module ArraySizes
  save
  integer(kind=8):: ix=150
  integer(kind=8):: jx=50
  integer(kind=8):: npob=200
  integer(kind=8):: ksimp=23
  integer(kind=8):: nmax=5
  integer(kind=8):: nps=100
  integer(kind=8):: neng=500
  integer(kind=8):: kxx=0
  integer(kind=8):: kbw=0
  integer(kind=8):: lda=0
end module ArraySizes
module Fstor
  save
  real(kind=8):: swg1=1.0
  real(kind=8):: swg2=1.0
  real(kind=8):: swg3=1.0
  real(kind=8):: swg4=1.0
  real(kind=8):: exbratio=-1.0
  real(kind=8):: alfrigid=1.0
  integer(kind=8):: isubp=140
  real(kind=8):: alfsubp=0.5
  logical(kind=8):: dosubp=.true.
  logical(kind=8):: doflat=.false.
  logical(kind=8):: doxrlin=.false.
  logical(kind=8):: doxrtanh=.true.
  logical(kind=8):: dowriteb=.false.
  logical(kind=8):: dorzzlb=.false.
  logical(kind=8):: doplugpob=.true.
  real(kind=8), pointer:: f1(:,:)
  real(kind=8), pointer:: f2(:,:)
  real(kind=8), pointer:: f3(:,:)
  real(kind=8), pointer:: f4(:,:)
  real(kind=8), pointer:: f5(:,:)
  real(kind=8), pointer:: f7(:,:)
  real(kind=8), pointer:: g1(:,:)
  real(kind=8), pointer:: g2(:,:)
  real(kind=8), pointer:: g3(:,:)
  real(kind=8), pointer:: g4(:,:)
  real(kind=8), pointer:: b(:,:)
  real(kind=8), pointer:: rho(:,:)
  real(kind=8), pointer:: qub(:,:)
  real(kind=8), pointer:: r(:,:)
  real(kind=8), pointer:: yyy(:,:)
  real(kind=8), pointer:: xxx(:,:)
  real(kind=8), pointer:: xioo(:)
  real(kind=8), pointer:: xio(:)
  real(kind=8), pointer:: xiol(:)
  real(kind=8), pointer:: xroo(:)
  real(kind=8), pointer:: xro(:)
  real(kind=8), pointer:: xrol(:)
  real(kind=8), pointer:: omstri1(:)
  real(kind=8), pointer:: omgbi1(:)
  real(kind=8), pointer:: omstri34(:)
  real(kind=8), pointer:: omstri66(:)
  real(kind=8), pointer:: omstr148(:)
  real(kind=8), pointer:: omebj1(:)
  real(kind=8), pointer:: omstrj1(:)
end module Fstor
module Matrix
  save
  integer(kind=8), pointer:: ipvt(:)
  real(kind=8), pointer:: a1(:,:)
  real(kind=8), pointer:: a2(:,:)
  real(kind=8), pointer:: a3(:,:)
  real(kind=8), pointer:: b1(:,:)
  real(kind=8), pointer:: bc(:)
  real(kind=8), pointer:: rhs1(:)
  real(kind=8), pointer:: rhs2(:)
  real(kind=8), pointer:: abar(:,:)
end module Matrix
module Const_1a
  save
  integer(kind=8):: iscreen=1
  integer(kind=8):: mm=4
  integer(kind=8):: lmax=2
  integer(kind=8):: isw
  integer(kind=8):: ndiag=100
  integer(kind=8):: kplot
  integer(kind=8):: npm
  integer(kind=8):: kplotm=0
  integer(kind=8):: kzs=1
  integer(kind=8):: n
  integer(kind=8):: ltt
  integer(kind=8):: nen=1
  integer(kind=8):: lee
end module Const_1a
module Const_1
  save
  real(kind=8):: startime
  real(kind=8):: endtime
  real(kind=8):: totalcpu
  real(kind=8):: t
  real(kind=8):: gam1
  real(kind=8):: gam2
  real(kind=8):: fac1
  real(kind=8):: fac2
  real(kind=8):: bias=0.5
  real(kind=8):: du=1.0
  real(kind=8):: dv=1.0
  real(kind=8):: dt=1.0e-5
  real(kind=8):: ex0=0.0
  real(kind=8):: ex1=0.0
  real(kind=8):: fi1=1.0
  real(kind=8):: fizx=1.0
  real(kind=8):: fj1=1.0
  real(kind=8):: fjrx=1.0
  real(kind=8):: fpsi=0.5
  real(kind=8):: fu=0.5
  real(kind=8):: fv=0.5
  real(kind=8):: fz=0.5
  real(kind=8):: azm=1.0
  real(kind=8):: apsim=1.0
  real(kind=8):: u0
  real(kind=8):: v0
  real(kind=8):: amass=3.34e-24
  real(kind=8):: omegexb
  real(kind=8):: sf6=1.0
  real(kind=8):: sf8=1.0
  real(kind=8):: zedge
  real(kind=8):: xu
  real(kind=8):: xv
  real(kind=8):: vw
  real(kind=8):: psiw
  real(kind=8):: dvin
  real(kind=8):: dvout
end module Const_1
module Const_2
  save
  real(kind=8):: psi0rel=0.50
  real(kind=8):: z1rel=0.5
  real(kind=8):: z2rel=1.0
  real(kind=8):: z3rel=0.625
  real(kind=8):: z0rel=0.75
  real(kind=8):: nslosh
  real(kind=8):: nsloshks
  real(kind=8):: bmg=1.0e4
  real(kind=8):: ncenter=1.0e13
  real(kind=8):: pslosh
  real(kind=8):: psloshks
  real(kind=8):: pcenter
  real(kind=8):: ztrans=0.4
  real(kind=8):: ltrans=0.05
  real(kind=8):: bm
  real(kind=8):: ltran
  real(kind=8):: ztran
  real(kind=8):: rp1=2.0
  real(kind=8):: rp1ks=100.0
  real(kind=8):: bcen
  real(kind=8):: pring
  real(kind=8):: epsp=1.0e-6
  real(kind=8):: phicen=0.1
  real(kind=8):: phiplg=0.1
  real(kind=8):: xpot=1.0
  real(kind=8):: ypot=2.0
  real(kind=8):: wpot=2.0
  real(kind=8):: pfudge=0.0
  real(kind=8):: pfudgeks=0.0
  real(kind=8):: rpx
  real(kind=8):: rpxks=0.0
  real(kind=8):: phice
  real(kind=8):: phipl
  real(kind=8):: betslsh=0.25
  real(kind=8):: betslsks=0.0
  real(kind=8):: betcent=0.10
  real(kind=8):: z0
  real(kind=8):: z1
  real(kind=8):: z2
  real(kind=8):: z3
  real(kind=8):: psi0
  real(kind=8):: betcene=0.1
  real(kind=8):: betslse=0.1
  real(kind=8):: psloshe
  real(kind=8):: pcentee
  real(kind=8):: bmax
  real(kind=8):: alsi
  real(kind=8):: alsiks
  real(kind=8):: bm1
  real(kind=8):: bm1ks
  real(kind=8):: bvoutks
  real(kind=8):: psls1
  real(kind=8):: cold=1.0e-5
  real(kind=8):: alfcold=1.0
  real(kind=8):: p2wide=0.1
  real(kind=8):: psi3rel=1.05
  real(kind=8):: psi3
  real(kind=8):: p1max
  real(kind=8):: bv0
  real(kind=8):: bv3
  real(kind=8):: bceng=1.0e3
  real(kind=8):: psloshin
  real(kind=8):: poshinks
  real(kind=8):: psloshen
  real(kind=8):: nsloshin=2.0e13
  real(kind=8):: noshinks=0.0
  real(kind=8):: p3a
  real(kind=8):: p3b
  real(kind=8):: p3c
  real(kind=8):: p3d
  real(kind=8):: psim
  real(kind=8):: pe10=0.0
  real(kind=8):: ae1
  real(kind=8):: be1
  real(kind=8):: ce1
  real(kind=8):: de1
  real(kind=8):: psi0erel=0.5
  real(kind=8):: psi0e
  real(kind=8):: psime
  real(kind=8):: p2ewide=0.2
  real(kind=8):: wp2e
  real(kind=8):: p1floor=0.0
  real(kind=8):: p2flag=1.0e-3
  real(kind=8):: p2floor=0.0
  real(kind=8):: fring=0.9
  real(kind=8):: dip=1.0
  real(kind=8):: psistr
  real(kind=8):: psislp=0.01
  real(kind=8):: psihrel=0.0
  real(kind=8):: psih
  real(kind=8):: dpsihrel=0.0
  real(kind=8):: dpsih
end module Const_2
module Coils
  save
  integer(kind=8):: ncoil=2
  real(kind=8):: z1c=0.0
  real(kind=8):: z2c=0.0
  real(kind=8):: z3c=0.0
  real(kind=8):: ass(3)
  data ass/3*0.0/
  real(kind=8):: als(3)
  data als/3*0.0/
  real(kind=8):: zs(3)
  real(kind=8):: bs(3)
end module Coils
module GFiducials
  save
  integer(kind=8):: nregions=0
  integer(kind=8):: ibvmin(3)
  integer(kind=8):: ibvmax(3)
end module GFiducials
module Const_3
  save
  real(kind=8):: at0
  real(kind=8):: bt0
  real(kind=8):: ct0
  real(kind=8):: cp0
  real(kind=8):: ap1
  real(kind=8):: ap2
  real(kind=8):: ap3
  real(kind=8):: at1
  real(kind=8):: at2
  real(kind=8):: at3
  real(kind=8):: bp1
  real(kind=8):: bp2
  real(kind=8):: bp3
  real(kind=8):: bt1
  real(kind=8):: bt2
  real(kind=8):: bt3
  real(kind=8):: cp1
  real(kind=8):: cp2
  real(kind=8):: cp3
  real(kind=8):: ct1
  real(kind=8):: ct2
  real(kind=8):: ct3
  real(kind=8):: ct2ks
  real(kind=8):: ct3ks
  real(kind=8):: bmx1=0.0
  real(kind=8):: bmx2=0.0
  real(kind=8):: bmx3=0.0
  real(kind=8):: bmn1
  real(kind=8):: bmn2
  real(kind=8):: ppas1
  real(kind=8):: ppas2=0.0
  real(kind=8):: ppas3=0.0
  real(kind=8):: p1trap
  real(kind=8):: z1min
  real(kind=8):: z2min
  real(kind=8):: dpas1=0.0
  real(kind=8):: d1trap=0.0
  real(kind=8):: betrap=0.0
  real(kind=8):: betpas1=0.0
  real(kind=8):: bvx2
  real(kind=8):: bvx3
  real(kind=8):: z2ct
end module Const_3
module Const_4
  save
  real(kind=8), pointer:: psi(:)
  real(kind=8), pointer:: z(:)
  real(kind=8), pointer:: u(:)
  real(kind=8), pointer:: v(:)
  real(kind=8), pointer:: dpsi(:)
  real(kind=8), pointer:: dz(:)
  real(kind=8), pointer:: vpsi(:)
  real(kind=8), pointer:: uuz(:)
  real(kind=8), pointer:: vpsih(:)
  real(kind=8), pointer:: uuzh(:)
end module Const_4
module Const_5
  save
  real(kind=8), pointer:: xrtime(:)
  real(kind=8), pointer:: xrspz(:,:)
  real(kind=8), pointer:: xrsppsi(:,:)
  real(kind=8), pointer:: time(:)
  real(kind=8), pointer:: xflute(:,:)
  real(kind=8), pointer:: enpot(:)
  real(kind=8), pointer:: tenergy(:)
  real(kind=8), pointer:: enkin(:)
  real(kind=8), pointer:: timengy(:)
  real(kind=8), pointer:: tenrel(:)
  real(kind=8), pointer:: enbend(:)
  real(kind=8), pointer:: encurve(:)
  real(kind=8), pointer:: enflr(:)
end module Const_5
module Const_6
  save
  real(kind=8):: lb=1.0e9
  real(kind=8):: rw=0.0
  real(kind=8):: cee=3.0e10
end module Const_6
module Const_7
  save
  real(kind=8):: betring=0.0
  real(kind=8), pointer:: h12(:)
  real(kind=8), pointer:: hzt0(:)
  real(kind=8), pointer:: h34(:)
  real(kind=8), pointer:: abp(:)
  real(kind=8), pointer:: bbp(:)
  real(kind=8), pointer:: cbp(:)
  real(kind=8), pointer:: abf(:)
  real(kind=8), pointer:: bbf(:)
  real(kind=8), pointer:: cbf(:)
  real(kind=8), pointer:: hp3(:)
  real(kind=8), pointer:: htrans(:)
  real(kind=8), pointer:: abq(:)
  real(kind=8), pointer:: bbq(:)
  real(kind=8), pointer:: cbq(:)
  real(kind=8), pointer:: ebp(:)
  real(kind=8), pointer:: fbp(:)
  real(kind=8), pointer:: gbp(:)
  real(kind=8), pointer:: hp0(:)
  real(kind=8), pointer:: hpm(:)
  real(kind=8), pointer:: hpme(:)
  real(kind=8), pointer:: hflr(:)
  real(kind=8), pointer:: hzp0(:)
  real(kind=8), pointer:: hzp1(:)
  real(kind=8), pointer:: hzp2(:)
  real(kind=8), pointer:: hzp3(:)
  real(kind=8), pointer:: hzt1(:)
  real(kind=8), pointer:: hzt2(:)
  real(kind=8), pointer:: hzt3(:)
  real(kind=8), pointer:: hzt2ks(:)
  real(kind=8), pointer:: hzt3ks(:)
  real(kind=8), pointer:: dterjb(:)
end module Const_7
module Const_8
  save
  real(kind=8):: bvmaxp=20.0
  real(kind=8):: bvmaxpg=2.10
  real(kind=8):: bvadj=1.0
  real(kind=8):: alfpg=0.5
  real(kind=8):: alfks=0.5
  integer(kind=8):: delsubp=0
  real(kind=8):: post1
  real(kind=8):: post2
  real(kind=8):: post1r
  real(kind=8):: post2r
  real(kind=8):: postjb
  real(kind=8):: post1sum
  real(kind=8):: post2sum
  real(kind=8):: postjbsum
  real(kind=8):: postjbsumo
  real(kind=8):: post1cc
  real(kind=8):: post2cc
  real(kind=8):: postjbcc
  real(kind=8):: post1pg
  real(kind=8):: post2pg
  real(kind=8):: postjbpg
  real(kind=8):: post1ks
  real(kind=8):: post2ks
  real(kind=8):: postjbks
  real(kind=8):: p1kssubp
  real(kind=8):: p1ksmax
  real(kind=8):: p2ksmax
  real(kind=8):: pjbksmax
  real(kind=8):: pjbksmaxo
  real(kind=8):: pnorm
  real(kind=8):: pperpinj
  real(kind=8):: btksinj
  real(kind=8):: pparinj
  real(kind=8):: pperpinjo
  real(kind=8):: btksinjo
  real(kind=8):: grow
  real(kind=8):: growmax
  real(kind=8):: xfreqmax
  real(kind=8):: rzzrmax
  real(kind=8), pointer:: bvac(:)
  real(kind=8), pointer:: dbvdz(:)
  real(kind=8), pointer:: d2bvdz2(:)
  real(kind=8), pointer:: d3bvdz3(:)
  real(kind=8), pointer:: bint(:)
  real(kind=8), pointer:: dp1dpsi(:)
  real(kind=8), pointer:: p1(:)
  real(kind=8), pointer:: p1k(:,:)
  real(kind=8), pointer:: hpk0(:)
  real(kind=8), pointer:: deli1(:)
  real(kind=8), pointer:: deli2(:)
  real(kind=8), pointer:: deli3(:)
  real(kind=8), pointer:: deli4(:)
  real(kind=8), pointer:: rzz(:,:)
  real(kind=8), pointer:: rzz1a(:)
  real(kind=8), pointer:: rzz1b(:)
  real(kind=8), pointer:: rzz2(:)
  real(kind=8), pointer:: rzz3(:)
  real(kind=8), pointer:: rzz1anew(:)
  real(kind=8), pointer:: rzz1bnew(:)
  real(kind=8), pointer:: rzz2new(:)
  real(kind=8), pointer:: rzz3new(:)
  real(kind=8), pointer:: rzznew(:)
  real(kind=8), pointer:: rzzold(:)
  real(kind=8), pointer:: rd2diff(:)
  real(kind=8), pointer:: rnew(:)
  real(kind=8), pointer:: rnewd2(:)
  real(kind=8), pointer:: rold(:)
  real(kind=8), pointer:: roldd2(:)
  real(kind=8), pointer:: icapi2(:)
  real(kind=8), pointer:: icapi3(:)
  real(kind=8), pointer:: icapi5(:)
  real(kind=8), pointer:: icap2new(:)
  real(kind=8), pointer:: icap3new(:)
  real(kind=8), pointer:: icap5new(:)
  real(kind=8), pointer:: dbdpsi(:,:)
  real(kind=8), pointer:: phi1(:)
  real(kind=8), pointer:: phi2(:)
  real(kind=8), pointer:: pperp(:,:)
  real(kind=8), pointer:: ppar(:,:)
  real(kind=8), pointer:: jperpz(:)
  real(kind=8):: jperpb(1000)
  real(kind=8):: jparb(1000)
  real(kind=8):: jdfb(1000)
  real(kind=8):: jd2fb(1000)
  real(kind=8):: ddbparb(1000)
  real(kind=8):: ddbprpb(1000)
  real(kind=8):: jperpbpg(1000)
  real(kind=8):: jparbpg(1000)
  real(kind=8):: jdfbpg(1000)
  real(kind=8):: jd2fbpg(1000)
  real(kind=8):: ddbparbpg(1000)
  real(kind=8):: ddbprpbpg(1000)
  real(kind=8), pointer:: jparz(:)
  real(kind=8), pointer:: jd2fz(:)
  real(kind=8), pointer:: jdfz(:)
  real(kind=8), pointer:: jbtotz(:)
  real(kind=8), pointer:: jmbselfz(:)
  real(kind=8), pointer:: ddbprpz(:)
  real(kind=8), pointer:: ddbparz(:)
  real(kind=8), pointer:: posh(:)
  real(kind=8), pointer:: nosh(:)
  real(kind=8), pointer:: bvacnorm(:)
  real(kind=8), pointer:: bti82(:)
  real(kind=8), pointer:: btisubp(:)
  real(kind=8), pointer:: btisubpm1(:)
  real(kind=8), pointer:: btisubpm2(:)
  real(kind=8), pointer:: btisubpm3(:)
  real(kind=8), pointer:: jpzsubp(:)
  real(kind=8), pointer:: jpzsubpm1(:)
  real(kind=8), pointer:: jpzsubpm2(:)
  real(kind=8), pointer:: jpzsubpm3(:)
  real(kind=8), pointer:: bj2old(:)
  real(kind=8), pointer:: pperpold(:)
  real(kind=8), pointer:: pperpold25(:)
  real(kind=8), pointer:: pparold(:)
  real(kind=8), pointer:: betaold(:)
  real(kind=8), pointer:: qubold(:)
  real(kind=8), pointer:: qubvold(:)
  real(kind=8), pointer:: dbdpsiold(:)
  real(kind=8), pointer:: dflute3(:)
  real(kind=8), pointer:: qubv(:,:)
  real(kind=8), pointer:: p2(:)
  real(kind=8), pointer:: dp2dpsi(:)
  real(kind=8), pointer:: dflute1(:)
  real(kind=8), pointer:: dflute2(:)
  real(kind=8), pointer:: flute1(:)
  real(kind=8), pointer:: flute2(:)
  real(kind=8), pointer:: flute3(:)
  real(kind=8), pointer:: dpost1(:)
  real(kind=8), pointer:: dpost2(:)
  real(kind=8), pointer:: dpost1r(:)
  real(kind=8), pointer:: dpost2r(:)
  real(kind=8), pointer:: dpostjb(:)
  real(kind=8), pointer:: dpostjbo(:)
  real(kind=8), pointer:: ptot(:)
  real(kind=8), pointer:: beta(:)
  real(kind=8), pointer:: betanorm(:)
  real(kind=8), pointer:: p2k(:,:)
  real(kind=8), pointer:: deli5(:)
  real(kind=8), pointer:: del1new(:)
  real(kind=8), pointer:: del2new(:)
  real(kind=8), pointer:: del3new(:)
  real(kind=8), pointer:: del5new(:)
  real(kind=8), pointer:: pperps(:,:)
  real(kind=8), pointer:: errprp(:,:)
  real(kind=8), pointer:: errprl(:,:)
  real(kind=8), pointer:: dqubdb(:,:)
  real(kind=8), pointer:: xxxfreq(:)
  real(kind=8), pointer:: pperpe(:,:)
  real(kind=8), pointer:: epsi(:,:)
  real(kind=8), pointer:: omeg1wkb(:)
  real(kind=8), pointer:: omeg2wkb(:)
  real(kind=8), pointer:: gamwkb(:)
  real(kind=8), pointer:: dflute4(:)
  real(kind=8), pointer:: rhoave(:)
  real(kind=8), pointer:: xxxave(:)
  real(kind=8), pointer:: yyyave(:)
  real(kind=8), pointer:: p2t(:)
  real(kind=8), pointer:: dp2dpst(:)
  real(kind=8), pointer:: p3(:)
  real(kind=8), pointer:: dp3dpsi(:)
  real(kind=8), pointer:: hpkm(:)
  real(kind=8), pointer:: hpkme(:)
  real(kind=8), pointer:: droave(:)
  real(kind=8), pointer:: droterm(:)
  real(kind=8), pointer:: ering(:,:)
end module Const_8
module TMInput
  save
  integer(kind=8):: long=1
  real(kind=8):: rw1=0.0
  real(kind=8):: zmax=0.0
  integer(kind=8):: info
  real(kind=8):: bsub
  real(kind=8):: frbvac=0.0
  logical(kind=8):: dobvsub=.false.
end module TMInput
module GEnergy
  save
  real(kind=8), pointer:: drxi(:,:)
  real(kind=8), pointer:: drxio(:,:)
  real(kind=8), pointer:: drxr(:,:)
  real(kind=8), pointer:: drxro(:,:)
  real(kind=8), pointer:: dxiz2(:)
  real(kind=8), pointer:: dxrz2(:)
  real(kind=8), pointer:: dum1(:)
  real(kind=8), pointer:: dum2(:)
  real(kind=8), pointer:: psuma(:,:)
  real(kind=8), pointer:: psumb(:,:)
  real(kind=8):: quad(12)
  real(kind=8):: quad1(4)
  real(kind=8), pointer:: rxi(:)
  real(kind=8), pointer:: rxr(:)
  real(kind=8), pointer:: xig(:)
  real(kind=8), pointer:: xigo(:)
  real(kind=8), pointer:: xrg(:)
  real(kind=8), pointer:: xrgo(:)
end module GEnergy
module Glrexec
  save
  real(kind=8), pointer:: rhs1b(:,:)
  real(kind=8), pointer:: rhs2b(:,:)
end module Glrexec
module Splines
  save
  integer(kind=8):: mspin
  integer(kind=8):: mspout
  integer(kind=8), pointer:: lsp(:)
  real(kind=8), pointer:: dsp(:)
  real(kind=8), pointer:: csp1(:)
  real(kind=8), pointer:: csp2(:)
  real(kind=8), pointer:: csp3(:)
  real(kind=8), pointer:: csp4(:)
end module Splines
module Btable
  save
  integer(kind=8):: nks=0
  real(kind=8):: zks(1000)
  real(kind=8):: bks(1000)
end module Btable
subroutine glrpasspointers()
  use ArraySizes
  use Fstor
  use Matrix
  use Const_1a
  use Const_1
  use Const_2
  use Coils
  use GFiducials
  use Const_3
  use Const_4
  use Const_5
  use Const_6
  use Const_7
  use Const_8
  use TMInput
  use GEnergy
  use Glrexec
  use Splines
  use Btable
  call glrgrabscalarpointers_integer(int(0, kind=8), ix)
  call glrgrabscalarpointers_integer(int(1, kind=8), jx)
  call glrgrabscalarpointers_integer(int(2, kind=8), npob)
  call glrgrabscalarpointers_integer(int(3, kind=8), ksimp)
  call glrgrabscalarpointers_integer(int(4, kind=8), nmax)
  call glrgrabscalarpointers_integer(int(5, kind=8), nps)
  call glrgrabscalarpointers_integer(int(6, kind=8), neng)
  call glrgrabscalarpointers_integer(int(7, kind=8), kxx)
  call glrgrabscalarpointers_integer(int(8, kind=8), kbw)
  call glrgrabscalarpointers_integer(int(9, kind=8), lda)
  call glrgrabscalarpointers_real(int(10, kind=8), swg1)
  call glrgrabscalarpointers_real(int(11, kind=8), swg2)
  call glrgrabscalarpointers_real(int(12, kind=8), swg3)
  call glrgrabscalarpointers_real(int(13, kind=8), swg4)
  call glrgrabscalarpointers_real(int(14, kind=8), exbratio)
  call glrgrabscalarpointers_real(int(15, kind=8), alfrigid)
  call glrgrabscalarpointers_integer(int(16, kind=8), isubp)
  call glrgrabscalarpointers_real(int(17, kind=8), alfsubp)
  call glrgrabscalarpointers_logical(int(18, kind=8), dosubp)
  call glrgrabscalarpointers_logical(int(19, kind=8), doflat)
  call glrgrabscalarpointers_logical(int(20, kind=8), doxrlin)
  call glrgrabscalarpointers_logical(int(21, kind=8), doxrtanh)
  call glrgrabscalarpointers_logical(int(22, kind=8), dowriteb)
  call glrgrabscalarpointers_logical(int(23, kind=8), dorzzlb)
  call glrgrabscalarpointers_logical(int(24, kind=8), doplugpob)
  call glrgrabscalarpointers_integer(int(25, kind=8), iscreen)
  call glrgrabscalarpointers_integer(int(26, kind=8), mm)
  call glrgrabscalarpointers_integer(int(27, kind=8), lmax)
  call glrgrabscalarpointers_integer(int(28, kind=8), isw)
  call glrgrabscalarpointers_integer(int(29, kind=8), ndiag)
  call glrgrabscalarpointers_integer(int(30, kind=8), kplot)
  call glrgrabscalarpointers_integer(int(31, kind=8), npm)
  call glrgrabscalarpointers_integer(int(32, kind=8), kplotm)
  call glrgrabscalarpointers_integer(int(33, kind=8), kzs)
  call glrgrabscalarpointers_integer(int(34, kind=8), n)
  call glrgrabscalarpointers_integer(int(35, kind=8), ltt)
  call glrgrabscalarpointers_integer(int(36, kind=8), nen)
  call glrgrabscalarpointers_integer(int(37, kind=8), lee)
  call glrgrabscalarpointers_real(int(38, kind=8), startime)
  call glrgrabscalarpointers_real(int(39, kind=8), endtime)
  call glrgrabscalarpointers_real(int(40, kind=8), totalcpu)
  call glrgrabscalarpointers_real(int(41, kind=8), t)
  call glrgrabscalarpointers_real(int(42, kind=8), gam1)
  call glrgrabscalarpointers_real(int(43, kind=8), gam2)
  call glrgrabscalarpointers_real(int(44, kind=8), fac1)
  call glrgrabscalarpointers_real(int(45, kind=8), fac2)
  call glrgrabscalarpointers_real(int(46, kind=8), bias)
  call glrgrabscalarpointers_real(int(47, kind=8), du)
  call glrgrabscalarpointers_real(int(48, kind=8), dv)
  call glrgrabscalarpointers_real(int(49, kind=8), dt)
  call glrgrabscalarpointers_real(int(50, kind=8), ex0)
  call glrgrabscalarpointers_real(int(51, kind=8), ex1)
  call glrgrabscalarpointers_real(int(52, kind=8), fi1)
  call glrgrabscalarpointers_real(int(53, kind=8), fizx)
  call glrgrabscalarpointers_real(int(54, kind=8), fj1)
  call glrgrabscalarpointers_real(int(55, kind=8), fjrx)
  call glrgrabscalarpointers_real(int(56, kind=8), fpsi)
  call glrgrabscalarpointers_real(int(57, kind=8), fu)
  call glrgrabscalarpointers_real(int(58, kind=8), fv)
  call glrgrabscalarpointers_real(int(59, kind=8), fz)
  call glrgrabscalarpointers_real(int(60, kind=8), azm)
  call glrgrabscalarpointers_real(int(61, kind=8), apsim)
  call glrgrabscalarpointers_real(int(62, kind=8), u0)
  call glrgrabscalarpointers_real(int(63, kind=8), v0)
  call glrgrabscalarpointers_real(int(64, kind=8), amass)
  call glrgrabscalarpointers_real(int(65, kind=8), omegexb)
  call glrgrabscalarpointers_real(int(66, kind=8), sf6)
  call glrgrabscalarpointers_real(int(67, kind=8), sf8)
  call glrgrabscalarpointers_real(int(68, kind=8), zedge)
  call glrgrabscalarpointers_real(int(69, kind=8), xu)
  call glrgrabscalarpointers_real(int(70, kind=8), xv)
  call glrgrabscalarpointers_real(int(71, kind=8), vw)
  call glrgrabscalarpointers_real(int(72, kind=8), psiw)
  call glrgrabscalarpointers_real(int(73, kind=8), dvin)
  call glrgrabscalarpointers_real(int(74, kind=8), dvout)
  call glrgrabscalarpointers_real(int(75, kind=8), psi0rel)
  call glrgrabscalarpointers_real(int(76, kind=8), z1rel)
  call glrgrabscalarpointers_real(int(77, kind=8), z2rel)
  call glrgrabscalarpointers_real(int(78, kind=8), z3rel)
  call glrgrabscalarpointers_real(int(79, kind=8), z0rel)
  call glrgrabscalarpointers_real(int(80, kind=8), nslosh)
  call glrgrabscalarpointers_real(int(81, kind=8), nsloshks)
  call glrgrabscalarpointers_real(int(82, kind=8), bmg)
  call glrgrabscalarpointers_real(int(83, kind=8), ncenter)
  call glrgrabscalarpointers_real(int(84, kind=8), pslosh)
  call glrgrabscalarpointers_real(int(85, kind=8), psloshks)
  call glrgrabscalarpointers_real(int(86, kind=8), pcenter)
  call glrgrabscalarpointers_real(int(87, kind=8), ztrans)
  call glrgrabscalarpointers_real(int(88, kind=8), ltrans)
  call glrgrabscalarpointers_real(int(89, kind=8), bm)
  call glrgrabscalarpointers_real(int(90, kind=8), ltran)
  call glrgrabscalarpointers_real(int(91, kind=8), ztran)
  call glrgrabscalarpointers_real(int(92, kind=8), rp1)
  call glrgrabscalarpointers_real(int(93, kind=8), rp1ks)
  call glrgrabscalarpointers_real(int(94, kind=8), bcen)
  call glrgrabscalarpointers_real(int(95, kind=8), pring)
  call glrgrabscalarpointers_real(int(96, kind=8), epsp)
  call glrgrabscalarpointers_real(int(97, kind=8), phicen)
  call glrgrabscalarpointers_real(int(98, kind=8), phiplg)
  call glrgrabscalarpointers_real(int(99, kind=8), xpot)
  call glrgrabscalarpointers_real(int(100, kind=8), ypot)
  call glrgrabscalarpointers_real(int(101, kind=8), wpot)
  call glrgrabscalarpointers_real(int(102, kind=8), pfudge)
  call glrgrabscalarpointers_real(int(103, kind=8), pfudgeks)
  call glrgrabscalarpointers_real(int(104, kind=8), rpx)
  call glrgrabscalarpointers_real(int(105, kind=8), rpxks)
  call glrgrabscalarpointers_real(int(106, kind=8), phice)
  call glrgrabscalarpointers_real(int(107, kind=8), phipl)
  call glrgrabscalarpointers_real(int(108, kind=8), betslsh)
  call glrgrabscalarpointers_real(int(109, kind=8), betslsks)
  call glrgrabscalarpointers_real(int(110, kind=8), betcent)
  call glrgrabscalarpointers_real(int(111, kind=8), z0)
  call glrgrabscalarpointers_real(int(112, kind=8), z1)
  call glrgrabscalarpointers_real(int(113, kind=8), z2)
  call glrgrabscalarpointers_real(int(114, kind=8), z3)
  call glrgrabscalarpointers_real(int(115, kind=8), psi0)
  call glrgrabscalarpointers_real(int(116, kind=8), betcene)
  call glrgrabscalarpointers_real(int(117, kind=8), betslse)
  call glrgrabscalarpointers_real(int(118, kind=8), psloshe)
  call glrgrabscalarpointers_real(int(119, kind=8), pcentee)
  call glrgrabscalarpointers_real(int(120, kind=8), bmax)
  call glrgrabscalarpointers_real(int(121, kind=8), alsi)
  call glrgrabscalarpointers_real(int(122, kind=8), alsiks)
  call glrgrabscalarpointers_real(int(123, kind=8), bm1)
  call glrgrabscalarpointers_real(int(124, kind=8), bm1ks)
  call glrgrabscalarpointers_real(int(125, kind=8), bvoutks)
  call glrgrabscalarpointers_real(int(126, kind=8), psls1)
  call glrgrabscalarpointers_real(int(127, kind=8), cold)
  call glrgrabscalarpointers_real(int(128, kind=8), alfcold)
  call glrgrabscalarpointers_real(int(129, kind=8), p2wide)
  call glrgrabscalarpointers_real(int(130, kind=8), psi3rel)
  call glrgrabscalarpointers_real(int(131, kind=8), psi3)
  call glrgrabscalarpointers_real(int(132, kind=8), p1max)
  call glrgrabscalarpointers_real(int(133, kind=8), bv0)
  call glrgrabscalarpointers_real(int(134, kind=8), bv3)
  call glrgrabscalarpointers_real(int(135, kind=8), bceng)
  call glrgrabscalarpointers_real(int(136, kind=8), psloshin)
  call glrgrabscalarpointers_real(int(137, kind=8), poshinks)
  call glrgrabscalarpointers_real(int(138, kind=8), psloshen)
  call glrgrabscalarpointers_real(int(139, kind=8), nsloshin)
  call glrgrabscalarpointers_real(int(140, kind=8), noshinks)
  call glrgrabscalarpointers_real(int(141, kind=8), p3a)
  call glrgrabscalarpointers_real(int(142, kind=8), p3b)
  call glrgrabscalarpointers_real(int(143, kind=8), p3c)
  call glrgrabscalarpointers_real(int(144, kind=8), p3d)
  call glrgrabscalarpointers_real(int(145, kind=8), psim)
  call glrgrabscalarpointers_real(int(146, kind=8), pe10)
  call glrgrabscalarpointers_real(int(147, kind=8), ae1)
  call glrgrabscalarpointers_real(int(148, kind=8), be1)
  call glrgrabscalarpointers_real(int(149, kind=8), ce1)
  call glrgrabscalarpointers_real(int(150, kind=8), de1)
  call glrgrabscalarpointers_real(int(151, kind=8), psi0erel)
  call glrgrabscalarpointers_real(int(152, kind=8), psi0e)
  call glrgrabscalarpointers_real(int(153, kind=8), psime)
  call glrgrabscalarpointers_real(int(154, kind=8), p2ewide)
  call glrgrabscalarpointers_real(int(155, kind=8), wp2e)
  call glrgrabscalarpointers_real(int(156, kind=8), p1floor)
  call glrgrabscalarpointers_real(int(157, kind=8), p2flag)
  call glrgrabscalarpointers_real(int(158, kind=8), p2floor)
  call glrgrabscalarpointers_real(int(159, kind=8), fring)
  call glrgrabscalarpointers_real(int(160, kind=8), dip)
  call glrgrabscalarpointers_real(int(161, kind=8), psistr)
  call glrgrabscalarpointers_real(int(162, kind=8), psislp)
  call glrgrabscalarpointers_real(int(163, kind=8), psihrel)
  call glrgrabscalarpointers_real(int(164, kind=8), psih)
  call glrgrabscalarpointers_real(int(165, kind=8), dpsihrel)
  call glrgrabscalarpointers_real(int(166, kind=8), dpsih)
  call glrgrabscalarpointers_integer(int(167, kind=8), ncoil)
  call glrgrabscalarpointers_real(int(168, kind=8), z1c)
  call glrgrabscalarpointers_real(int(169, kind=8), z2c)
  call glrgrabscalarpointers_real(int(170, kind=8), z3c)
  call glrgrabscalarpointers_integer(int(171, kind=8), nregions)
  call glrgrabscalarpointers_real(int(172, kind=8), at0)
  call glrgrabscalarpointers_real(int(173, kind=8), bt0)
  call glrgrabscalarpointers_real(int(174, kind=8), ct0)
  call glrgrabscalarpointers_real(int(175, kind=8), cp0)
  call glrgrabscalarpointers_real(int(176, kind=8), ap1)
  call glrgrabscalarpointers_real(int(177, kind=8), ap2)
  call glrgrabscalarpointers_real(int(178, kind=8), ap3)
  call glrgrabscalarpointers_real(int(179, kind=8), at1)
  call glrgrabscalarpointers_real(int(180, kind=8), at2)
  call glrgrabscalarpointers_real(int(181, kind=8), at3)
  call glrgrabscalarpointers_real(int(182, kind=8), bp1)
  call glrgrabscalarpointers_real(int(183, kind=8), bp2)
  call glrgrabscalarpointers_real(int(184, kind=8), bp3)
  call glrgrabscalarpointers_real(int(185, kind=8), bt1)
  call glrgrabscalarpointers_real(int(186, kind=8), bt2)
  call glrgrabscalarpointers_real(int(187, kind=8), bt3)
  call glrgrabscalarpointers_real(int(188, kind=8), cp1)
  call glrgrabscalarpointers_real(int(189, kind=8), cp2)
  call glrgrabscalarpointers_real(int(190, kind=8), cp3)
  call glrgrabscalarpointers_real(int(191, kind=8), ct1)
  call glrgrabscalarpointers_real(int(192, kind=8), ct2)
  call glrgrabscalarpointers_real(int(193, kind=8), ct3)
  call glrgrabscalarpointers_real(int(194, kind=8), ct2ks)
  call glrgrabscalarpointers_real(int(195, kind=8), ct3ks)
  call glrgrabscalarpointers_real(int(196, kind=8), bmx1)
  call glrgrabscalarpointers_real(int(197, kind=8), bmx2)
  call glrgrabscalarpointers_real(int(198, kind=8), bmx3)
  call glrgrabscalarpointers_real(int(199, kind=8), bmn1)
  call glrgrabscalarpointers_real(int(200, kind=8), bmn2)
  call glrgrabscalarpointers_real(int(201, kind=8), ppas1)
  call glrgrabscalarpointers_real(int(202, kind=8), ppas2)
  call glrgrabscalarpointers_real(int(203, kind=8), ppas3)
  call glrgrabscalarpointers_real(int(204, kind=8), p1trap)
  call glrgrabscalarpointers_real(int(205, kind=8), z1min)
  call glrgrabscalarpointers_real(int(206, kind=8), z2min)
  call glrgrabscalarpointers_real(int(207, kind=8), dpas1)
  call glrgrabscalarpointers_real(int(208, kind=8), d1trap)
  call glrgrabscalarpointers_real(int(209, kind=8), betrap)
  call glrgrabscalarpointers_real(int(210, kind=8), betpas1)
  call glrgrabscalarpointers_real(int(211, kind=8), bvx2)
  call glrgrabscalarpointers_real(int(212, kind=8), bvx3)
  call glrgrabscalarpointers_real(int(213, kind=8), z2ct)
  call glrgrabscalarpointers_real(int(214, kind=8), lb)
  call glrgrabscalarpointers_real(int(215, kind=8), rw)
  call glrgrabscalarpointers_real(int(216, kind=8), cee)
  call glrgrabscalarpointers_real(int(217, kind=8), betring)
  call glrgrabscalarpointers_real(int(218, kind=8), bvmaxp)
  call glrgrabscalarpointers_real(int(219, kind=8), bvmaxpg)
  call glrgrabscalarpointers_real(int(220, kind=8), bvadj)
  call glrgrabscalarpointers_real(int(221, kind=8), alfpg)
  call glrgrabscalarpointers_real(int(222, kind=8), alfks)
  call glrgrabscalarpointers_integer(int(223, kind=8), delsubp)
  call glrgrabscalarpointers_real(int(224, kind=8), post1)
  call glrgrabscalarpointers_real(int(225, kind=8), post2)
  call glrgrabscalarpointers_real(int(226, kind=8), post1r)
  call glrgrabscalarpointers_real(int(227, kind=8), post2r)
  call glrgrabscalarpointers_real(int(228, kind=8), postjb)
  call glrgrabscalarpointers_real(int(229, kind=8), post1sum)
  call glrgrabscalarpointers_real(int(230, kind=8), post2sum)
  call glrgrabscalarpointers_real(int(231, kind=8), postjbsum)
  call glrgrabscalarpointers_real(int(232, kind=8), postjbsumo)
  call glrgrabscalarpointers_real(int(233, kind=8), post1cc)
  call glrgrabscalarpointers_real(int(234, kind=8), post2cc)
  call glrgrabscalarpointers_real(int(235, kind=8), postjbcc)
  call glrgrabscalarpointers_real(int(236, kind=8), post1pg)
  call glrgrabscalarpointers_real(int(237, kind=8), post2pg)
  call glrgrabscalarpointers_real(int(238, kind=8), postjbpg)
  call glrgrabscalarpointers_real(int(239, kind=8), post1ks)
  call glrgrabscalarpointers_real(int(240, kind=8), post2ks)
  call glrgrabscalarpointers_real(int(241, kind=8), postjbks)
  call glrgrabscalarpointers_real(int(242, kind=8), p1kssubp)
  call glrgrabscalarpointers_real(int(243, kind=8), p1ksmax)
  call glrgrabscalarpointers_real(int(244, kind=8), p2ksmax)
  call glrgrabscalarpointers_real(int(245, kind=8), pjbksmax)
  call glrgrabscalarpointers_real(int(246, kind=8), pjbksmaxo)
  call glrgrabscalarpointers_real(int(247, kind=8), pnorm)
  call glrgrabscalarpointers_real(int(248, kind=8), pperpinj)
  call glrgrabscalarpointers_real(int(249, kind=8), btksinj)
  call glrgrabscalarpointers_real(int(250, kind=8), pparinj)
  call glrgrabscalarpointers_real(int(251, kind=8), pperpinjo)
  call glrgrabscalarpointers_real(int(252, kind=8), btksinjo)
  call glrgrabscalarpointers_real(int(253, kind=8), grow)
  call glrgrabscalarpointers_real(int(254, kind=8), growmax)
  call glrgrabscalarpointers_real(int(255, kind=8), xfreqmax)
  call glrgrabscalarpointers_real(int(256, kind=8), rzzrmax)
  call glrgrabscalarpointers_integer(int(257, kind=8), long)
  call glrgrabscalarpointers_real(int(258, kind=8), rw1)
  call glrgrabscalarpointers_real(int(259, kind=8), zmax)
  call glrgrabscalarpointers_integer(int(260, kind=8), info)
  call glrgrabscalarpointers_real(int(261, kind=8), bsub)
  call glrgrabscalarpointers_real(int(262, kind=8), frbvac)
  call glrgrabscalarpointers_logical(int(263, kind=8), dobvsub)
  call glrgrabscalarpointers_integer(int(264, kind=8), mspin)
  call glrgrabscalarpointers_integer(int(265, kind=8), mspout)
  call glrgrabscalarpointers_integer(int(266, kind=8), nks)
  call glrgrabarraypointers_real(int(38, kind=8), ass)
  call glrgrabarraypointers_real(int(39, kind=8), als)
  call glrgrabarraypointers_real(int(40, kind=8), zs)
  call glrgrabarraypointers_real(int(41, kind=8), bs)
  call glrgrabarraypointers_integer(int(42, kind=8), ibvmin)
  call glrgrabarraypointers_integer(int(43, kind=8), ibvmax)
  call glrgrabarraypointers_real(int(139, kind=8), jperpb)
  call glrgrabarraypointers_real(int(140, kind=8), jparb)
  call glrgrabarraypointers_real(int(141, kind=8), jdfb)
  call glrgrabarraypointers_real(int(142, kind=8), jd2fb)
  call glrgrabarraypointers_real(int(143, kind=8), ddbparb)
  call glrgrabarraypointers_real(int(144, kind=8), ddbprpb)
  call glrgrabarraypointers_real(int(145, kind=8), jperpbpg)
  call glrgrabarraypointers_real(int(146, kind=8), jparbpg)
  call glrgrabarraypointers_real(int(147, kind=8), jdfbpg)
  call glrgrabarraypointers_real(int(148, kind=8), jd2fbpg)
  call glrgrabarraypointers_real(int(149, kind=8), ddbparbpg)
  call glrgrabarraypointers_real(int(150, kind=8), ddbprpbpg)
  call glrgrabarraypointers_real(int(235, kind=8), quad)
  call glrgrabarraypointers_real(int(236, kind=8), quad1)
  call glrgrabarraypointers_real(int(251, kind=8), zks)
  call glrgrabarraypointers_real(int(252, kind=8), bks)
  return
end
subroutine glrnullifypointers()
  use ArraySizes
  use Fstor
  use Matrix
  use Const_1a
  use Const_1
  use Const_2
  use Coils
  use GFiducials
  use Const_3
  use Const_4
  use Const_5
  use Const_6
  use Const_7
  use Const_8
  use TMInput
  use GEnergy
  use Glrexec
  use Splines
  use Btable
  nullify(f1)
  nullify(f2)
  nullify(f3)
  nullify(f4)
  nullify(f5)
  nullify(f7)
  nullify(g1)
  nullify(g2)
  nullify(g3)
  nullify(g4)
  nullify(b)
  nullify(rho)
  nullify(qub)
  nullify(r)
  nullify(yyy)
  nullify(xxx)
  nullify(xioo)
  nullify(xio)
  nullify(xiol)
  nullify(xroo)
  nullify(xro)
  nullify(xrol)
  nullify(omstri1)
  nullify(omgbi1)
  nullify(omstri34)
  nullify(omstri66)
  nullify(omstr148)
  nullify(omebj1)
  nullify(omstrj1)
  nullify(ipvt)
  nullify(a1)
  nullify(a2)
  nullify(a3)
  nullify(b1)
  nullify(bc)
  nullify(rhs1)
  nullify(rhs2)
  nullify(abar)
  nullify(psi)
  nullify(z)
  nullify(u)
  nullify(v)
  nullify(dpsi)
  nullify(dz)
  nullify(vpsi)
  nullify(uuz)
  nullify(vpsih)
  nullify(uuzh)
  nullify(xrtime)
  nullify(xrspz)
  nullify(xrsppsi)
  nullify(time)
  nullify(xflute)
  nullify(enpot)
  nullify(tenergy)
  nullify(enkin)
  nullify(timengy)
  nullify(tenrel)
  nullify(enbend)
  nullify(encurve)
  nullify(enflr)
  nullify(h12)
  nullify(hzt0)
  nullify(h34)
  nullify(abp)
  nullify(bbp)
  nullify(cbp)
  nullify(abf)
  nullify(bbf)
  nullify(cbf)
  nullify(hp3)
  nullify(htrans)
  nullify(abq)
  nullify(bbq)
  nullify(cbq)
  nullify(ebp)
  nullify(fbp)
  nullify(gbp)
  nullify(hp0)
  nullify(hpm)
  nullify(hpme)
  nullify(hflr)
  nullify(hzp0)
  nullify(hzp1)
  nullify(hzp2)
  nullify(hzp3)
  nullify(hzt1)
  nullify(hzt2)
  nullify(hzt3)
  nullify(hzt2ks)
  nullify(hzt3ks)
  nullify(dterjb)
  nullify(bvac)
  nullify(dbvdz)
  nullify(d2bvdz2)
  nullify(d3bvdz3)
  nullify(bint)
  nullify(dp1dpsi)
  nullify(p1)
  nullify(p1k)
  nullify(hpk0)
  nullify(deli1)
  nullify(deli2)
  nullify(deli3)
  nullify(deli4)
  nullify(rzz)
  nullify(rzz1a)
  nullify(rzz1b)
  nullify(rzz2)
  nullify(rzz3)
  nullify(rzz1anew)
  nullify(rzz1bnew)
  nullify(rzz2new)
  nullify(rzz3new)
  nullify(rzznew)
  nullify(rzzold)
  nullify(rd2diff)
  nullify(rnew)
  nullify(rnewd2)
  nullify(rold)
  nullify(roldd2)
  nullify(icapi2)
  nullify(icapi3)
  nullify(icapi5)
  nullify(icap2new)
  nullify(icap3new)
  nullify(icap5new)
  nullify(dbdpsi)
  nullify(phi1)
  nullify(phi2)
  nullify(pperp)
  nullify(ppar)
  nullify(jperpz)
  nullify(jparz)
  nullify(jd2fz)
  nullify(jdfz)
  nullify(jbtotz)
  nullify(jmbselfz)
  nullify(ddbprpz)
  nullify(ddbparz)
  nullify(posh)
  nullify(nosh)
  nullify(bvacnorm)
  nullify(bti82)
  nullify(btisubp)
  nullify(btisubpm1)
  nullify(btisubpm2)
  nullify(btisubpm3)
  nullify(jpzsubp)
  nullify(jpzsubpm1)
  nullify(jpzsubpm2)
  nullify(jpzsubpm3)
  nullify(bj2old)
  nullify(pperpold)
  nullify(pperpold25)
  nullify(pparold)
  nullify(betaold)
  nullify(qubold)
  nullify(qubvold)
  nullify(dbdpsiold)
  nullify(dflute3)
  nullify(qubv)
  nullify(p2)
  nullify(dp2dpsi)
  nullify(dflute1)
  nullify(dflute2)
  nullify(flute1)
  nullify(flute2)
  nullify(flute3)
  nullify(dpost1)
  nullify(dpost2)
  nullify(dpost1r)
  nullify(dpost2r)
  nullify(dpostjb)
  nullify(dpostjbo)
  nullify(ptot)
  nullify(beta)
  nullify(betanorm)
  nullify(p2k)
  nullify(deli5)
  nullify(del1new)
  nullify(del2new)
  nullify(del3new)
  nullify(del5new)
  nullify(pperps)
  nullify(errprp)
  nullify(errprl)
  nullify(dqubdb)
  nullify(xxxfreq)
  nullify(pperpe)
  nullify(epsi)
  nullify(omeg1wkb)
  nullify(omeg2wkb)
  nullify(gamwkb)
  nullify(dflute4)
  nullify(rhoave)
  nullify(xxxave)
  nullify(yyyave)
  nullify(p2t)
  nullify(dp2dpst)
  nullify(p3)
  nullify(dp3dpsi)
  nullify(hpkm)
  nullify(hpkme)
  nullify(droave)
  nullify(droterm)
  nullify(ering)
  nullify(drxi)
  nullify(drxio)
  nullify(drxr)
  nullify(drxro)
  nullify(dxiz2)
  nullify(dxrz2)
  nullify(dum1)
  nullify(dum2)
  nullify(psuma)
  nullify(psumb)
  nullify(rxi)
  nullify(rxr)
  nullify(xig)
  nullify(xigo)
  nullify(xrg)
  nullify(xrgo)
  nullify(rhs1b)
  nullify(rhs2b)
  nullify(lsp)
  nullify(dsp)
  nullify(csp1)
  nullify(csp2)
  nullify(csp3)
  nullify(csp4)
  return
end
subroutine glrsetarraypointerf1(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  f1 => p__
  return
end
subroutine glrsetarraypointerf2(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  f2 => p__
  return
end
subroutine glrsetarraypointerf3(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  f3 => p__
  return
end
subroutine glrsetarraypointerf4(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  f4 => p__
  return
end
subroutine glrsetarraypointerf5(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  f5 => p__
  return
end
subroutine glrsetarraypointerf7(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  f7 => p__
  return
end
subroutine glrsetarraypointerg1(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  g1 => p__
  return
end
subroutine glrsetarraypointerg2(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  g2 => p__
  return
end
subroutine glrsetarraypointerg3(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  g3 => p__
  return
end
subroutine glrsetarraypointerg4(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  g4 => p__
  return
end
subroutine glrsetarraypointerb(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  b => p__
  return
end
subroutine glrsetarraypointerrho(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  rho => p__
  return
end
subroutine glrsetarraypointerqub(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  qub => p__
  return
end
subroutine glrsetarraypointerr(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  r => p__
  return
end
subroutine glrsetarraypointeryyy(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  yyy => p__
  return
end
subroutine glrsetarraypointerxxx(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  xxx => p__
  return
end
subroutine glrsetarraypointerxioo(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(kxx)
  xioo => p__
  return
end
subroutine glrsetarraypointerxio(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(kxx)
  xio => p__
  return
end
subroutine glrsetarraypointerxiol(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(kxx)
  xiol => p__
  return
end
subroutine glrsetarraypointerxroo(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(kxx)
  xroo => p__
  return
end
subroutine glrsetarraypointerxro(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(kxx)
  xro => p__
  return
end
subroutine glrsetarraypointerxrol(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(kxx)
  xrol => p__
  return
end
subroutine glrsetarraypointeromstri1(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  omstri1 => p__
  return
end
subroutine glrsetarraypointeromgbi1(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  omgbi1 => p__
  return
end
subroutine glrsetarraypointeromstri34(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  omstri34 => p__
  return
end
subroutine glrsetarraypointeromstri66(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  omstri66 => p__
  return
end
subroutine glrsetarraypointeromstr148(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  omstr148 => p__
  return
end
subroutine glrsetarraypointeromebj1(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  omebj1 => p__
  return
end
subroutine glrsetarraypointeromstrj1(p__, fobj__, dims__)
  use ArraySizes
  use Fstor
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  omstrj1 => p__
  return
end
subroutine glrsetarraypointeripvt(p__, fobj__, dims__)
  use ArraySizes
  use Matrix
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  integer(kind=8), target:: p__(kxx)
  ipvt => p__
  return
end
subroutine glrsetarraypointera1(p__, fobj__, dims__)
  use ArraySizes
  use Matrix
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(kxx,9)
  a1 => p__
  return
end
subroutine glrsetarraypointera2(p__, fobj__, dims__)
  use ArraySizes
  use Matrix
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(kxx,9)
  a2 => p__
  return
end
subroutine glrsetarraypointera3(p__, fobj__, dims__)
  use ArraySizes
  use Matrix
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(kxx,9)
  a3 => p__
  return
end
subroutine glrsetarraypointerb1(p__, fobj__, dims__)
  use ArraySizes
  use Matrix
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(kxx,3)
  b1 => p__
  return
end
subroutine glrsetarraypointerbc(p__, fobj__, dims__)
  use ArraySizes
  use Matrix
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  bc => p__
  return
end
subroutine glrsetarraypointerrhs1(p__, fobj__, dims__)
  use ArraySizes
  use Matrix
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(kxx)
  rhs1 => p__
  return
end
subroutine glrsetarraypointerrhs2(p__, fobj__, dims__)
  use ArraySizes
  use Matrix
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(kxx)
  rhs2 => p__
  return
end
subroutine glrsetarraypointerabar(p__, fobj__, dims__)
  use ArraySizes
  use Matrix
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(lda,kxx)
  abar => p__
  return
end
subroutine glrsetarraypointerpsi(p__, fobj__, dims__)
  use ArraySizes
  use Const_4
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  psi => p__
  return
end
subroutine glrsetarraypointerz(p__, fobj__, dims__)
  use ArraySizes
  use Const_4
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  z => p__
  return
end
subroutine glrsetarraypointeru(p__, fobj__, dims__)
  use ArraySizes
  use Const_4
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  u => p__
  return
end
subroutine glrsetarraypointerv(p__, fobj__, dims__)
  use ArraySizes
  use Const_4
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  v => p__
  return
end
subroutine glrsetarraypointerdpsi(p__, fobj__, dims__)
  use ArraySizes
  use Const_4
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  dpsi => p__
  return
end
subroutine glrsetarraypointerdz(p__, fobj__, dims__)
  use ArraySizes
  use Const_4
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dz => p__
  return
end
subroutine glrsetarraypointervpsi(p__, fobj__, dims__)
  use ArraySizes
  use Const_4
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  vpsi => p__
  return
end
subroutine glrsetarraypointeruuz(p__, fobj__, dims__)
  use ArraySizes
  use Const_4
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  uuz => p__
  return
end
subroutine glrsetarraypointervpsih(p__, fobj__, dims__)
  use ArraySizes
  use Const_4
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  vpsih => p__
  return
end
subroutine glrsetarraypointeruuzh(p__, fobj__, dims__)
  use ArraySizes
  use Const_4
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  uuzh => p__
  return
end
subroutine glrsetarraypointerxrtime(p__, fobj__, dims__)
  use ArraySizes
  use Const_5
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(nmax)
  xrtime => p__
  return
end
subroutine glrsetarraypointerxrspz(p__, fobj__, dims__)
  use ArraySizes
  use Const_5
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,nps)
  xrspz => p__
  return
end
subroutine glrsetarraypointerxrsppsi(p__, fobj__, dims__)
  use ArraySizes
  use Const_5
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(jx,2*nps)
  xrsppsi => p__
  return
end
subroutine glrsetarraypointertime(p__, fobj__, dims__)
  use ArraySizes
  use Const_5
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(nmax)
  time => p__
  return
end
subroutine glrsetarraypointerxflute(p__, fobj__, dims__)
  use ArraySizes
  use Const_5
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,nps)
  xflute => p__
  return
end
subroutine glrsetarraypointerenpot(p__, fobj__, dims__)
  use ArraySizes
  use Const_5
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(neng)
  enpot => p__
  return
end
subroutine glrsetarraypointertenergy(p__, fobj__, dims__)
  use ArraySizes
  use Const_5
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(neng)
  tenergy => p__
  return
end
subroutine glrsetarraypointerenkin(p__, fobj__, dims__)
  use ArraySizes
  use Const_5
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(neng)
  enkin => p__
  return
end
subroutine glrsetarraypointertimengy(p__, fobj__, dims__)
  use ArraySizes
  use Const_5
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(neng)
  timengy => p__
  return
end
subroutine glrsetarraypointertenrel(p__, fobj__, dims__)
  use ArraySizes
  use Const_5
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(neng)
  tenrel => p__
  return
end
subroutine glrsetarraypointerenbend(p__, fobj__, dims__)
  use ArraySizes
  use Const_5
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(neng)
  enbend => p__
  return
end
subroutine glrsetarraypointerencurve(p__, fobj__, dims__)
  use ArraySizes
  use Const_5
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(neng)
  encurve => p__
  return
end
subroutine glrsetarraypointerenflr(p__, fobj__, dims__)
  use ArraySizes
  use Const_5
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(neng)
  enflr => p__
  return
end
subroutine glrsetarraypointerh12(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  h12 => p__
  return
end
subroutine glrsetarraypointerhzt0(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  hzt0 => p__
  return
end
subroutine glrsetarraypointerh34(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  h34 => p__
  return
end
subroutine glrsetarraypointerabp(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  abp => p__
  return
end
subroutine glrsetarraypointerbbp(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  bbp => p__
  return
end
subroutine glrsetarraypointercbp(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  cbp => p__
  return
end
subroutine glrsetarraypointerabf(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  abf => p__
  return
end
subroutine glrsetarraypointerbbf(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  bbf => p__
  return
end
subroutine glrsetarraypointercbf(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  cbf => p__
  return
end
subroutine glrsetarraypointerhp3(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  hp3 => p__
  return
end
subroutine glrsetarraypointerhtrans(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  htrans => p__
  return
end
subroutine glrsetarraypointerabq(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  abq => p__
  return
end
subroutine glrsetarraypointerbbq(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  bbq => p__
  return
end
subroutine glrsetarraypointercbq(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  cbq => p__
  return
end
subroutine glrsetarraypointerebp(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  ebp => p__
  return
end
subroutine glrsetarraypointerfbp(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  fbp => p__
  return
end
subroutine glrsetarraypointergbp(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  gbp => p__
  return
end
subroutine glrsetarraypointerhp0(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  hp0 => p__
  return
end
subroutine glrsetarraypointerhpm(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  hpm => p__
  return
end
subroutine glrsetarraypointerhpme(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  hpme => p__
  return
end
subroutine glrsetarraypointerhflr(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  hflr => p__
  return
end
subroutine glrsetarraypointerhzp0(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  hzp0 => p__
  return
end
subroutine glrsetarraypointerhzp1(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  hzp1 => p__
  return
end
subroutine glrsetarraypointerhzp2(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  hzp2 => p__
  return
end
subroutine glrsetarraypointerhzp3(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  hzp3 => p__
  return
end
subroutine glrsetarraypointerhzt1(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  hzt1 => p__
  return
end
subroutine glrsetarraypointerhzt2(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  hzt2 => p__
  return
end
subroutine glrsetarraypointerhzt3(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  hzt3 => p__
  return
end
subroutine glrsetarraypointerhzt2ks(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  hzt2ks => p__
  return
end
subroutine glrsetarraypointerhzt3ks(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  hzt3ks => p__
  return
end
subroutine glrsetarraypointerdterjb(p__, fobj__, dims__)
  use ArraySizes
  use Const_7
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dterjb => p__
  return
end
subroutine glrsetarraypointerbvac(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  bvac => p__
  return
end
subroutine glrsetarraypointerdbvdz(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dbvdz => p__
  return
end
subroutine glrsetarraypointerd2bvdz2(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  d2bvdz2 => p__
  return
end
subroutine glrsetarraypointerd3bvdz3(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  d3bvdz3 => p__
  return
end
subroutine glrsetarraypointerbint(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  bint => p__
  return
end
subroutine glrsetarraypointerdp1dpsi(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  dp1dpsi => p__
  return
end
subroutine glrsetarraypointerp1(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  p1 => p__
  return
end
subroutine glrsetarraypointerp1k(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ksimp,jx)
  p1k => p__
  return
end
subroutine glrsetarraypointerhpk0(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ksimp)
  hpk0 => p__
  return
end
subroutine glrsetarraypointerdeli1(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ksimp)
  deli1 => p__
  return
end
subroutine glrsetarraypointerdeli2(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ksimp)
  deli2 => p__
  return
end
subroutine glrsetarraypointerdeli3(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ksimp)
  deli3 => p__
  return
end
subroutine glrsetarraypointerdeli4(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ksimp)
  deli4 => p__
  return
end
subroutine glrsetarraypointerrzz(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  rzz => p__
  return
end
subroutine glrsetarraypointerrzz1a(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rzz1a => p__
  return
end
subroutine glrsetarraypointerrzz1b(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rzz1b => p__
  return
end
subroutine glrsetarraypointerrzz2(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rzz2 => p__
  return
end
subroutine glrsetarraypointerrzz3(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rzz3 => p__
  return
end
subroutine glrsetarraypointerrzz1anew(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rzz1anew => p__
  return
end
subroutine glrsetarraypointerrzz1bnew(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rzz1bnew => p__
  return
end
subroutine glrsetarraypointerrzz2new(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rzz2new => p__
  return
end
subroutine glrsetarraypointerrzz3new(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rzz3new => p__
  return
end
subroutine glrsetarraypointerrzznew(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rzznew => p__
  return
end
subroutine glrsetarraypointerrzzold(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rzzold => p__
  return
end
subroutine glrsetarraypointerrd2diff(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rd2diff => p__
  return
end
subroutine glrsetarraypointerrnew(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rnew => p__
  return
end
subroutine glrsetarraypointerrnewd2(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rnewd2 => p__
  return
end
subroutine glrsetarraypointerrold(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  rold => p__
  return
end
subroutine glrsetarraypointerroldd2(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  roldd2 => p__
  return
end
subroutine glrsetarraypointericapi2(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  icapi2 => p__
  return
end
subroutine glrsetarraypointericapi3(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  icapi3 => p__
  return
end
subroutine glrsetarraypointericapi5(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  icapi5 => p__
  return
end
subroutine glrsetarraypointericap2new(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  icap2new => p__
  return
end
subroutine glrsetarraypointericap3new(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  icap3new => p__
  return
end
subroutine glrsetarraypointericap5new(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  icap5new => p__
  return
end
subroutine glrsetarraypointerdbdpsi(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  dbdpsi => p__
  return
end
subroutine glrsetarraypointerphi1(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  phi1 => p__
  return
end
subroutine glrsetarraypointerphi2(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  phi2 => p__
  return
end
subroutine glrsetarraypointerpperp(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  pperp => p__
  return
end
subroutine glrsetarraypointerppar(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  ppar => p__
  return
end
subroutine glrsetarraypointerjperpz(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  jperpz => p__
  return
end
subroutine glrsetarraypointerjparz(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  jparz => p__
  return
end
subroutine glrsetarraypointerjd2fz(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  jd2fz => p__
  return
end
subroutine glrsetarraypointerjdfz(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  jdfz => p__
  return
end
subroutine glrsetarraypointerjbtotz(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  jbtotz => p__
  return
end
subroutine glrsetarraypointerjmbselfz(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  jmbselfz => p__
  return
end
subroutine glrsetarraypointerddbprpz(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  ddbprpz => p__
  return
end
subroutine glrsetarraypointerddbparz(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  ddbparz => p__
  return
end
subroutine glrsetarraypointerposh(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  posh => p__
  return
end
subroutine glrsetarraypointernosh(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  nosh => p__
  return
end
subroutine glrsetarraypointerbvacnorm(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  bvacnorm => p__
  return
end
subroutine glrsetarraypointerbti82(p__, fobj__, dims__)
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(100)
  bti82 => p__
  return
end
subroutine glrsetarraypointerbtisubp(p__, fobj__, dims__)
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(100)
  btisubp => p__
  return
end
subroutine glrsetarraypointerbtisubpm1(p__, fobj__, dims__)
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(100)
  btisubpm1 => p__
  return
end
subroutine glrsetarraypointerbtisubpm2(p__, fobj__, dims__)
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(100)
  btisubpm2 => p__
  return
end
subroutine glrsetarraypointerbtisubpm3(p__, fobj__, dims__)
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(100)
  btisubpm3 => p__
  return
end
subroutine glrsetarraypointerjpzsubp(p__, fobj__, dims__)
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(100)
  jpzsubp => p__
  return
end
subroutine glrsetarraypointerjpzsubpm1(p__, fobj__, dims__)
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(100)
  jpzsubpm1 => p__
  return
end
subroutine glrsetarraypointerjpzsubpm2(p__, fobj__, dims__)
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(100)
  jpzsubpm2 => p__
  return
end
subroutine glrsetarraypointerjpzsubpm3(p__, fobj__, dims__)
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(100)
  jpzsubpm3 => p__
  return
end
subroutine glrsetarraypointerbj2old(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  bj2old => p__
  return
end
subroutine glrsetarraypointerpperpold(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  pperpold => p__
  return
end
subroutine glrsetarraypointerpperpold25(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  pperpold25 => p__
  return
end
subroutine glrsetarraypointerpparold(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  pparold => p__
  return
end
subroutine glrsetarraypointerbetaold(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  betaold => p__
  return
end
subroutine glrsetarraypointerqubold(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  qubold => p__
  return
end
subroutine glrsetarraypointerqubvold(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  qubvold => p__
  return
end
subroutine glrsetarraypointerdbdpsiold(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dbdpsiold => p__
  return
end
subroutine glrsetarraypointerdflute3(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dflute3 => p__
  return
end
subroutine glrsetarraypointerqubv(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  qubv => p__
  return
end
subroutine glrsetarraypointerp2(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  p2 => p__
  return
end
subroutine glrsetarraypointerdp2dpsi(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  dp2dpsi => p__
  return
end
subroutine glrsetarraypointerdflute1(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dflute1 => p__
  return
end
subroutine glrsetarraypointerdflute2(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dflute2 => p__
  return
end
subroutine glrsetarraypointerflute1(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  flute1 => p__
  return
end
subroutine glrsetarraypointerflute2(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  flute2 => p__
  return
end
subroutine glrsetarraypointerflute3(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  flute3 => p__
  return
end
subroutine glrsetarraypointerdpost1(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dpost1 => p__
  return
end
subroutine glrsetarraypointerdpost2(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dpost2 => p__
  return
end
subroutine glrsetarraypointerdpost1r(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dpost1r => p__
  return
end
subroutine glrsetarraypointerdpost2r(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dpost2r => p__
  return
end
subroutine glrsetarraypointerdpostjb(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dpostjb => p__
  return
end
subroutine glrsetarraypointerdpostjbo(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dpostjbo => p__
  return
end
subroutine glrsetarraypointerptot(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  ptot => p__
  return
end
subroutine glrsetarraypointerbeta(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  beta => p__
  return
end
subroutine glrsetarraypointerbetanorm(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  betanorm => p__
  return
end
subroutine glrsetarraypointerp2k(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ksimp,jx)
  p2k => p__
  return
end
subroutine glrsetarraypointerdeli5(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ksimp)
  deli5 => p__
  return
end
subroutine glrsetarraypointerdel1new(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ksimp)
  del1new => p__
  return
end
subroutine glrsetarraypointerdel2new(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ksimp)
  del2new => p__
  return
end
subroutine glrsetarraypointerdel3new(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ksimp)
  del3new => p__
  return
end
subroutine glrsetarraypointerdel5new(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ksimp)
  del5new => p__
  return
end
subroutine glrsetarraypointerpperps(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  pperps => p__
  return
end
subroutine glrsetarraypointererrprp(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  errprp => p__
  return
end
subroutine glrsetarraypointererrprl(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix-2,jx-1)
  errprl => p__
  return
end
subroutine glrsetarraypointerdqubdb(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  dqubdb => p__
  return
end
subroutine glrsetarraypointerxxxfreq(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  xxxfreq => p__
  return
end
subroutine glrsetarraypointerpperpe(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  pperpe => p__
  return
end
subroutine glrsetarraypointerepsi(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  epsi => p__
  return
end
subroutine glrsetarraypointeromeg1wkb(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  omeg1wkb => p__
  return
end
subroutine glrsetarraypointeromeg2wkb(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  omeg2wkb => p__
  return
end
subroutine glrsetarraypointergamwkb(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  gamwkb => p__
  return
end
subroutine glrsetarraypointerdflute4(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dflute4 => p__
  return
end
subroutine glrsetarraypointerrhoave(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  rhoave => p__
  return
end
subroutine glrsetarraypointerxxxave(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  xxxave => p__
  return
end
subroutine glrsetarraypointeryyyave(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  yyyave => p__
  return
end
subroutine glrsetarraypointerp2t(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  p2t => p__
  return
end
subroutine glrsetarraypointerdp2dpst(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  dp2dpst => p__
  return
end
subroutine glrsetarraypointerp3(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  p3 => p__
  return
end
subroutine glrsetarraypointerdp3dpsi(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  dp3dpsi => p__
  return
end
subroutine glrsetarraypointerhpkm(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ksimp)
  hpkm => p__
  return
end
subroutine glrsetarraypointerhpkme(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ksimp)
  hpkme => p__
  return
end
subroutine glrsetarraypointerdroave(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  droave => p__
  return
end
subroutine glrsetarraypointerdroterm(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  droterm => p__
  return
end
subroutine glrsetarraypointerering(p__, fobj__, dims__)
  use ArraySizes
  use Const_8
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  ering => p__
  return
end
subroutine glrsetarraypointerdrxi(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  drxi => p__
  return
end
subroutine glrsetarraypointerdrxio(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  drxio => p__
  return
end
subroutine glrsetarraypointerdrxr(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  drxr => p__
  return
end
subroutine glrsetarraypointerdrxro(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(ix,jx)
  drxro => p__
  return
end
subroutine glrsetarraypointerdxiz2(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dxiz2 => p__
  return
end
subroutine glrsetarraypointerdxrz2(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dxrz2 => p__
  return
end
subroutine glrsetarraypointerdum1(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dum1 => p__
  return
end
subroutine glrsetarraypointerdum2(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  dum2 => p__
  return
end
subroutine glrsetarraypointerpsuma(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(jx,12)
  psuma => p__
  return
end
subroutine glrsetarraypointerpsumb(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(jx,4)
  psumb => p__
  return
end
subroutine glrsetarraypointerrxi(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  rxi => p__
  return
end
subroutine glrsetarraypointerrxr(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(jx)
  rxr => p__
  return
end
subroutine glrsetarraypointerxig(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  xig => p__
  return
end
subroutine glrsetarraypointerxigo(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  xigo => p__
  return
end
subroutine glrsetarraypointerxrg(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  xrg => p__
  return
end
subroutine glrsetarraypointerxrgo(p__, fobj__, dims__)
  use ArraySizes
  use GEnergy
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(ix)
  xrgo => p__
  return
end
subroutine glrsetarraypointerrhs1b(p__, fobj__, dims__)
  use ArraySizes
  use Glrexec
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(kxx,1)
  rhs1b => p__
  return
end
subroutine glrsetarraypointerrhs2b(p__, fobj__, dims__)
  use ArraySizes
  use Glrexec
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(2)
  real(kind=8), target:: p__(kxx,1)
  rhs2b => p__
  return
end
subroutine glrsetarraypointerlsp(p__, fobj__, dims__)
  use Splines
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  integer(kind=8), target:: p__(mspout)
  lsp => p__
  return
end
subroutine glrsetarraypointerdsp(p__, fobj__, dims__)
  use Splines
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(mspout)
  dsp => p__
  return
end
subroutine glrsetarraypointercsp1(p__, fobj__, dims__)
  use Splines
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(mspin)
  csp1 => p__
  return
end
subroutine glrsetarraypointercsp2(p__, fobj__, dims__)
  use Splines
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(mspin)
  csp2 => p__
  return
end
subroutine glrsetarraypointercsp3(p__, fobj__, dims__)
  use Splines
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(mspin)
  csp3 => p__
  return
end
subroutine glrsetarraypointercsp4(p__, fobj__, dims__)
  use Splines
  integer(kind=8):: fobj__
  integer(kind=8):: dims__(1)
  real(kind=8), target:: p__(mspin)
  csp4 => p__
  return
end
