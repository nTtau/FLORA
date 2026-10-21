""" PYTHON FUNCTIONS TO PLOT FLORA OUTPUTS """

""" Author: S Sharpe  """ 
""" Date: October 20th 2026 """


import matplotlib.pyplot as plt
from matplotlib.ticker import ScalarFormatter
import numpy as np
import CalculateFunctions as CF
       
def plotBField(B_tesla,z,iplugmid):

    """    
    Function to plot the magnetic field as a function of z (r=0)
    Highlights the values given in the caption of Fig1  of the 
    Cohen paper for direct comparison  

    Inputs:
        B_tesla : array of magnetic field points in Tesla 
        z: array of z points 
        iplugmid: index corresponding to the plug midplane 
        
    Note: Dimensions of B and Z must match 
    """

    fig=plt.figure(figsize=(10, 6))


    # Cohen Figure 1 target fields
    plt.plot(z, B_tesla, color='black', label='FLORA B(z)')

    plt.axhline(0.10, color='blue', linestyle='--',
                label='Central cell: 0.10 T')

    plt.axhline(0.33, color='green', linestyle='--',
                label='Plug midplane: 0.33 T')

    plt.axhline(1.00, color='red', linestyle='--',
                label='Mirror peaks: 1.00 T')

    plt.xlabel("z (cm)")
    plt.ylabel("Magnetic field B (T)")
    plt.title("FLORA Vacuum Magnetic Field")
    plt.grid(True)
    plt.legend()

    plt.scatter(
        z[iplugmid],
        B_tesla[iplugmid],
        s=80,
        zorder=5,
        color='green',
        label=f"FLORA plug midplane = {B_tesla[iplugmid]:.3f} T"
    )

    plt.tight_layout()
    plt.show() 
    fig.savefig('outputs/B_z0.png')
    
    return() 
    
def plotBOnly(B_tesla,z):

    """    
    Function to plot the magnetic field as a function of z (r=0) 
     

    Inputs:
        B : array of magnetic field points (in Tesla) 
        z: array of z points 
        
    Note: Array B and z must match in size . 
    """

    fig=plt.figure(figsize=(10, 6))


    # Cohen Figure 1 target fields
    plt.plot(z, B_tesla, color='black', label='FLORA B(z)')


    plt.xlabel("z (cm)")
    plt.ylabel("Magnetic field B (T)")
    plt.title("FLORA Vacuum Magnetic Field")
    plt.grid(True)
    plt.legend()

    plt.tight_layout()
    plt.show()
    fig.savefig('outputs/B_z0.png') 
    
    return()     
    
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.collections import PolyCollection
from matplotlib.lines import Line2D          

def plotProfiles(FieldName,P,r,z):

    """    
    Function to plot the r,z profile of any field of form P[axial,radial]
    Used to generate Figure 1 for Cohen paper recreation 

    Inputs:
        FieldName : str type, sets what to call the y axis 
        P : The array containing the field info to plot 
        r : array of r points 
        z: array of z points 
        
    Note: Dimensions of P must match with r and z such that 
          P is of the form P[z,r] - default flora output when
          grabbing from glr. 
    """
# -------------------------------------------------------
# Make sure P is of form [radial, axial]
# -------------------------------------------------------

    if P.shape[1] == len(z):
    # already [radial, z]
        Pplot = P

        if r.ndim == 2:
            R = r
        else:
            R = np.tile(r[:, None], (1, len(z)))

    elif P.shape[0] == len(z):
    # transpose to [radial, z]
        Pplot = P.T

        if r.ndim == 2:
            R = r.T
        else:
            R = np.tile(r[None, :], (len(z), 1)).T

    else:
        raise ValueError(
            f"Cannot match pperp shape {P.shape} "
            f"to z length {len(z)}"
        )

    # axial coordinate
    Z = np.tile(z[None, :], (Pplot.shape[0], 1))


    Z = np.tile(z, (r.shape[1], 1))
    R = r.T
    Pplot = P.T


    nphi, nz = Pplot.shape

    phi = np.linspace(0.0, 1.0, nphi)

    PHI = np.broadcast_to(
        phi[:, None],
        Pplot.shape
    )

    zmin = np.nanmin(Z)
    zmax = np.nanmax(Z)

    pmin = np.nanmin(Pplot)
    pmax = np.nanmax(Pplot)

    zrange = zmax - zmin
    prange = pmax - pmin


# Amount that phi moves the surface:
    phi_dx = 0.30 * zrange
    phi_dy = 0.18 * prange

    X = Z + PHI * phi_dx
    Y = Pplot + PHI * phi_dy

    fig, ax = plt.subplots(
        figsize=(10, 7)
    )

    verts = []

    for i in range(nphi - 1):

        for j in range(nz - 1):

            verts.append([
                (X[i,     j],     Y[i,     j]),
                (X[i,     j + 1], Y[i,     j + 1]),
                (X[i + 1, j + 1], Y[i + 1, j + 1]),
                (X[i + 1, j],     Y[i + 1, j])
            ])


    surface = PolyCollection(
        verts,
        facecolors='0.65',
        edgecolors='none',
        alpha=1.0,
        zorder=1
    )

    ax.add_collection(surface)

    i_front = 0
    p0 = 0.0

    front_vertices = []


    for j in range(nz):

        front_vertices.append(
            (
                X[i_front, j],
                Y[i_front, j]
            )
        )

    for j in range(nz - 1, -1, -1):

        front_vertices.append(
            (
                X[i_front, j],
                p0
            )
        )

    front_face = PolyCollection(
        [front_vertices],
        facecolors='white',
        edgecolors='black',
        linewidths=1.8,
        linestyle='-',
        zorder=10
    )

    ax.add_collection(front_face)

    Pbox = np.nanmax(Pplot)

# Bottom corners
    A = (
        X[0, 0],
        p0
    )

    B = (
        X[0, -1],
        p0
    )

    C = (
        X[-1, 0],
        p0 + phi_dy
    )

    D = (
        X[-1, -1],
        p0 + phi_dy
    )

# Top corners
    A_top = (
        A[0],
        Pbox
    )

    B_top = (
        B[0],
        Pbox
    )

    C_top = (
        C[0],
        Pbox + phi_dy
    )

    D_top = (
        D[0],
        Pbox + phi_dy
    )


    box_lines = [

    # Front vertical axis
        (A, A_top),

    # Front bottom
        (A, B),

    # Front top
        (A_top, B_top),

    # Right side
        (B, D),

    # Right vertical
        (B, B_top),

    # Back bottom
        (C, D),

    # Back vertical
        (C, C_top),

    # Back top
        (C_top, D_top),

    # Left phi direction
        (A, C),

    # Left top phi direction
        (A_top, C_top),

    # Right top phi direction
        (B_top, D_top),
    ]
    
    for p1, p2 in box_lines:

        ax.add_line(
            Line2D(
                [p1[0], p2[0]],
                [p1[1], p2[1]],
                color='black',
                linewidth=1.0,
                zorder=20
            )
        )

    zticks = np.linspace(
        zmin,
        zmax,
        6
    )

    for zval in zticks:

        j = np.argmin(
            np.abs(z - zval)
        )

        xval = X[0, j]

        ax.plot(
            [xval, xval],
            [p0, p0 - 0.015 * prange],
            color='black',
            linewidth=1.0,
            zorder=25
        )

        ax.text(
            xval,
            p0 - 0.035 * prange,
            f'{z[j]:.0f}',
            ha='center',
            va='top',
            fontsize=11
        )

    pticks = np.linspace(
        0,
        Pbox,
        6
    )

    for pval in pticks:

        ax.plot(
            [A[0] - 0.012 * zrange,
             A[0]],
            [pval, pval],
            color='black',
            linewidth=1.0,
            zorder=25
        )

        ax.text(
            A[0] - 0.025 * zrange,
            pval,
            f'{pval:.2g}',
            ha='right',
            va='center',
            fontsize=10
        )

    #set phiu axis to be on right side, match cohen paper 
    phi_ticks = np.linspace(
        0,
        1,
        6
    )

    for phival in phi_ticks:

    # Position along right-hand box edge
        x_tick = B[0] + phival * phi_dx
        y_tick = p0 + phival * phi_dy

    # Small tick pointing outward
        tick_length = 0.012 * zrange

        ax.plot(
            [
                x_tick,
                x_tick + tick_length
            ],
            [
                y_tick,
                y_tick
            ],
            color='black',
            linewidth=1.0,
            zorder=25
        )

        ax.text(
            x_tick + 0.025 * zrange,
            y_tick,
            f'{phival:.1f}',
            ha='left',
            va='center',
            fontsize=10
        )
        

    ax.text(
        (A[0] + B[0]) / 2,
        p0 - 0.10 * prange,
        r'$z$',
        ha='center',
        va='top',
        fontsize=16
    )

    ax.text(
        A[0] - 0.08 * zrange,
        Pbox / 2,
        FieldName,
        ha='center',
        va='center',
        fontsize=16,
        rotation=90
    )


    ax.text(
        D[0] + 0.10 * zrange,
        D[1] + 0.02 * prange,
        r'$\phi$',
        ha='left',
        va='bottom',
        fontsize=16
    )

    ax.set_xlim(
        zmin - 0.15 * zrange,
        zmax + phi_dx + 0.20 * zrange
    )

    ax.set_ylim(
        p0 - 0.15 * prange,
        Pbox + phi_dy + 0.15 * prange
    )

    ax.set_xticks([])
    ax.set_yticks([])

    for spine in ax.spines.values():
        spine.set_visible(False)

    ax.set_aspect('auto')

    plt.tight_layout()

    plt.show()
    
    fileOut = "outputs/" + str(FieldName) + ".png"
    
    fig.savefig(fileOut)

    return()
    
# ===============================================================================================
# COHEN FIGURE 2A, GROWTH RATE COMPARED TO FLUTE3 (OPTIONAL) AND WKB (OPTIONAL) APPROXIMATIONS
# =============================================================================================== 

def PlotCohen2a(glr,k_values,amplitudes,times,useWKB=True,useFlute3=True): 


    psi = np.asarray(glr.psi).squeeze() # mag flux surface

    gamma2_theory = np.asarray(glr.flute3).squeeze() # curvature only growth rate ^2 
    wkb = np.asarray(glr.gamwkb).squeeze() # WKB approximation for growth rates 
    

# Set up plot
    fig, ax = plt.subplots(figsize=(6, 4))

    ax.set_xlabel(r"Magnetic flux $\psi$")
    ax.set_ylabel(r"Growth rate squared, $\gamma^2$")
    ax.legend()
    ax.tick_params(direction="in")
    plt.tight_layout()
    
    if useFlute3==True:

        ax.plot(
            psi[1:-1],
            gamma2_theory[1:-1],
            "k-",
            label="FLORA flute3 growth rate"
        )
        
    if useWKB==True:
    
        ax.plot(
            psi[1:-1],
            wkb[1:-1]**2,
            "k-",
            label="wkb growth rate",
            color = "red"
        )

#Plot the flora growth rates at different flux surface
    for k in range (len(k_values)):

        growthDict = CF.calculate_growth_rate(
        times,
        amplitudes[k])
    
        FLORA_GR = growthDict["gamma"] 
    
        psi_kplot = psi[k_values[k]]

        plt.scatter(
            psi_kplot,
            FLORA_GR**2,
            s=80,
            zorder=5,
            color='green',
            label=f"FLORA growth rate"
        )

    plt.show()
    plt.close()
    fig.savefig("outputs/Fig2a.png")

    return()
    
    
# ================================================================
# GROWTH RATE PLOTTING 
# ================================================================    
      
def plot_growth(result):
    """
    Plot perturbation amplitude and local growth rate from a dictionary containing these .

    Parameters
    ----------
    result : dict
        Output from calculate_growth_rate() / calculate_growth_rate_bins in CalculateFunctions.
    """

    t = result["times"]
    A = result["amplitude"]
    gamma_local = result["gamma_local"]

    gamma = result["gamma"]
    intercept = result["intercept"]
    r2 = result["r_squared"]

    t_start = result["t_start"]
    t_end = result["t_end"]
    
    print("t_start:", result["t_start"])
    print("t_start type:", type(result["t_start"]))
    print("t_start shape:", np.shape(result["t_start"]))

    print("t_end:", result["t_end"])
    print("t_end type:", type(result["t_end"]))
    print("t_end shape:", np.shape(result["t_end"]))

    # ========================================================
    # Amplitude plot
    # ========================================================
    
    print("plotting amplitude", flush=True)

    print("len(t):", len(t), flush=True)
    print("len(A):", len(A), flush=True)

    print("creating figure...", flush=True)
    fig, ax = plt.subplots()
    print("figure created", flush=True)
    
    print("plotting data...", flush=True)
    ax.plot(t, A, label="Perturbation amplitude")
    print("data plotted", flush=True)

    plt.plot(
        t,
        A,
        label="Perturbation amplitude"
    )
    
    print("fitting equation")
    A0 = np.exp(intercept)

    
    A_fitted = A0 * np.exp(gamma * t)

    plt.plot(
        t,
        A_fitted,
        "--",
        label=f"Fit: A(t) = {A0:.3E} exp(({gamma:.3E})t)"
    )

    plt.axvspan(
        t_start,
        t_end,
        alpha=0.3,
        label="Detected constant gamma region"
    )

    plt.xlabel("Time [s]")
    plt.ylabel("Perturbation amplitude")

    plt.yscale("log")

    plt.grid(True)
    plt.legend()

    plt.show()
    fig.savefig("outputs/A_t.png")
    
    plt.close()
    
    print("amplitude plot done")

    # ========================================================
    # Growth-rate plot
    # ========================================================

    plt.figure()

    plt.plot(
        t,
        gamma_local,
        label="Local gamma(t)"
    )

    plt.axhline(
        gamma,
        linestyle="--",
        label=f"Fitted gamma = {gamma:.3e} s$^{{-1}}$"
    )

    plt.axvspan(
        t_start,
        t_end,
        alpha=0.3,
        label="Detected constant gamma region"
    )

    plt.xlabel("Time [s]")
    plt.ylabel(r"$\gamma(t)$ [s$^{-1}$]")

    plt.grid(True)
    plt.legend()

    plt.show()
    fig.savefig("outputs/GrowthRate.png")
    
    return()
    
def plot_radial_displacement(
    glr,
    xi_history,
    times,
    z_target,
    timesteps,
    normalize=False
):
    """
    Plot radial displacement versus normalized flux at selected timesteps.

    Parameters
    ----------
    glr : FLORA glr object
        Used to obtain the radial psi grid.

    xi_history : dict
        Dictionary containing displacement histories:
            xi_history[z_target].shape = (n_times, jx)

    times : ndarray
        Physical time corresponding to each saved timestep.

    z_target : float
        Axial position to plot, e.g. 50.0 cm.

    timesteps : list of int
        Saved timestep indices to plot, e.g.
            [100, 500, 1000, 2000]

    normalize : bool, optional
        If True, normalize each radial profile by its maximum
        absolute value. Default False.
    """

    psi = np.asarray(glr.psi, dtype=float)
    psi_norm = psi / psi[-1]

    xi_all = np.asarray(xi_history[z_target])

    fig=plt.figure(figsize=(7, 5))

    for step in timesteps:

        if step < 0 or step >= len(times):
            print(
                f"Skipping timestep {step}: "
                f"valid range is 0 to {len(times)-1}"
            )
            continue

        xi = xi_all[step, :].copy()

        if normalize:
            xi_max = np.max(np.abs(xi))
            if xi_max > 0:
                xi /= xi_max

        plt.plot(
            psi_norm,
            xi,
            label=(
                f"n = {step}, "
                f"t = {times[step]:.3e} s"
            )
        )

    plt.xlabel(r"$\psi/\psi_w$")
    plt.ylabel(r"$\xi$")
    plt.title(
        rf"Radial displacement at $z={z_target:g}$ cm"
    )

    plt.axhline(0.0, color="k", linewidth=0.7)
    plt.legend()
    plt.grid(alpha=0.25)
    plt.tight_layout()
    plt.show()
    fileOut = "outputs/RadDis_at_z" + str(z_target) +".png"
    
    fig.savefig(fileOut) 
       
    return ()
    
def plot_figure3a(
    file_name="outputs/Fig3a.csv",
    file_out="outputs/Figure3a.png"
    ):
    
    """
    Plot growth rate versus azimuthal mode number m for Figure 3a.

    Results shown:
        - Shear-only approximation: dashed line
        - Shear + curvature approximation
        - WKB approximation
        - FLORA time-dependent perturbation

    Parameters
    ----------
    file_name : str
        Path to Fig3a.csv.

    file_out : str
        Path used to save the resulting figure.
    """

    
    # Read CSV with the four columns shown above
    data = np.genfromtxt(
        file_name,
        delimiter=",",
        names=True,
        encoding="utf-8",
    )

    data = np.atleast_1d(data)
    data = data[np.argsort(data["M"])]

    m = data["M"]
    wkb = data["WKB_approx"]
    shear = data["Shear_only_approx"]
    shearCurv = data["Shear_and_curvature_approx"]
    actual = data["FLORA"]

    fig, ax = plt.subplots(figsize=(7.5, 5.8))
    ax.set_box_aspect(2 / 3)

    ax.plot(
        m, wkb,
        color="black", linestyle="-", linewidth=2,
        label="WKB prediction",
    )

    ax.plot(
        m, shear,
        color="black", linestyle="--", linewidth=2.5,
        label="Shear-only prediction",
    )
    
    ax.plot(
        m, shearCurv,
        color="black", linestyle="-.", linewidth=2.5,
        label="Shear and curvature prediction",
    )

    ax.plot(
        m, actual,
        linestyle="none", marker="o", markersize=9,
        markerfacecolor="none", markeredgecolor="black",
        markeredgewidth=1.5,
        clip_on=False, zorder=4,
        label="FLORA",
    )

    # Reference axis limits and ticks
    ax.set_xlim(0, 60)
    ax.set_ylim(0, 10000)
    ax.set_xticks([0, 10, 20, 30, 40, 50])
    ax.set_yticks([0, 5000, 10000])

    formatter = ScalarFormatter(useMathText=True)
    formatter.set_scientific(True)
    formatter.set_powerlimits((4, 4))
    ax.yaxis.set_major_formatter(formatter)
    ax.yaxis.get_offset_text().set_fontsize(14)

    ax.set_xlabel("m", fontsize=16, labelpad=10)
    ax.set_ylabel(
        r"Growth rate $\gamma$ ($\mathrm{s}^{-1}$)",
        fontsize=16, labelpad=12,
    )

    ax.spines["top"].set_visible(False)
    ax.spines["right"].set_visible(False)
    for side in ["left", "bottom"]:
       ax.spines[side].set_linewidth(1.8)

    ax.tick_params(
        axis="both", direction="in",
        length=12, width=1.8, labelsize=14,
    )
    ax.grid(False)

    # Use this annotation only for the Omega_a = 0 case
    ax.text(
        0.66, 0.13, r"$\Omega_a = 0$",
        transform=ax.transAxes, fontsize=16,
    )

    ax.legend(frameon=False, loc="upper left", fontsize=12)

    fig.tight_layout()

    plt.show()
    fig.savefig(file_out)

    return ()    
    
    
def plot_figure3b(
    file_name="outputs/Fig3b.csv",
    file_out="outputs/Figure3b.png"
    ):    
    
    """
    Plots growth rate for different rotational shears

    Results shown:
        - Theoretical growth rate 
        - FLORA time-dependent perturbation

    Parameters
    ----------
    file_name : str
        Path to Fig3a.csv.

    file_out : str
        Path used to save the resulting figure.
    """
    
    # Read CSV with the four columns shown above
    data = np.genfromtxt(
        file_name,
        delimiter=",",
        names=True,
        encoding="utf-8",
    )

    data = np.atleast_1d(data)
    data = data[np.argsort(data["S"])]

    S = data["S"]
    WKB_gamma_predict = data["WKB_approx"]
    theory = data["Theory"]
    gamma_actual = data["FLORA"]
    

    fig, ax = plt.subplots(figsize=(6.5, 5.5))
    ax.set_box_aspect(0.8)

    ax.plot(S, gamma_actual, "o", markersize=9,
        markerfacecolor="none", markeredgecolor="black",
        label="FLORA", clip_on=False, zorder=3)

    ax.plot(S, theory, "^", markersize=9,
        markerfacecolor="none", markeredgecolor="black",
        label="Theory", clip_on=False, zorder=3)

    ax.plot(S, WKB_gamma_predict, "s", markersize=7,
        markerfacecolor="none", markeredgecolor="tab:blue",
        label="WKB prediction", clip_on=False, zorder=3)

    ax.set_xlim(0, 1.25)
    ax.set_ylim(0, 10000)
    ax.set_xticks([0, 0.5, 1.0])
    ax.set_xticklabels(["0", "0.5", "1.0"])
    ax.set_yticks([0, 5000, 10000])

    formatter = ScalarFormatter(useMathText=True)
    formatter.set_scientific(True)
    formatter.set_powerlimits((4, 4))
    ax.yaxis.set_major_formatter(formatter)

    ax.set_xlabel(r"$1-\Omega_a/\Omega_c$", fontsize=16, labelpad=12)
    ax.set_ylabel(r"Growth rate $\gamma$ ($\mathrm{s}^{-1}$)",
              fontsize=16, labelpad=12)

    ax.spines["top"].set_visible(False)
    ax.spines["right"].set_visible(False)
    for spine in ["left", "bottom"]:
        ax.spines[spine].set_linewidth(1.5)

    ax.tick_params(direction="in", length=10, width=1.5, labelsize=13)
    ax.text(0.05, 0.93, r"$m=50$", transform=ax.transAxes, fontsize=15)
    ax.legend(frameon=False, loc="lower right", fontsize=12)

    fig.tight_layout()
    plt.show()
    fig.savefig(file_out)
    
    return()
