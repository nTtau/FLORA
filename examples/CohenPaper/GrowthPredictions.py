""" PYTHON FUNCTIONS TO CALCULATE THE THEORETICAL GROWTH RATES """

""" Author: S Sharpe  """ 
""" Date: October 20th 2026 """

""" Note: Any references to equation numbers come from the Cohen paper """
""" DOI: https://doi.org/10.1063/1.865673 """


import numpy as np
from flora import *
from flora.flora_graphics import plots1
import matplotlib.pyplot as plt

def shear_only_growth_rate(glr, mode_number=None):
    """
    Calculate the weak-FLR, high-m shear-only growth rate.

    Uses potential-derived rotation: Omega = -cee * epsi.
    Excludes curvature, radial centrifugal drive and FLR terms.

    mode_number defaults to glr.mm.
    Returns the maximum rate and predictions on each flux surface.
    """
    m = float(glr.mm if mode_number is None else mode_number)

    z = np.asarray(glr.z, dtype=float).reshape(-1)
    rho = np.asarray(glr.rho, dtype=float)
    B = np.asarray(glr.b, dtype=float)
    omega = -float(glr.cee) * np.asarray(glr.epsi, dtype=float)

    if (
        rho.ndim != 2
        or rho.shape[0] != z.size
        or not (rho.shape == B.shape == omega.shape)
    ):
        raise ValueError(
            "rho, B and epsi must have shape (len(z), n_surfaces)."
        )

    if not np.isfinite(m):
        raise ValueError("mode_number must be finite.")

    # Clean all axial arrays together.
    valid = (
        np.isfinite(z)
        & np.all(np.isfinite(rho) & (rho >= 0), axis=1)
        & np.all(np.isfinite(B) & (B > 0), axis=1)
        & np.all(np.isfinite(omega), axis=1)
    )
    z, rho, B, omega = (
        z[valid], rho[valid], B[valid], omega[valid]
    )

    order = np.argsort(z, kind="stable")
    z, rho, B, omega = (
        z[order], rho[order], B[order], omega[order]
    )

    z, keep = np.unique(z, return_index=True)
    rho, B, omega = rho[keep], B[keep], omega[keep]

    if z.size < 2:
        raise ValueError("Fewer than two valid axial points.")

    trap = getattr(np, "trapezoid", None)
    if trap is None:
        trap = np.trapz

    weight = rho / B**2
    W = trap(weight, x=z, axis=0)

    mean_omega = np.divide(
        trap(weight * omega, x=z, axis=0),
        W,
        out=np.full_like(W, np.nan),
        where=W > 0,
    )

    variance = np.divide(
        trap(
            weight * (omega - mean_omega[None, :])**2,
            x=z,
            axis=0,
        ),
        W,
        out=np.full_like(W, np.nan),
        where=W > 0,
    )

    gamma = abs(m) * np.sqrt(np.maximum(variance, 0.0))

    # Exclude radial boundary/ghost surfaces.
    surfaces = np.arange(1, gamma.size - 1)
    surfaces = surfaces[np.isfinite(gamma[surfaces])]

    if surfaces.size == 0:
        raise ValueError("No valid interior flux surfaces.")

    j_fast = int(surfaces[np.argmax(gamma[surfaces])])

    return {
        "mode_number": m,
        "gamma": float(gamma[j_fast]),
        "fastest_surface": j_fast,
        "gamma_by_surface": gamma,
        "mean_omega_by_surface": mean_omega,
        "rotation_variance_by_surface": variance,
    }
    

def check_rotation_only_coefficients(glr, surfaces=(16, 48), mode_number=None):
    import numpy as np

    m = float(glr.mm if mode_number is None else mode_number)

    z = np.asarray(glr.z, dtype=float).reshape(-1)
    rho = np.asarray(glr.rho, dtype=float)
    B = np.asarray(glr.b, dtype=float)
    r = np.asarray(glr.r, dtype=float)
    omega = -float(glr.cee) * np.asarray(glr.epsi, dtype=float)

    xxx = np.asarray(glr.xxx, dtype=float)
    yyy = np.asarray(glr.yyy, dtype=float)
    hflr = np.asarray(glr.hflr, dtype=float).reshape(-1)

    if not (
        rho.shape == B.shape == r.shape
        == omega.shape == xxx.shape == yyy.shape
    ):
        raise ValueError("All spatial arrays must have matching shapes.")

    if rho.shape != (z.size, hflr.size):
        raise ValueError("Spatial arrays must have shape (len(z), len(hflr)).")

    e_native = np.asarray(glr.rhoave, dtype=float).reshape(-1)
    f_native = np.asarray(glr.xxxave, dtype=float).reshape(-1)
    g_native = np.asarray(glr.yyyave, dtype=float).reshape(-1)

    trap = getattr(np, "trapezoid", None)
    if trap is None:
        trap = np.trapz

    results = {}

    for j in surfaces:
        # r=0 and B=0 cannot be included in the native-weight reconstruction.
        valid = (
            np.isfinite(z)
            & np.isfinite(rho[:, j]) & (rho[:, j] >= 0)
            & np.isfinite(B[:, j]) & (B[:, j] > 0)
            & np.isfinite(r[:, j]) & (r[:, j] > 0)
            & np.isfinite(omega[:, j])
            & np.isfinite(xxx[:, j])
            & np.isfinite(yyy[:, j])
        )

        zz = z[valid]
        rrho = rho[valid, j]
        bb = B[valid, j]
        radius = r[valid, j]
        om = omega[valid, j]
        xx = xxx[valid, j]
        yy = yyy[valid, j]

        order = np.argsort(zz, kind="stable")
        zz, rrho, bb, radius, om, xx, yy = (
            a[order] for a in (zz, rrho, bb, radius, om, xx, yy)
        )

        zz, keep = np.unique(zz, return_index=True)
        rrho, bb, radius, om, xx, yy = (
            a[keep] for a in (rrho, bb, radius, om, xx, yy)
        )

        if zz.size < 2:
            raise ValueError(f"Not enough valid points on surface {j}.")

        def integral(a):
            return trap(a, x=zz)

        def variance_growth(weight):
            W = integral(weight)
            if W <= 0:
                return np.nan
            mean = integral(weight * om) / W
            variance = integral(weight * (om - mean)**2) / W
            return abs(m) * np.sqrt(max(variance, 0.0))

        # Paper's weak-FLR shear weighting.
        gamma_paper = variance_growth(rrho / bb)

        # Spatial factor appearing in FLORA's native axial integrands.
        factor = 1.0 / (radius**2 * bb**3)
        gamma_native_weight = variance_growth(rrho * factor)

        # Rotation-only reconstruction, retaining the generated hflr.
        xxx_rot = 2.0 * hflr[j] * rrho * om
        yyy_rot = -hflr[j] * rrho * om**2

        e_trap = integral(rrho * factor)
        f_rot = integral(xxx_rot * factor)
        g_rot = integral(yyy_rot * factor)

        f_actual = integral(xx * factor)
        g_actual = integral(yy * factor)

        def rotation_term(e, f, g):
            if not np.isfinite(e) or e <= 0:
                return np.nan
            return -0.25 * m**2 * ((f / e)**2 + 4.0 * g / e)

        rot_only_sq = rotation_term(e_trap, f_rot, g_rot)
        actual_trap_sq = rotation_term(e_trap, f_actual, g_actual)
        native_sq = rotation_term(
            e_native[j], f_native[j], g_native[j]
        )

        print(f"\n=== Surface {j}, m={m:g} ===")
        print(f"hflr = {hflr[j]:.12e}")
        print(f"Paper-weight shear gamma : {gamma_paper:.6f} s^-1")
        print(
            f"Native-weight shear gamma: "
            f"{gamma_native_weight:.6f} s^-1"
        )
        print("Signed rotation contributions [s^-2]:")
        print(f"  Rotation-only reconstruction : {rot_only_sq:+.12e}")
        print(f"  Actual xxx/yyy, trapezoid     : {actual_trap_sq:+.12e}")
        print(f"  FLORA stored averages        : {native_sq:+.12e}")

        print("Normalized coefficients:")
        print(
            f"  Rotation-only: f/e={f_rot/e_trap:+.12e}, "
            f"g/e={g_rot/e_trap:+.12e}"
        )
        print(
            f"  Actual trap:   f/e={f_actual/e_trap:+.12e}, "
            f"g/e={g_actual/e_trap:+.12e}"
        )
        if e_native[j] > 0:
            print(
                f"  FLORA stored:  f/e={f_native[j]/e_native[j]:+.12e}, "
                f"g/e={g_native[j]/e_native[j]:+.12e}"
            )

        results[j] = {
            "paper_shear_gamma": gamma_paper,
            "native_weight_shear_gamma": gamma_native_weight,
            "rotation_only_sq": rot_only_sq,
            "actual_trapezoid_sq": actual_trap_sq,
            "stored_native_sq": native_sq,
        }

    return results     
    
def predict_growth_rate(glr, m=None):
    """
    Full local WKB prediction from FLORA's generated coefficients.
    Works for zero or nonzero rotation.

    Call after glr.glrgen().
    """
    if m is None:
        m = float(glr.mm)

    e = np.asarray(glr.rhoave, dtype=float).reshape(-1)
    f = np.asarray(glr.xxxave, dtype=float).reshape(-1)
    g = np.asarray(glr.yyyave, dtype=float).reshape(-1)
    curvature = np.asarray(glr.flute3, dtype=float).reshape(-1)
    dro = np.asarray(glr.droave, dtype=float).reshape(-1)

    valid = (
        (e > 0)
        & np.isfinite(e)
        & np.isfinite(f)
        & np.isfinite(g)
        & np.isfinite(curvature)
        & np.isfinite(dro)
    )

    if not np.any(valid):
        raise ValueError("No valid surfaces for the WKB prediction.")

    gamma_by_surface = np.full(e.shape, np.nan)

    trad = (
        0.25 * m**2 * (f[valid]**2 + 4.0 * e[valid] * g[valid])
        - e[valid]**2 * curvature[valid]
        - dro[valid] * g[valid]
    )

    gamma_by_surface[valid] = (
        np.sqrt(np.maximum(-trad, 0.0)) / e[valid]
    )

    j = int(np.nanargmax(gamma_by_surface))

    return {
        "gamma": float(gamma_by_surface[j]),
        "surface": j,
        "gamma_by_surface": gamma_by_surface,
    }       #
    
def eikonal_growth_rate(glr, mode_number=None, include_curvature=False):
    """
    Local eikonal prediction using FLORA's integrated coefficients.

    include_curvature=False:
        Eq. (55): e*omega**2 - m*f*omega - m**2*g = 0

    include_curvature=True:
        Eq. (58): e*(omega**2 + gamma_c**2)
                  - m*f*omega - m**2*g = 0

    Assumes perturbations proportional to exp(-1j*omega*t).
    Returns growth rates in s^-1 and angular frequencies in rad/s.

    Coefficients reflect the rotation/FLR switches used when glr.gen()
    generated the equilibrium. This function does not change those switches.
    """
    m = float(glr.mm if mode_number is None else mode_number)

    if not np.isfinite(m) or m == 0:
        raise ValueError("mode_number must be finite and nonzero.")

    def surface_array(name):
        return np.asarray(getattr(glr, name), dtype=float).reshape(-1)

    e = surface_array("rhoave")
    f = surface_array("xxxave")
    g = surface_array("yyyave")

    if not (e.shape == f.shape == g.shape):
        raise ValueError("rhoave, xxxave and yyyave must have matching shapes.")

    curvature = (
        surface_array("flute3")
        if include_curvature
        else np.zeros_like(e)
    )

    if curvature.shape != e.shape:
        raise ValueError("flute3 must have the same shape as rhoave.")

    # Exclude FLORA's radial boundary/ghost surfaces.
    valid = (
        np.isfinite(e) & (e > 0)
        & np.isfinite(f)
        & np.isfinite(g)
        & np.isfinite(curvature)
    )
    valid[0] = False
    valid[-1] = False

    if not np.any(valid):
        raise ValueError("No valid interior flux surfaces.")

    f_over_e = np.full_like(e, np.nan)
    g_over_e = np.full_like(e, np.nan)

    np.divide(f, e, out=f_over_e, where=valid)
    np.divide(g, e, out=g_over_e, where=valid)

    # omega = m*f/(2e) +/- sqrt(D)
    discriminant = (
        m**2 * (0.25 * f_over_e**2 + g_over_e)
        - curvature
    )

    root = np.sqrt(discriminant.astype(complex))
    centre = 0.5 * m * f_over_e

    omega_plus = centre + root
    omega_minus = centre - root

    gamma = np.full_like(e, np.nan)
    gamma[valid] = np.sqrt(
        np.maximum(-discriminant[valid], 0.0)
    )

    j_fast = int(np.nanargmax(gamma))

    return {
        "equation": "58" if include_curvature else "55",
        "mode_number": m,
        "gamma": float(gamma[j_fast]),
        "fastest_surface": j_fast,
        "gamma_by_surface": gamma,
        "omega_plus_by_surface": omega_plus,
        "omega_minus_by_surface": omega_minus,
        "curvature_gamma_squared_by_surface": curvature,
        "discriminant_by_surface": discriminant,
    }   
    
def figure3b_theory(
    glr,
    omega_c=400.0,
    omega_p = 0.0,
    mode_number=50,
    z_split=None,
):
    """
    Calculate Cohen Figure 3b local theoretical predictions.

    S = 0:      Eq. (63), centrifugal + curvature.
    S = 0.5, 1: Eq. (55), weak-FLR axial shear.

    Uses the paper's averaging measure:
        <A> = integral(A dz / B)

    Assumes an ideal two-cell rotation step.
    Call after glr.glrgen().

    Assumes mutually consistent native FLORA units.
    """
    m = float(mode_number)
    omega_c = float(omega_c)
    omega_p = float(omega_p)   
    z_split = float(glr.z1c if z_split is None else z_split)
    
    #Set ratio of omegas
    S =  round(1.0 - (omega_p / omega_c), 1)
    
    
    if not np.all(np.isfinite([m, omega_c,omega_p, z_split])):
        raise ValueError("Mode number, rotation and interface must be finite.")

    z = np.asarray(glr.z, dtype=float).reshape(-1)
    psi = np.asarray(glr.psi, dtype=float).reshape(-1)

    arrays = [
        np.asarray(getattr(glr, name), dtype=float).copy()
        for name in ("rho", "b", "r", "rzz", "pperp", "ppar")
    ]

    expected_shape = (z.size, psi.size)
    if any(a.shape != expected_shape for a in arrays):
        raise ValueError(
            "Spatial arrays must have shape (len(z), len(psi))."
        )

    # ----------------------------------------------------------
    # Clean radial coordinates and ALL radial arrays together.
    # ----------------------------------------------------------

    # Exclude radial boundary/ghost surfaces first.
    surfaces = np.arange(1, psi.size - 1)
    psi = psi[surfaces]
    arrays = [a[:, surfaces] for a in arrays]

    # Remove nonfinite flux coordinates.
    finite = np.isfinite(psi)
    surfaces = surfaces[finite]
    psi = psi[finite]
    arrays = [a[:, finite] for a in arrays]

    # Sort by flux coordinate.
    order = np.argsort(psi, kind="stable")
    surfaces = surfaces[order]
    psi = psi[order]
    arrays = [a[:, order] for a in arrays]

    # Remove duplicates, retaining the first occurrence.
    psi, keep = np.unique(psi, return_index=True)
    surfaces = surfaces[keep]
    arrays = [a[:, keep] for a in arrays]

    rho, B, r, kappa, pperp, ppar = arrays

    if psi.size < 3:
        raise ValueError(
            "Fewer than three distinct interior flux surfaces."
        )

    print(
        f"Using {psi.size} distinct radial surfaces; "
        f"psi range = {psi[0]:.6e} to {psi[-1]:.6e}"
    )

    # ----------------------------------------------------------
    # Clean axial coordinates and ALL axial arrays together.
    # ----------------------------------------------------------

    valid_z = (
        np.isfinite(z)
        & np.all(np.isfinite(rho) & (rho >= 0), axis=1)
        & np.all(np.isfinite(B) & (B > 0), axis=1)
        & np.all(np.isfinite(r) & (r > 0), axis=1)
        & np.all(np.isfinite(kappa), axis=1)
        & np.all(np.isfinite(pperp), axis=1)
        & np.all(np.isfinite(ppar), axis=1)
    )

    z = z[valid_z]
    arrays = [
        a[valid_z]
        for a in (rho, B, r, kappa, pperp, ppar)
    ]

    order = np.argsort(z, kind="stable")
    z = z[order]
    arrays = [a[order] for a in arrays]

    z, keep = np.unique(z, return_index=True)
    arrays = [a[keep] for a in arrays]

    rho, B, r, kappa, pperp, ppar = arrays

    if z.size < 3:
        raise ValueError("Fewer than three distinct valid axial points.")

    if not z[0] < z_split < z[-1]:
        raise ValueError(
            "z_split must lie inside the valid axial domain."
        )

    # ----------------------------------------------------------
    # Insert the cell interface for the step-profile integrals.
    # ----------------------------------------------------------

    if not np.any(z == z_split):
        i = np.searchsorted(z, z_split)
        fraction = (
            (z_split - z[i - 1]) / (z[i] - z[i - 1])
        )

        def insert_interface(a):
            value = (
                a[i - 1] + fraction * (a[i] - a[i - 1])
            )
            return np.insert(a, i, value, axis=0)

        rho, B, r, kappa, pperp, ppar = [
            insert_interface(a)
            for a in (rho, B, r, kappa, pperp, ppar)
        ]

        z = np.insert(z, i, z_split)

    trap = getattr(np, "trapezoid", None)
    if trap is None:
        trap = np.trapz

    def integral(a):
        return trap(a, x=z, axis=0)

    # ----------------------------------------------------------
    # Equilibrium coefficients and zero-shear contributions.
    # ----------------------------------------------------------

    # Eq. (48b): e = <rho/B> = integral(rho/B^2 dz).
    weight = rho / B**2
    e = integral(weight)

    # Eq. (48e): H = -<2*kappa*pbar/(r*B)>.
    pbar = 0.5 * (pperp + ppar)
    H = -integral(
        2.0 * kappa * pbar / (r * B**2)
    )

    dH_dpsi = np.gradient(H, psi, edge_order=2)
    drho_dpsi = np.gradient(
        rho, psi, axis=1, edge_order=2
    )

    with np.errstate(divide="ignore", invalid="ignore"):
        # Eq. (54).
        curvature_sq = -2.0 * psi * dH_dpsi / e

        # Centrifugal contribution in Eq. (63).
        centrifugal_sq = (
            -2.0 * psi * omega_c**2
            * integral(drho_dpsi / B**2) / e
        )

    central = z <= z_split
    W_central = trap(
        weight[central], x=z[central], axis=0
    )
    W_anchor = e - W_central

    with np.errstate(divide="ignore", invalid="ignore"):
        q = W_central / e

    # Allow only roundoff-sized excursions outside [0, 1].
    q_valid = np.isfinite(q) & (q >= -1e-12) & (q <= 1.0 + 1e-12)
    q = np.clip(q, 0.0, 1.0)

    # ----------------------------------------------------------
    # Calculate growth rate for given S 
    # ----------------------------------------------------------

    output = {}

    omega_a = (1.0 - S) * omega_c

    # Eq. (48c,d), weak-FLR rotation-only coefficients.
    f = 2.0 * (
        omega_c * W_central + omega_a * W_anchor
        )
        
    g = -(
        omega_c**2 * W_central
        + omega_a**2 * W_anchor
        )

    if S == 0.0:
        gamma_sq = curvature_sq + centrifugal_sq
        equation = "63"
        
    else:
            # Eq. (55), evaluated without moment cancellation.
        gamma_sq = (
            m**2
            * (omega_c - omega_a)**2
            * q * (1.0 - q)
        )
        equation = "55"

    valid = (
        (e > 0)
        & np.isfinite(e)
        & np.isfinite(gamma_sq)
        & q_valid
        )

    if not np.any(valid):
        raise ValueError(
            f"No valid theoretical predictions for S={S}."
        )

            
    gamma = np.sqrt(np.maximum(gamma_sq[valid], 0.0))

    j = int(np.nanargmax(gamma))

    output = {
        "gamma": float(gamma[j]),
        "surface": int(surfaces[j]),
        "psi": float(psi[j]),
        "q": float(q[j]),
        "equation": equation,
        "omega_c": omega_c,
        "omega_a": omega_a,
        "gamma_by_surface": gamma,
        "gamma_sq_by_surface": gamma_sq.copy(),
        "surface_indices": surfaces.copy(),
        "psi_by_surface": psi.copy(),
        "q_by_surface": q.copy(),
        "e": e.copy(),
        "f": f,
        "g": g,
        "curvature_sq": curvature_sq.copy(),
        "centrifugal_sq": centrifugal_sq.copy(),
        }

    return output    
     
