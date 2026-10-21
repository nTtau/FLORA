""" PYTHON SCRIPT TO RECREATE FIGURE 2 OF THE COHEN PAPER """
""" DOI: https://doi.org/10.1063/1.865673 """

""" Author: S Sharpe  """ 
""" Date: October 20th 2026 """

#IMPORT FLORA 
from flora import *
from flora.flora_graphics import plots1

#IMPORT CUSTOM MODULES 
import PlottingFunctions as Plotting
import GrowthPredictions as GP
import CalculateFunctions as CF

#IMPORT GENERAL PYTHON LIBS 
import matplotlib.pyplot as plt
import numpy as np

#  LOAD INPUT FILES 
import jpostvbb
import in_Cohen_Fig2  # Use input for Figure 2 - has rotation at 400Hz everywhere


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

#extract r,z,psi values from glr
r = np.asarray(glr.r)
z = np.asarray(glr.z)
psi = np.asarray(glr.psi)

# ====================================================================
# TIME DEPENDENT PERTUBATION: 
#
# Runs timestepping to study the growth rate over time 
# These growth rates are used as the 'FLORA' result for Cohen fig 2a 
# Also tracks radial displacement for Cohen fig 2b 
#
# ====================================================================

print("\n=== ADVANCING PERTUBATION WITH TIME ===")

#Set up lists to store the time,local amplitude and global amplitude 
times = []
amplitude_point = []
amplitude_global = []


# k_values = Fortran r grid indices to analyse
# Used for recreation of 2a, looks at growth rate at different flux surfaces
# For the single value (identical to Cohen) just give the index that 
# corresponds to peak of the Flute3 
k_values = [2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40]

amplitudes = [[] for k in k_values]

#Choose z indexes to calculate radial displacement at 
#Current values set to match the Diagno.F module 
#But any value may be given 

ix = int(glr.ix)

# Python indices corresponding approximately to the
# Fortran diagnostic locations
iz_1 = ix // 2 - 1
iz_2 = ix // 4 - 1

print("FLORA diagnostic positions:")
print("position 1:", iz_1, z[iz_1])
print("position 2:", iz_2, z[iz_2])

z_targets = [z[iz_1], z[iz_2]]       # cm

# Find nearest FLORA axial-grid indices
z_indices = [iz_1,iz_2]

print("\nRadial displacement locations:")
for z_target, iz in zip(z_targets, z_indices):
    print(
        f"requested z = {z_target:.3f} cm, "
        f"using z[{iz}] = {z[iz]:.3f} cm"
    )

# One list for each axial position
xi_history = {
    z_target: []
    for z_target in z_targets
}


# Start the loop[ through all timesteps 

# loop, iterate through to glr.nmax -1 (account for different start ordering in python vs fortran) 
for i in range(glr.nmax-1):

    #call python exposed glrexe routine set up to advance pertubation 
    #each call to glrexepy advances by a single timestep 
    
    glr.glrexepy()

    n = int(glr.n)

    # Current simulation time
    t = float(glr.time[n - 1])
   
    #Calculate the local amplitudes at different k values specified above 
    for j, k in enumerate(k_values):
        k_python = k - 1  # Fortran to Python index

        A = np.sqrt(
            glr.xro[k_python]**2 +
            glr.xio[k_python]**2
        )

        #Append to local amplitudes list 
        amplitudes[j].append(A)

    # Calculate global amplitude    
    A_global = np.sqrt(
        np.sum(np.asarray(glr.xro)**2) +
        np.sum(np.asarray(glr.xio)**2)
    )

    #Append lists 
    times.append(t)
    amplitude_global.append(A_global)
    

    # Save complete radial displacement at each requested z

    for z_target, iz in zip(z_targets, z_indices):

        xi = CF.calculate_radial_displacement_at_z(glr,iz)

        xi_history[z_target].append(xi.copy())
    
#Convert to array                    
times = np.asarray(times)
   
print("\n=== PERTUBATION WITH TIME COMPLETE ===") 

# ====================================================================
# GENERATE FIGURES : 
#
# Calls the plotting module to create plots that correspond with 
# Figures 2a and 2b of the Cohen paper for the equilibrium specified
# by the input deck
#
# Saves pngs in the outputs directory
# ====================================================================   

print("\n=== CREATING PLOT FOR FIGURE 2a ===") 

Plotting.PlotCohen2a(glr,k_values,amplitudes,times,useWKB=True,useFlute3=False)

print("\n=== CREATING PLOT FOR FIGURE 2b ===")

Plotting.plot_radial_displacement(
    glr,
    xi_history,
    times,
    z_target=z[iz_1],
    timesteps=[45000,46000,47000,48000,49000,50000],
)

Plotting.plot_radial_displacement(
    glr,
    xi_history,
    times,
    z_target=z[iz_2],
    timesteps=[45000,46000,47000,48000,49000,50000],
)



