""" PYTHON SCRIPT TO RECREATE FIGURE 3 OF THE COHEN PAPER """
""" DOI: https://doi.org/10.1063/1.865673 """

""" Author: S Sharpe  """ 
""" Date: October 20th 2026 """


#IMPORT FLORA 
from flora import *

#IMPORT CUSTOM MODULES 
import PlottingFunctions as Plotting
import CalculateFunctions as CF
import GrowthPredictions as GP

#IMPORT GENERAL PYTHON LIBS 
import matplotlib.pyplot as plt
import numpy as np
from pathlib import Path

#  LOAD INPUT FILES 
import jpostvbb
import in_Cohen 


# ====================================================================
# START OF MAIN CODE 
# ====================================================================

#read basitervbb.glr.b [NO LONGER USED]
#kept as in original example 
glr.dowriteb=True

# ====================================================================
# GENERATE THE EQUILIBRIUM
#
# Call the glrgen() routine to set up the initial equilibrium in 
# FLORA from the input deck and apply the initial pertubation 
#
# ====================================================================

print("\n=== GENERATING EQUILIBRIUM  ===")

#Generate initial equilibrium 
glr.glrgen()

z = np.asarray(glr.z)

# ====================================================================
# Run timestepping to study the growth rate over time 
# These growth rates are used as the 'FLORA' result for figures 2 & 3 
# ====================================================================

print("\n=== ADVANCING PERTUBATION WITH TIME ===")

#Set up lists to store the time,local amplitude and global amplitude 
times = []
amplitude_global = []



# loop, iterate through to glr.nmax -1 (account for different start ordering in python vs fortran) 
for i in range(glr.nmax-1):

    #call python exposed glrexe routine I set up to run at timestep i 
    glr.glrexepy()

    n = int(glr.n)

    # Current simulation time
    t = float(glr.time[n - 1])    

    # Calculate global amplitude
    A_global = np.sqrt(
        np.sum(np.asarray(glr.xro)**2) +
        np.sum(np.asarray(glr.xio)**2)
    )

    times.append(t)
    amplitude_global.append(A_global)
    
                  
times = np.asarray(times)


modeNum = int(glr.mm)

print("\n===  PERTUBATION WITH TIME COMPLETE ===")

# ================================================================================================== 
# FIGURE 3a: Growth rate as a function of m 
#
# This compares the actual growth rate and the predicted for the non-zero rotation case 
# (see eq 55 of Cohen paper) 
#
# The WKBJ theory and the approximation with significant curvature contribution (eq 58) have 
# also been added to better understand the calculated growth rate 

# Need to vary m in the input deck and rerun full script , this will populate a csv file
# with the values of m that have been tested.
# NOTE: Keep S=1 for this for correct rotational frequency
# ==================================================================================================  

#Only recreating fig 3a if the correct rotational profile is used 
#Add if condition for this   
 
if float(glr.phicen) != 0.0 and float(glr.phiplg) == 0.0:

    print("\n=== CALCULATING GROWTH RATES FOR M = ", glr.mm, " ===")  

    # eq 55 (Cohen paper) is the eikonal growth rate , without curvature drive   
    # This gives the growth rate solely due to the shear instability (non-zero rotation) 
    # This has a linear relationship with m, likely how the dashed line in Figure 3a was determined              
    eq55 = GP.eikonal_growth_rate(glr, mode_number=modeNum, include_curvature=False)

    # eq 58 gives the predicted growth rate with both rotation and curvature contributions 
    # For bad curvature, this will differ significantly from eq 55 
    # For weak curvature instability, this will approximate 55 
    eq58 = GP.eikonal_growth_rate(
        glr, mode_number=modeNum, include_curvature=True
    )

    # Predicted growth rate from WKBJ theory 
    # Takes the maximum of this to be the wkb prediction at this mode number 
    wkb = np.asarray(glr.gamwkb).squeeze() # WKB approximation for growth rates

    # FLORA growth rate calculation using the global amplitude 
    # Also makes plots showing the global amplitude and growth rate over time - optional
    #Calculate the growth rate
    growthDict = CF.calculate_growth_rate(
        times,
        amplitude_global
        ) 
        
    #Make plots of amplitude and growth rate over time
    #Comment out if not wanted  
    Plotting.plot_growth(growthDict) 


    print("\n=== FINAL GROWTH RATES ", glr.mm, " ===") 
    print("")
       
    print(" Only shear (no curvature drive) approximation: ",eq55['gamma'])
    print(" Shear and curvature approximation: ", eq58['gamma'])
    print(" WKBJ theory: ", max(wkb))
    print(" FLORA time pertubation: ", growthDict['gamma']  )
    
 
    #Make csv to store values if it does not exist 
    file3a_path = "outputs/Fig3a.csv"

    path = Path(file3a_path)

    if not path.exists():
        with path.open("w") as file_3a:
            print("M,Shear_only_approx,Shear_and_curvature_approx,WKB_approx,FLORA", file=file_3a)
        file_3a.close()
    
    #Print values to  file     
    with open(file3a_path, "a") as file_3a:
        print(glr.mm,eq55['gamma'],eq58['gamma'],max(wkb),growthDict['gamma'], sep=",", file=file_3a)
        
    file_3a.close()
    
    #Make final plot? - only have uncommented after csv has been populated 
    Plotting.plot_figure3a()


# ================================================================================================== 
# FIGURE 3b: Growth rate as a rotational shear 
#
# This compares the actual growth rate and the predicted for different values of rotational shear 
# For non-zero shear, prediction comes from eq 55 
# For zero shear, prediction comes from eq 63 instead 
# 
# Need to vary S in the input deck and rerun full script, this will populate a csv file with the values of 
# S that have been tested (Cohen uses 0.0, 0.5 and 1.0)
# NOTE: Keep m=50 for consistency with the Cohen paper 
# ==================================================================================================  

#Only recreating fig 3b if the correct mode number (50) is used 
#Add if condition for this   
 
if int(glr.mm) ==50 : 

    wkb = np.asarray(glr.gamwkb).squeeze()
    #ratio between plug and central cell 
    
    epsi = np.asarray(glr.epsi)
    omega = -glr.cee * epsi
    
    # Central cell: near z = 0
    i_central = 1

    # Plug value 
    # z1c is the anchor point
    z_plug = (glr.z1c)
    #Calculate the index corresponding to this z 
    # Add a couple on to make sure the rotation has decayed into the step function 
    i_plug = np.argmin(np.abs(z - z_plug)) +1 

    omega_central = omega[i_central, 0]
    omega_plug = omega[i_plug, 0]
    
    print("Omegas:", omega_plug, omega_central)
    
    theory3b = GP.figure3b_theory(
    glr,
    omega_c=omega_central,
    omega_p = omega_plug,
    mode_number=50,
    z_split=None,
    )
    
    S =  round(1.0 - (omega_plug / omega_central), 1)
    
    print("\n=== EXTRACTING GROWTH RATE FOR S=",S,"  ===")
    print("") 
    print("\n=== (where S = 1 - Omega_a / Omega_c)  ===")
    print("") 

    growthDict = CF.calculate_growth_rate(
        times,
        amplitude_global
        ) 

    #Make plots of amplitude and growth rate over time
    #Comment out if not wanted  
    Plotting.plot_growth(growthDict)    
    
    print("\n=== FINAL GROWTH RATES  ===") 
     
    print("")   
    print("Theory value: ", theory3b['gamma'])
    print(" WKBJ theory: ", max(wkb))
    print("FLORA time pertubation: ", growthDict['gamma'])

    
    #Make csv to store values if it does not exist 
    file3b_path = "outputs/Fig3b.csv"

    path = Path(file3b_path)

    if not path.exists():
        with path.open("w") as file_3b:
            print("S,Theory,WKB_approx,FLORA", file=file_3b)
        file_3b.close()
    
    #Print values to  file     
    with open(file3b_path, "a") as file_3b:
        print(S,theory3b['gamma'],max(wkb),growthDict['gamma'], sep=",", file=file_3b)
        
    file_3b.close()
    
    #Make final plot? - only have uncommented after csv has been populated
    Plotting.plot_figure3b()

