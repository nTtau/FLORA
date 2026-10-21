from flora import *

#Time controls 
glr.dt		=1e-7 # timestep
glr.lmax	=0 # Iteration limit - set to zero by default? 
glr.ndiag	=500 # number timesteps between diagnostic plots 
glr.nen		=500 # number timesteps between energy checks 
glr.nmax	=60000 # total number of timesteps to simulate
#glr.nmax	=100000 # total number of timesteps to simulate
glr.kplotm	=15 #Index of spatial location of time history plots, if ==0, center of region is used
glr.bias	=0.25 # time centring param, 0 = fully centred, 1 = fully forward bias 

#Grid params and machine dimensions 
glr.fpsi	=0.5# Grid stretching parameter
glr.fu		=0.5# Grid stretching parameter
glr.fv		=0.5# Grid stretching parameter
glr.fz		=0.5# Grid stretching parameter 
glr.zmax	=200  # max z of computational domain 

#boundary conditions 
glr.fi1		=1 # min z boundary condition (slope or zero value)
glr.fizx	=1 # max z boundary condition
glr.fj1		=0 # minimum psi boundary condition, 
glr.fjrx	=-1 # max psi boundary condition 
glr.rw1		=11.99 # value just below wall radius (within one cell)  
glr.rw		=12 # wall radius: physical radius of the conducting vacuum chamber wall around plasma

#Coils / Regions
glr.ncoil	=2 # number of coils / regions 
glr.als		=[10,10,0] # solenoid length 
glr.ass		= 25.0 # solenoid radius 
glr.z1c		=100 #z of choke 
glr.z2c		=190 #z inboard end plug 
glr.z3c		=500.0 #z outboard end plug

#Betas
pFactor = 0.1
glr.betcene	=1e-6*pFactor #  centre cell electron beta
glr.betcent	=1e-6*pFactor # peak centre cell ion beta 
glr.betpas1	=0.0000*pFactor # centre cell passing beta 
glr.betrap	=1e-6*pFactor # peak choke cell beta 
glr.betring	=0.5e-6*pFactor # peak hot electron beta 
glr.betslse	=0.5e-6*pFactor # peak warm sloshing electron beta 
glr.betslsh	=0.5e-6*pFactor # peak sloshing ion beta 
glr.betslsks	=1e-9*pFactor # K-S related beta profile param 

#Magnetic field values and related params 
#Note: Mag field in Gauss, not Tesla 
glr.bceng	=1000.0 # magnetic field in centre cell - 0.1T
glr.bmx1	=9000.0 # mag field at choke coil solenoid  -1T
glr.bmx2	=9000.0 # mag field at inboard end plug solenoid 
glr.bmx3	=0.0 # mag field at outer end plug solenoid  ( 2 regions so not used) 
glr.ltrans	=0.1	#Scale length, normalized to zmax, for center cell vacuum field transition region
glr.ztrans	=1.2 # Z position of center cell field transition region.

#Densities 
#Note: densities are measured in particles/cm^3 
glr.cold	=1e-6 # global density min
glr.d1trap	=1e12 # peak denisty in choke cell 
glr.nsloshin	=1e12 # peak plug cell density 
glr.ncenter	=2e12 #centre cell density 
glr.dpas1	=0 # centre cell passing density 

#Pressure / pressure profile coeffs
glr.p2wide	=0.9 #Parameter inversely proportional to ramp width of p2t in ion radial pressure profile
glr.p2ewide	=0.9 #Parameter inversely proportional to ramp width of p2t in electron radial pressure profile
glr.pe10	=0 #Coefficient of hot electron radial pressure profile
glr.ppas2	=0.98 #Minimum passing pressure in choke cell, fraction of ppas1
glr.ppas3	=0.98#Maximum passing pressure at inboard mirror of end plug cell,fraction of ppas1
glr.p2flag	=0.0 # Value of p2 at which p1 and p2 are set constant
glr.p2floor	=0.0 # Value to which p2 is set if p2 <= p2flag

# magnetic flux (psi) related inputs
glr.psi0erel	=0.4 # Psi value relative to psimax at which hot electron radial pressure half max 
glr.psi0rel	=0.4 # Psi value relative to psimax at which ion radial pressure is half max
glr.psi3rel	=1.05 # Psi value relative to psimax where electric field=0.
glr.psihrel	=1.6  # Psi value relative to psimax of halo.
glr.dpsihrel	=0.03 # Psi width relative to psimax of transition to halo region.
glr.dip		=0 # Parameter in psi pressure profile

#electrostatic potential params 


#electrostatic potential params 
#For figure 2, need 400Hz everywhere 
#set shear to 0 
s = 0              # Desired shear
central_amplitude = -70.0 
glr.phicen = s * central_amplitude
glr.phiplg = (1.0 - s) * central_amplitude
#glr.phicen = 0.0
#glr.phiplg = 0.0

glr.ypot	=1# Power of polynomial in potential psi dependence.
glr.xpot =20000.0
glr.wpot = 0.0

#Scaling factors 
glr.sf6		=1 # scaling factor on gyroscopic FLR term, 0 = flr off 
glr.sf8		=1 # scaling factor on quasi-elastic FLR term, 0 = flr off 

# Pertubation / instability 
glr.ex0		=1# Initial perturbation coefficient, ==1 random perturbation
glr.ex1		=1# Initial perturbation coefficient, ==1 for cosine cosine distribution
glr.kzs		=1# Flute mode initialization, ==1 & ex0==1 & ex1==1 sets initial condition r B xro=0 and and r B xio=0.

#Hot electron params 
glr.long		=1# Switch which sets hot electron z-length as elongated (long==1) or regular (long==0)
glr.fring		=0.5# Used for elongated hot electrons 
glr.z3rel		=0.94#Outer axial position where hot electrons go to zero

#sloshing shape params? 
glr.pfudge		=0 # psrameter for sloshing shape? - set to 0 as default 
glr.pfudgeks	=1.99 # No def in user guide or glr.v
glr.rp1		=2 # Mirror ratio of the inner component of the sloshing profile
glr.rp1ks	=2# Mirror ratio of inner component of KS sloshing profile.

#BOOLEAN FLAGS
glr.doflat	=False # flat profile option 
glr.dorzzlb	=False # use simplified curvature model?
glr.doxrlin	=False # linear radial profile 
glr.doxrtanh	=True # tanh based profile 

#Other / unknown 
glr.mm		=50 #  mode number 

glr.rpxks	=30 # no definition in user guide or glr.v 
glr.noshinks	=4e7 # ? Cant find definition in user guide or glr.v
glr.alfcold	=0.001 # exp(-alfcold(JRX-j)) psivariable model  alf 1.->.1 ?
glr.exbratio	=0# omegexb = exbratio*omegstr???
glr.alfrigid	=999## larger for faster decay rigidrotor dpdpsi/p? 











