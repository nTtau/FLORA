""" PYTHON SCRIPT TO RECREATE FIGURE 1 OF THE COHEN PAPER """
""" DOI: https://doi.org/10.1063/1.865673 """

""" Author: S Sharpe  """ 
""" Date: October 20th 2026 """


#IMPORT FLORA 
from flora import *

#IMPORT CUSTOM MODULES 
import PlottingFunctions as Plotting
import CalculateFunctions as CF

#IMPORT GENERAL PYTHON LIBS 
import matplotlib.pyplot as plt
import numpy as np

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


# ====================================================================
# GENERATE THE FIELD PLOTS 
#
# Generates the plots in Figure 1 of the Cohen paper: 
# a) perpendicular pressure 
# b) mass density 
# c) rotational frequency 
#
# Also generates a plot of the magnetic field to compare with the 
# peak magnetic field values  (0.1T in central, 1T in plug cells) 
# and plug midplane value (0.33T)
# ====================================================================

#extract r,z,psi values from glr
r = np.asarray(glr.r)
z = np.asarray(glr.z)
psi = np.asarray(glr.psi)

#Figure 1a - plot perpendicular pressure 

print("\n=== GENERATING PERPENDICULAR PRESSURE PLOT ===")
P = np.asarray(glr.pperp)
Plotting.plotProfiles("P_perp",P,r,z)

#Figure 1b - plot density profile 

print("\n=== GENERATING DENSITY PLOT ===")

rho = np.asarray(glr.rho)
print("rho shape:", rho.shape)
Plotting.plotProfiles("density",rho,r,z)


# Figure 1c - plot rotational frequency

print("\n=== GENERATING ROTATIONAL FREQUENCY PLOT ===")

epsi = np.asarray(glr.epsi)
Omega = -glr.cee * epsi
Plotting.plotProfiles("Rotation",Omega,r,z)

#On axis Magnetic Field Plot
print("\n=== GENERATING MAGNETIC FIELD PLOT ===")

Bfield,Z_coords,EPMidI=CF.calcBTesla(glr) 

#Plot on axis mag field as function of z, with specified paper values shown for comparison 
Plotting.plotBField(Bfield,Z_coords,EPMidI)

#Alternate B plot, plots the on axis mag field but without the specified paper values shown
#Plotting.plotBOnly(Bfield,Z_coords)


