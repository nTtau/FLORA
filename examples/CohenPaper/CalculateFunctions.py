""" PYTHON FUNCTIONS TO CALCULATE USEFUL QUANTITIES FROM FLORA OUTPUTS """

""" Author: S Sharpe """ 
""" Date: October 20th 2026 """


import numpy as np

# ======================================================================================
# Calculate B (Tesla) as a function of z from the glr output
# ======================================================================================

def calcBTesla(glr):

    """    
    Function to calculate the on axis magnetic field in Tesla 

    Inputs:
    	glr : FLORA input/output array where all quantities 
              are stored.
    
    Outputs:
        B_tesla : array of magnetic field points in Tesla 
        z: array of z points 
        iplugmid: index corresponding to the plug midplane 
                  (used for comparing to caption of 
                   Cohen paper, Fig 1) 
        
    Note: Dimensions of B and Z must match 
    """

    if hasattr(glr, "bvac") and hasattr(glr, "z"):

        bvac = np.asarray(glr.bvac)
        z = np.asarray(glr.z)

        # Convert FLORA internal B back to Gauss
        B_tesla = bvac * np.sqrt(4.0 * np.pi) / 10000.0
            
        # ============================================================
        # FIND FLORA MIRROR PEAKS AND PLUG MIDPLANE
        # ============================================================

        ibvmax = np.asarray(glr.ibvmax).astype(int)

        # FLORA uses Fortran (1-based) indexing
        i1 = ibvmax[0] - 1
        i2 = ibvmax[1] - 1

        # Make sure the two peaks are ordered in z
        if i1 > i2:
            i1, i2 = i2, i1        
        
        # FLORA plug-midplane index
        iplugmid = (i1 + 1 + i2) // 2

        print(f"Mirror 1: z = {z[i1]:.3f} cm, B = {B_tesla[i1]:.5f} T")
        print(f"Plug midplane: z = {z[iplugmid]:.3f} cm, "
              f"B = {B_tesla[iplugmid]:.5f} T")
        print(f"Mirror 2: z = {z[i2]:.3f} cm, B = {B_tesla[i2]:.5f} T")              
            
        return(B_tesla,z,iplugmid)


# ======================================================================================
# Radial displacement calculation at current time, given axial index 
# ======================================================================================

def calculate_radial_displacement_at_z(glr, iz):
    """
    Reproduce the xrsppsi radial profile from FLORA diagno.F
    at a given axial grid index.
    Current work around for issues with xrsppsi not recording 
    at all times properly.
    
    Used for producing similar plot to Figure 2b of Cohen paper 

    Parameters
    ----------
    glr
        FLORA glr module.

    iz : int
        Python (0-based) axial index.

    Returns
    -------
    xi : ndarray, shape (jx,)
        xro radial displacement profile at the requested z index.
        Boundary points are zero, matching original diagno.F.
    """

    ix = int(glr.ix)
    jx = int(glr.jx)
    isw = int(glr.isw)

    xro = np.asarray(glr.xro, dtype=float)

    # diagno.F uses Fortran axial index ixpl
    # Python index iz -> Fortran index iz + 1
    ixpl = iz + 1

    xi = np.zeros(jx, dtype=float)

    for j_python in range(1, jx - 1):

        j_fortran = j_python + 1

        # Exact diagno.F expressions
        kp1 = (
            ixpl - 1
            + (j_fortran - 2) * (ix - 2)
        )

        kp2 = (
            j_fortran - 1
            + (jx - 2) * (ixpl - 2)
        )

        if isw == 1:
            kpp = kp1
        else:
            kpp = kp2

        # kpp is a Fortran 1-based xro index
        xi[j_python] = xro[kpp - 1]

    return (xi)

# ======================================================================================
# Final growth rate calculation by comparing current growth rate to previous time step 
# ======================================================================================

def calculate_growth_rate(
    times,
    amplitude,
    gamma_tol=0.05,
    min_region_fraction=0.1
):
    """
    Function to automatically determine the sustained exponential-growth
    region and calculate the fitted growth rate.


    Uses the following eqs: 
    
        A(t) = A0 * exp(gamma*t)
        ln(A) = gamma*t + constant
        
    where gamma is the growth rate.
    
    The function compares the current growth rate to the previous and sees if it lies 
    within the tolerance level given with a fractional tolerance used to account for large growth rates
    
    If min_region_fraction * total num timesteps consecutively lie within this tolerance
    we consider the sustained exponential growth region to be found and the final growth 
    rate calculated. 
    
    If not the code will still calculate the growth rate but will return a warning 
    

    Parameters
    ----------
    times : array-like
        Simulation times.
    amplitude : array-like
        Perturbation amplitude.
    gamma_tolerance : float
        Maximum allowed relative variation in gamma from previous step 
        0.05 corresponds to 5%.
    min_region_fraction : float
        Fraction of the total points that must have constant gamma consecutively before constant gamma decided 
        0.1 = 10% of the total points must consecutively lie within the tolerance level for convergence 

    Returns
    -------
    result : dict
    	Contains all the values needed to plot the growth rate and amplitude over time 
    	(see PlottingFunctions.py's plot_growth() function)
    	Also indicates at which time the constant growth rate region begins 

    """

    print("STARTING CALC")
    times = np.asarray(times, dtype=float)
    amplitude = np.asarray(amplitude, dtype=float)

    # --------------------------------------------------------
    # Clean data if needed 
    # --------------------------------------------------------

    mask = (
        np.isfinite(times) &
        np.isfinite(amplitude) &
        (amplitude > 0)
    )

    t = times[mask]
    A = amplitude[mask]
    
    print("valid points:", len(A))

    print("number of points:",len(t),len(times))
    if len(t) < 20:
        
        raise RuntimeError(
            "Not enough valid amplitude points to calculate "
            "a growth rate."
        )
  
    lnA = np.log(A)
    gammas = np.gradient(lnA,t)

    
    gammaFound = False
   
    # ---------------------------------------------------------
    # Find first region where gamma stays approximately constant
    # Compare with previous values and ensure the result is within the tolerance window   
    # ---------------------------------------------------------

    start = None
    count = 0
    #Set number of points that must remain constant before growth rate has been calculated 
    pointsToConstant = int(min_region_fraction*len(gammas))
    
    print("points needed to convergence: ", pointsToConstant)

    for i in range(len(gammas) - 1):  

        gamma_current = gammas[i]
        gamma_next = gammas[i + 1] 
        
        diff = gamma_next -gamma_current
        
        #Check to prevent divide by zero issues 
        if gamma_current ==0: 
        
            gamma_current = 1e-12 
            print("gamma reset as small")
                     
        if abs((gamma_next -gamma_current)/(gamma_current)) <= gamma_tol or gamma_current ==1e-12:
                  
            #set index of the start point for constant growth rate            
            if start == None:
                start = i 
                #print("NEW START:", i)
            
            #Update the count 
            count = count+1 
            
            if count == pointsToConstant:
            
                endp = i 
                print("breaking i =",i)
                break
        
        #gamma is not constant between steps, reset counters     
        else: 
        
            start=None 
            count =0 
            endp = None
           # print(i,"not within tolerance")
            #print("Percentage change:",(abs((gamma_next -gamma_current)/(gamma_current)))) 
            
        
    if count != pointsToConstant:
        
        print("count = ",count) 
        print("Not enough constant values of gamma reached to confirm final value") 
        print("Make a plot of the amplitude over time to check it the growth rate has converged ")   

    # ---------------------------------------------------------
    # Final growth-rate calculation
    # ---------------------------------------------------------
    
    print("start of constant gamma:", start)    
    print("gamma loop exited at i =",endp)
    end = len(gammas) -1 
    t_region = t[start:end]
    lnA_region = lnA[start:end]

    gamma, intercept = np.polyfit(
        t_region,
        lnA_region,
        1
    )

    # R² of final fit
    lnA_fit = gamma * t_region + intercept

    ss_res = np.sum((lnA_region - lnA_fit) ** 2)
    ss_tot = np.sum((lnA_region - np.mean(lnA_region)) ** 2)

    if ss_tot > 0:
        r_squared = 1 - ss_res / ss_tot
    else:
        r_squared = 1.0
         
    A0 = np.exp(intercept)
     
    print("The constant gamma region starts at t = ", t[start])
    print(f"The equation for the time dependent pertubation is:  ") 
    print(
    f"Perturbation equation: A(t) = "
    f"{A0:.3E} * exp(({gamma:.3E}) * t)"
    )
    print(f"This gives a growth rate of:  {gamma:.3E} s^-1") 
    
    if (gamma > 1e-3): 
        print("Positive growth rate  => unstable") 
        
    elif (gamma < -1e-3): 
        print("Negative growth rate  => stable")
        
    else: 
        print("Growth rate approximately 0 => marginally stable")   
      
    
    return {
        "times": t,
        "amplitude": A,
        "ln_amplitude": lnA,
        "gamma_local": gammas,
        "region_start": start,
        "region_end": end,
        "t_region": t_region,
        "gamma": gamma,
        "intercept":intercept,
        "r_squared": r_squared,
        "t_start": t[start],
        "t_end": t[end]
    }
   

