#include "Forthon.h"
#include <setjmp.h>
ForthonObject *glrObject;
extern jmp_buf stackenvironment;
extern int lstackenvironmentset;
extern void glrpasspointers_(void);
extern void glrnullifypointers_(void);
extern void glrgen_(void);
extern void glrexepy_(void);
extern void amat_(void);
extern void amax2_(double *a, long *im, long *jm, double *amax, long *imx, long *jmx);
extern void bcccal_(double *bs, double *zs, double *ass, double *als, double *z, long *n, double *bv, double *bvp, double *bvpp, double *b4, double *b5, double *z4, double *z5, long *nc);
extern void bvcal_(double *bs, double *zs, double *ass, double *als, double *z, long *n, double *zcc, double *bcc, double *znorm, double *bv, double *bvp, double *bvpp, double *b4, double *b5, double *z4, double *z5, long *nc);
extern void comat_(void);
extern void constant_(void);
extern void diagno_(void);
extern void ddpsi_(double *f1, double *f2, long *i);
extern void ddz_(double *f1, double *f2);
extern void dydx5_(double *x, double *y, long *n, double *yp1, double *ypn);
extern void energy_(void);
extern void equiltm_(void);
extern void errorend_(long *i, long *j);
extern void f1to11_(void);
extern void grid_(void);
extern void initial_(void);
extern void inputtm_(void);
extern void interp_(double *x, double *y, long *n, double *bc1, double *bcn, double *x2, double *y2, double *y2p, long *m);
extern void mymove_(double *a, double *b, long *len);
extern void rightvec_(void);
extern void simps_(double *fin, double *fout, long *knn, double *df);
extern void spline_(double *x, double *y, long *n, double *bc1, double *bcn, double *yp, double *ypp, double *yppp, double *yint);
extern void tmcon2_(void);

extern void glrsetarraypointerf1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerf2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerf3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerf4_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerf5_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerf7_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerg1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerg2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerg3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerg4_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrho_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerqub_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerr_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeryyy_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxxx_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxioo_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxio_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxiol_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxroo_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxro_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxrol_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeromstri1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeromgbi1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeromstri34_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeromstri66_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeromstr148_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeromebj1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeromstrj1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeripvt_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointera1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointera2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointera3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerb1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbc_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrhs1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrhs2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerabar_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerass_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerals_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerzs_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbs_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeribvmin_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeribvmax_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerpsi_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeru_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerv_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdpsi_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointervpsi_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeruuz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointervpsih_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeruuzh_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxrtime_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxrspz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxrsppsi_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointertime_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxflute_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerenpot_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointertenergy_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerenkin_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointertimengy_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointertenrel_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerenbend_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerencurve_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerenflr_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerh12_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhzt0_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerh34_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerabp_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbbp_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointercbp_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerabf_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbbf_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointercbf_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhp3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhtrans_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerabq_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbbq_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointercbq_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerebp_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerfbp_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointergbp_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhp0_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhpm_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhpme_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhflr_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhzp0_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhzp1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhzp2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhzp3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhzt1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhzt2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhzt3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhzt2ks_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhzt3ks_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdterjb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbvac_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdbvdz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerd2bvdz2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerd3bvdz3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbint_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdp1dpsi_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerp1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerp1k_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhpk0_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdeli1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdeli2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdeli3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdeli4_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrzz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrzz1a_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrzz1b_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrzz2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrzz3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrzz1anew_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrzz1bnew_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrzz2new_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrzz3new_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrzznew_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrzzold_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrd2diff_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrnew_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrnewd2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrold_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerroldd2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointericapi2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointericapi3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointericapi5_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointericap2new_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointericap3new_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointericap5new_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdbdpsi_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerphi1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerphi2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerpperp_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerppar_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjperpz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjperpb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjparb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjdfb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjd2fb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerddbparb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerddbprpb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjperpbpg_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjparbpg_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjdfbpg_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjd2fbpg_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerddbparbpg_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerddbprpbpg_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjparz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjd2fz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjdfz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjbtotz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjmbselfz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerddbprpz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerddbparz_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerposh_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointernosh_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbvacnorm_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbti82_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbtisubp_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbtisubpm1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbtisubpm2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbtisubpm3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjpzsubp_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjpzsubpm1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjpzsubpm2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerjpzsubpm3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbj2old_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerpperpold_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerpperpold25_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerpparold_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbetaold_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerqubold_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerqubvold_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdbdpsiold_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdflute3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerqubv_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerp2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdp2dpsi_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdflute1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdflute2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerflute1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerflute2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerflute3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdpost1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdpost2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdpost1r_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdpost2r_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdpostjb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdpostjbo_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerptot_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbeta_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbetanorm_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerp2k_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdeli5_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdel1new_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdel2new_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdel3new_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdel5new_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerpperps_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointererrprp_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointererrprl_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdqubdb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxxxfreq_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerpperpe_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerepsi_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeromeg1wkb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeromeg2wkb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointergamwkb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdflute4_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrhoave_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxxxave_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointeryyyave_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerp2t_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdp2dpst_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerp3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdp3dpsi_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhpkm_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerhpkme_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdroave_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdroterm_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerering_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdrxi_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdrxio_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdrxr_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdrxro_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdxiz2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdxrz2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdum1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdum2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerpsuma_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerpsumb_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerquad_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerquad1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrxi_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrxr_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxig_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxigo_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxrg_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerxrgo_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrhs1b_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerrhs2b_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerlsp_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerdsp_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointercsp1_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointercsp2_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointercsp3_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointercsp4_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerzks_(char *p__, char *fobj__, npy_intp *dims__);
extern void glrsetarraypointerbks_(char *p__, char *fobj__, npy_intp *dims__);

int glrnscalars = 267;
Fortranscalar glr_fscalars[267]={
{NPY_LONG,"integer","ix",NULL,"ArraySizes"," ArraySizes input ","Number of axial grid points.","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","jx",NULL,"ArraySizes"," ArraySizes input ","Number of radial (psi) grid points.","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","npob",NULL,"ArraySizes"," ArraySizes input ","Number of p(B) points.","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","ksimp",NULL,"ArraySizes"," ArraySizes input ","Number of points for Simpson's Rule integration.","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","nmax",NULL,"ArraySizes"," ArraySizes input ","Upper limit of time steps for problem.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","nps",NULL,"ArraySizes"," ArraySizes input ","?","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","neng",NULL,"ArraySizes"," ArraySizes input ","?","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","kxx",NULL,"ArraySizes"," ArraySizes ","Secondary array size, kxx=(ix-2)*(jx-2).","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","kbw",NULL,"ArraySizes"," ArraySizes ","Secondary array size, kbw=min(ix-1,jx-1).","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","lda",NULL,"ArraySizes"," ArraySizes ","Secondary array size, lda=3*kbw+1.","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","swg1",NULL,"Fstor"," Fstor input ","Arbitrary scaling factor on curvature-drive term.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","swg2",NULL,"Fstor"," Fstor input ","Arbitrary scaling factor on some of the line-bending terms.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","swg3",NULL,"Fstor"," Fstor input ","Arbitrary scaling factor on some of the line-bending terms.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","swg4",NULL,"Fstor"," Fstor input ","Arbitrary scaling factor on some of the line-bending terms.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","exbratio",NULL,"Fstor"," Fstor input ","omegexb = exbratio*omegstr.","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","alfrigid",NULL,"Fstor"," Fstor input ","larger for faster decay rigidrotor dpdpsi/p\n##ibksinit\tinteger\t/79/\t\t[none]\t\t+input\nIndex in z marking start of KS pressure","?",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","isubp",NULL,"Fstor"," Fstor input ","Index in z marking end of KS pressure","none",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","alfsubp",NULL,"Fstor"," Fstor ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"logical","dosubp",NULL,"Fstor"," Fstor ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"logical","doflat",NULL,"Fstor"," Fstor input ","?","flag",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"logical","doxrlin",NULL,"Fstor"," Fstor input ","?","flag",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"logical","doxrtanh",NULL,"Fstor"," Fstor input ","","flag",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"logical","dowriteb",NULL,"Fstor"," Fstor ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"logical","dorzzlb",NULL,"Fstor"," Fstor input ","?","flag",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"logical","doplugpob",NULL,"Fstor"," Fstor input ","if true iterate in plug for bt,jperpz in pob2poz","flag",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","iscreen",NULL,"Const_1a"," Const_1a input ","Tells how often to write timestep+ to screen.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","mm",NULL,"Const_1a"," Const_1a input ","Azimuthal mode number.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","lmax",NULL,"Const_1a"," Const_1a input ","Iteration limit.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","isw",NULL,"Const_1a"," Const_1a ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","ndiag",NULL,"Const_1a"," Const_1a input ","Number of time steps between diagnostic plots.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","kplot",NULL,"Const_1a"," Const_1a ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","npm",NULL,"Const_1a"," Const_1a ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","kplotm",NULL,"Const_1a"," Const_1a input ","Index of spatial location of time history plots, if ==0, center of\nregion is used.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","kzs",NULL,"Const_1a"," Const_1a input ","Flute mode initialization, ==1 & ex0==1 & ex1==1 sets initial\ncondition r B xro=0 and and r B xio=0.","flag",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","n",NULL,"Const_1a"," Const_1a ","Time loop counter.","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","ltt",NULL,"Const_1a"," Const_1a ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","nen",NULL,"Const_1a"," Const_1a input ","Number of time steps between energy checks.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","lee",NULL,"Const_1a"," Const_1a ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","startime",NULL,"Const_1"," Const_1 ","Initial value from 'call second' (Cray).","sec. CPU",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","endtime",NULL,"Const_1"," Const_1 ","Final value from 'call second' (Cray).","sec. CPU",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","totalcpu",NULL,"Const_1"," Const_1 ","Total timeloop CPU from 'call second' (Cray/Sun)","sec. CPU",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","t",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","gam1",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","gam2",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","fac1",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","fac2",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bias",NULL,"Const_1"," Const_1 input ","Time centering parameter, ==0 fully centered, ==1 fully forward bias.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","du",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","dv",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","dt",NULL,"Const_1"," Const_1 input ","Time step.","s",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ex0",NULL,"Const_1"," Const_1 input ","Initial perturbation coefficient, ==1 random perturbation.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ex1",NULL,"Const_1"," Const_1 input ","Initial perturbation coefficient, ==1 for cosine cosine distribution.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","fi1",NULL,"Const_1"," Const_1 input ","Minimum z boundary condition, ==1 for 0 slope, ==-1 for 0 value.","flag",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","fizx",NULL,"Const_1"," Const_1 input ","Maximum z boundary condition, ==1 for 0 slope, ==-1 for 0 value.","flag",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","fj1",NULL,"Const_1"," Const_1 input ","Minimum psi boundary condition, ==1 for 0 slope, ==-1 for 0 value;\nFor fj1==0, mm==1 results in 0 slope, mm>=2 results in 0 value.","flag",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","fjrx",NULL,"Const_1"," Const_1 input ","Maximum psi boundary condition, ==1 for 0 slope, ==-1 for 0 value.","flag",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","fpsi",NULL,"Const_1"," Const_1 input ","Grid stretching parameter [0,1].","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","fu",NULL,"Const_1"," Const_1 input ","Grid stretching parameter [0,1].","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","fv",NULL,"Const_1"," Const_1 input ","Grid stretching parameter [0,1].","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","fz",NULL,"Const_1"," Const_1 input ","Grid stretching parameter [0,1].g","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","azm",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","apsim",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","u0",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","v0",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","amass",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","omegexb",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","sf6",NULL,"Const_1"," Const_1 input ","Arbitrary scaling factor on gyroscopic FLR term xxx.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","sf8",NULL,"Const_1"," Const_1 input ","Arbitrary scaling factor on quasi-elastic FLR term yyy.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","zedge",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","xu",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","xv",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","vw",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psiw",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","dvin",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","dvout",NULL,"Const_1"," Const_1 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psi0rel",NULL,"Const_2"," Const_2 input ","Psi value relative to psimax at which ion radial pressure is half the\nmaximum.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z1rel",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z2rel",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z3rel",NULL,"Const_2"," Const_2 input ","Outer axial position where hot electrons go to zero (pring=0).","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z0rel",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","nslosh",NULL,"Const_2"," Const_2 ","Peak sloshing ion number density.","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","nsloshks",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bmg",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ncenter",NULL,"Const_2"," Const_2 input ","Center cell density.","1/cm^3",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","pslosh",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psloshks",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","pcenter",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ztrans",NULL,"Const_2"," Const_2 input ","Z position normalized to zmax to middle of center cell field\ntransition region.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ltrans",NULL,"Const_2"," Const_2 input ","Scale length, normalized to zmax, for center cell vacuum field\ntransition region.g","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bm",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ltran",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ztran",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","rp1",NULL,"Const_2"," Const_2 input ","Mirror ratio of the inner component of the sloshing profile\n(UCID-20400, Sect. 6).","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","rp1ks",NULL,"Const_2"," Const_2 input ","Mirror ratio of inner comp of KS sloshing profile.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bcen",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","pring",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","epsp",NULL,"Const_2"," Const_2 input ","Approximately the minimum pressure (normalized to 1), below which B\nis calculated by an expansion (UCID-20400, Sect. 3).","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","phicen",NULL,"Const_2"," Const_2 input ","Maximum center cell potential relative to plug ion tperp.","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","phiplg",NULL,"Const_2"," Const_2 input ","Maximum plug potential relative to plug ion tperp.","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","xpot",NULL,"Const_2"," Const_2 input ","Exponent coefficient in center cell potential.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ypot",NULL,"Const_2"," Const_2 input ","Power of polynomial in potential psi dependence.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","wpot",NULL,"Const_2"," Const_2 input ","Exponent coefficient in end plug cell potential.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","pfudge",NULL,"Const_2"," Const_2 input ","Parameter on sloshing shape.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","pfudgeks",NULL,"Const_2"," Const_2 input ","?","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","rpx",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","rpxks",NULL,"Const_2"," Const_2 input ","?","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","phice",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","phipl",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","betslsh",NULL,"Const_2"," Const_2 input ","Peak sloshing ion perpendicular beta, wrt bmn2.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","betslsks",NULL,"Const_2"," Const_2 input ","Peak KS sloshing ion perpendicular beta, wrt bmn2.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","betcent",NULL,"Const_2"," Const_2 input ","Peak center cell ion perpendicular beta, ert bv0.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z0",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z1",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z2",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z3",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psi0",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","betcene",NULL,"Const_2"," Const_2 input ","Peak center cell electron perpendicular beta, wrt bv0.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","betslse",NULL,"Const_2"," Const_2 input ","Peak warn sloshing electron perpendicular beta, wrt bmn2.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psloshe",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","pcentee",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bmax",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","alsi",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","alsiks",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bm1",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bm1ks",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bvoutks",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psls1",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","cold",NULL,"Const_2"," Const_2 input ","Global density minimum as fraction of ncenter.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","alfcold",NULL,"Const_2"," Const_2 input ","exp(-alfcold(JRX-j)) psivariable model alf 1.->.1","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p2wide",NULL,"Const_2"," Const_2 input ","Parameter inversely proportional to ramp width of p2t in the ion\nradial pressure profile (UCID-20400, Sect. 8).\nion radial pressure profile","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psi3rel",NULL,"Const_2"," Const_2 input ","Psi value relative to psimax where electric field=0.","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psi3",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p1max",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bv0",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bv3",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bceng",NULL,"Const_2"," Const_2 input ","Center cell magnetic field.","G",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psloshin",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","poshinks",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psloshen",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","nsloshin",NULL,"Const_2"," Const_2 input ","Peak plug cell density.","1/cm^3",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","noshinks",NULL,"Const_2"," Const_2 input ","?","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p3a",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p3b",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p3c",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p3d",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psim",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","pe10",NULL,"Const_2"," Const_2 input ","Coefficient of hot electron radial pressure profile (UCID-20400,\nSect. 8)","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ae1",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","be1",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ce1",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","de1",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psi0erel",NULL,"Const_2"," Const_2 input ","Psi value relative to psimax at which hot electron radial pressure is\nhalf the maximum (eringpperp(pe2)=halfmax).","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psi0e",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psime",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p2ewide",NULL,"Const_2"," Const_2 input ","Parameter inversely proportional to ramp width of p2e in the hot\nelectron radial pressure profile (UCID-20400, Sect. 8).","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","wp2e",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p1floor",NULL,"Const_2"," Const_2 input ","Value to which p1 is set if p2 <= p2flag.","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p2flag",NULL,"Const_2"," Const_2 input ","Value of p2 at which p1 and p2 are set constant.","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p2floor",NULL,"Const_2"," Const_2 input ","Value to which p2 is set if p2 <= p2flag.","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","fring",NULL,"Const_2"," Const_2 input ","Used for elongated hot electrons (UCID-20400, Sect. A.3).","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","dip",NULL,"Const_2"," Const_2 input ","Parameter in psi pressure profile (UCID-20400, Sect. 8).","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psistr",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psislp",NULL,"Const_2"," Const_2 input ","Coefficient of pe1 (UCID-20400, Sect. 8).","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psihrel",NULL,"Const_2"," Const_2 input ","Psi value relative to psimax of halo.","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","psih",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","dpsihrel",NULL,"Const_2"," Const_2 input ","Psi width relative to psimax of transition to halo region.","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","dpsih",NULL,"Const_2"," Const_2 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","ncoil",NULL,"Coils"," Coils input ","Number of solenoids (also regions).","none",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z1c",NULL,"Coils"," Coils input ","Axial position of choke coil.","cm",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z2c",NULL,"Coils"," Coils input ","Axial position of end plug inboard mirror coil.","cm",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z3c",NULL,"Coils"," Coils input ","Axial position of end plug outboard mirror coil.","cm",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","nregions",NULL,"GFiducials"," GFiducials ","Number of regions","none",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","at0",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bt0",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ct0",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","cp0",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ap1",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ap2",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ap3",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","at1",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","at2",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","at3",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bp1",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bp2",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bp3",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bt1",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bt2",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bt3",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","cp1",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","cp2",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","cp3",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ct1",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ct2",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ct3",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ct2ks",NULL,"Const_3"," Const_3 ","Mimic ct2 for outer kinetic stabilizer sloshing .","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ct3ks",NULL,"Const_3"," Const_3 ","Mimic ct3 for outer kinetic stabilizer sloshing.","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bmx1",NULL,"Const_3"," Const_3 input ","Magnetic field at choke coil solenoid (UCID-20400, Sect. 3).","G",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bmx2",NULL,"Const_3"," Const_3 input ","Magnetic field at inboard end plug solenoid (UCID-20400, Sect. 3).","G",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bmx3",NULL,"Const_3"," Const_3 input ","Magnetic field at outer end plug solenoid (UCID-20400, Sect. 3).","G",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bmn1",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bmn2",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ppas1",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ppas2",NULL,"Const_3"," Const_3 input ","Minimum passing pressure in choke cell, fraction of ppas1\n(UCID-20400, Sect. 7).","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","ppas3",NULL,"Const_3"," Const_3 input ","Maximum passing pressure at inboard mirror of end plug cell.","?",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p1trap",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z1min",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z2min",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","dpas1",NULL,"Const_3"," Const_3 input ","Center cell passing density.","1/cm^3",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","d1trap",NULL,"Const_3"," Const_3 input ","Peak density in choke cell.","1/cm^3",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","betrap",NULL,"Const_3"," Const_3 input ","Peak choke cell perpendicular beta.","none",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","betpas1",NULL,"Const_3"," Const_3 input ","Center cell passing beta.","none",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bvx2",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bvx3",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","z2ct",NULL,"Const_3"," Const_3 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","lb",NULL,"Const_6"," Const_6 ","With doflat==true for fixed curv rzz =-r/lb^2","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","rw",NULL,"Const_6"," Const_6 input ","Wall radius.","cm",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","cee",NULL,"Const_6"," Const_6 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","betring",NULL,"Const_7"," Const_7 input ","Peak hot electron perpendicular beta, wrt bmn1.","none",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bvmaxp",NULL,"Const_8"," Const_8 input ","maxb for jperpz (previously hardwired to 20)","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bvmaxpg",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bvadj",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","alfpg",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","alfks",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","delsubp",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","post1",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","post2",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","post1r",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","post2r",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","postjb",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","post1sum",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","post2sum",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","postjbsum",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","postjbsumo",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","post1cc",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","post2cc",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","postjbcc",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","post1pg",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","post2pg",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","postjbpg",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","post1ks",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","post2ks",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","postjbks",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p1kssubp",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p1ksmax",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","p2ksmax",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","pjbksmax",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","pjbksmaxo",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","pnorm",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","pperpinj",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","btksinj",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","pparinj",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","pperpinjo",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","btksinjo",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","grow",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","growmax",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","xfreqmax",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","rzzrmax",NULL,"Const_8"," Const_8 ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","long",NULL,"TMInput"," TMInput input ","Switch which sets hot electron z-length as elongated (long==1) or\nregular (long==0).","dimensionless",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","rw1",NULL,"TMInput"," TMInput input ","Equal, or slightly less (within one grid cell), to rw, if zero, gets\nset to rw.","cm",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","zmax",NULL,"TMInput"," TMInput input ","Maximum z of the domain.","cm",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","info",NULL,"TMInput"," TMInput ","Returned by dgbtrf and dgbtrs.","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","bsub",NULL,"TMInput"," TMInput ","Value subtracted from bvac.","",0,0,NULL,NULL,NULL,NULL},
{NPY_DOUBLE,"real","frbvac",NULL,"TMInput"," TMInput ","Allowed range is 0. to 1.-delta.","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"logical","dobvsub",NULL,"TMInput"," TMInput ","If true, subtract frbvac*bvac(ix).","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","mspin",NULL,"Splines"," Splines ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","mspout",NULL,"Splines"," Splines ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","nks",NULL,"Btable"," Btable input ","Number of points in imported B in KS region","",0,0,NULL,NULL,NULL,NULL}};
int glrnarrays = 253;
static Fortranarray glr_farrays[253]={
{NPY_DOUBLE,1,2,NULL,"f1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"f2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"f3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"f4",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"f5",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"f7",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"g1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"g2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"g3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"g4",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"b",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"rho",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"qub",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"r",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"yyy",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"xxx",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix,jx)"},
{NPY_DOUBLE,1,1,NULL,"xioo",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(kxx)"},
{NPY_DOUBLE,1,1,NULL,"xio",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(kxx)"},
{NPY_DOUBLE,1,1,NULL,"xiol",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(kxx)"},
{NPY_DOUBLE,1,1,NULL,"xroo",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(kxx)"},
{NPY_DOUBLE,1,1,NULL,"xro",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(kxx)"},
{NPY_DOUBLE,1,1,NULL,"xrol",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(kxx)"},
{NPY_DOUBLE,1,1,NULL,"omstri1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"omgbi1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"omstri34",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"omstri66",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"omstr148",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"omebj1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"omstrj1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Fstor"," Fstor ","","","(ix)"},
{NPY_LONG,1,1,NULL,"ipvt",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Matrix"," Matrix ","","","(kxx)"},
{NPY_DOUBLE,1,2,NULL,"a1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Matrix"," Matrix ","","","(kxx,9)"},
{NPY_DOUBLE,1,2,NULL,"a2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Matrix"," Matrix ","","","(kxx,9)"},
{NPY_DOUBLE,1,2,NULL,"a3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Matrix"," Matrix ","","","(kxx,9)"},
{NPY_DOUBLE,1,2,NULL,"b1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Matrix"," Matrix ","","","(kxx,3)"},
{NPY_DOUBLE,1,1,NULL,"bc",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Matrix"," Matrix ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"rhs1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Matrix"," Matrix ","","","(kxx)"},
{NPY_DOUBLE,1,1,NULL,"rhs2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Matrix"," Matrix ","","","(kxx)"},
{NPY_DOUBLE,1,2,NULL,"abar",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Matrix"," Matrix ","","","(lda,kxx)"},
{NPY_DOUBLE,0,1,NULL,"ass",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Coils"," Coils input ","Solenoid radius.","cm","(3)"},
{NPY_DOUBLE,0,1,NULL,"als",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Coils"," Coils input ","Solenoid coil length.","cm","(3)"},
{NPY_DOUBLE,0,1,NULL,"zs",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Coils"," Coils ","","","(3)"},
{NPY_DOUBLE,0,1,NULL,"bs",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Coils"," Coils ","","","(3)"},
{NPY_LONG,0,1,NULL,"ibvmin",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GFiducials"," GFiducials ","Indices of B minima in z","none","(3)"},
{NPY_LONG,0,1,NULL,"ibvmax",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GFiducials"," GFiducials ","Indices of B maxima in z","none","(3)"},
{NPY_DOUBLE,1,1,NULL,"psi",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_4"," Const_4 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"z",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_4"," Const_4 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"u",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_4"," Const_4 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"v",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_4"," Const_4 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"dpsi",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_4"," Const_4 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"dz",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_4"," Const_4 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"vpsi",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_4"," Const_4 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"uuz",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_4"," Const_4 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"vpsih",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_4"," Const_4 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"uuzh",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_4"," Const_4 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"xrtime",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_5"," Const_5 ","","","(nmax)"},
{NPY_DOUBLE,1,2,NULL,"xrspz",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_5"," Const_5 ","","","(ix,nps)"},
{NPY_DOUBLE,1,2,NULL,"xrsppsi",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_5"," Const_5 ","","","(jx,2*nps)"},
{NPY_DOUBLE,1,1,NULL,"time",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_5"," Const_5 ","","","(nmax)"},
{NPY_DOUBLE,1,2,NULL,"xflute",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_5"," Const_5 ","","","(ix,nps)"},
{NPY_DOUBLE,1,1,NULL,"enpot",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_5"," Const_5 ","","","(neng)"},
{NPY_DOUBLE,1,1,NULL,"tenergy",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_5"," Const_5 ","","","(neng)"},
{NPY_DOUBLE,1,1,NULL,"enkin",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_5"," Const_5 ","","","(neng)"},
{NPY_DOUBLE,1,1,NULL,"timengy",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_5"," Const_5 ","","","(neng)"},
{NPY_DOUBLE,1,1,NULL,"tenrel",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_5"," Const_5 ","","","(neng)"},
{NPY_DOUBLE,1,1,NULL,"enbend",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_5"," Const_5 ","","","(neng)"},
{NPY_DOUBLE,1,1,NULL,"encurve",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_5"," Const_5 ","","","(neng)"},
{NPY_DOUBLE,1,1,NULL,"enflr",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_5"," Const_5 ","","","(neng)"},
{NPY_DOUBLE,1,1,NULL,"h12",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"hzt0",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"h34",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"abp",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"bbp",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"cbp",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"abf",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"bbf",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"cbf",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"hp3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"htrans",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"abq",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"bbq",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"cbq",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"ebp",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"fbp",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"gbp",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"hp0",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"hpm",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"hpme",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"hflr",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"hzp0",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"hzp1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"hzp2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"hzp3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"hzt1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"hzt2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"hzt3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"hzt2ks",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"hzt3ks",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dterjb",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_7"," Const_7 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"bvac",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dbvdz",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"d2bvdz2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"d3bvdz3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"bint",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dp1dpsi",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"p1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,2,NULL,"p1k",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp,jx)"},
{NPY_DOUBLE,1,1,NULL,"hpk0",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp)"},
{NPY_DOUBLE,1,1,NULL,"deli1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp)"},
{NPY_DOUBLE,1,1,NULL,"deli2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp)"},
{NPY_DOUBLE,1,1,NULL,"deli3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp)"},
{NPY_DOUBLE,1,1,NULL,"deli4",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp)"},
{NPY_DOUBLE,1,2,NULL,"rzz",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix,jx)"},
{NPY_DOUBLE,1,1,NULL,"rzz1a",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rzz1b",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rzz2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rzz3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rzz1anew",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rzz1bnew",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rzz2new",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rzz3new",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rzznew",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rzzold",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rd2diff",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rnew",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rnewd2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rold",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"roldd2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"icapi2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"icapi3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"icapi5",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"icap2new",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"icap3new",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"icap5new",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,2,NULL,"dbdpsi",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix,jx)"},
{NPY_DOUBLE,1,1,NULL,"phi1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"phi2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,2,NULL,"pperp",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"ppar",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix,jx)"},
{NPY_DOUBLE,1,1,NULL,"jperpz",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,0,1,NULL,"jperpb",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(1000)"},
{NPY_DOUBLE,0,1,NULL,"jparb",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(1000)"},
{NPY_DOUBLE,0,1,NULL,"jdfb",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(1000)"},
{NPY_DOUBLE,0,1,NULL,"jd2fb",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(1000)"},
{NPY_DOUBLE,0,1,NULL,"ddbparb",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(1000)"},
{NPY_DOUBLE,0,1,NULL,"ddbprpb",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(1000)"},
{NPY_DOUBLE,0,1,NULL,"jperpbpg",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(1000)"},
{NPY_DOUBLE,0,1,NULL,"jparbpg",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(1000)"},
{NPY_DOUBLE,0,1,NULL,"jdfbpg",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(1000)"},
{NPY_DOUBLE,0,1,NULL,"jd2fbpg",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(1000)"},
{NPY_DOUBLE,0,1,NULL,"ddbparbpg",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(1000)"},
{NPY_DOUBLE,0,1,NULL,"ddbprpbpg",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(1000)"},
{NPY_DOUBLE,1,1,NULL,"jparz",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"jd2fz",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"jdfz",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"jbtotz",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"jmbselfz",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"ddbprpz",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"ddbparz",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"posh",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"nosh",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"bvacnorm",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"bti82",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(100)"},
{NPY_DOUBLE,1,1,NULL,"btisubp",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(100)"},
{NPY_DOUBLE,1,1,NULL,"btisubpm1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(100)"},
{NPY_DOUBLE,1,1,NULL,"btisubpm2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(100)"},
{NPY_DOUBLE,1,1,NULL,"btisubpm3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(100)"},
{NPY_DOUBLE,1,1,NULL,"jpzsubp",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(100)"},
{NPY_DOUBLE,1,1,NULL,"jpzsubpm1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(100)"},
{NPY_DOUBLE,1,1,NULL,"jpzsubpm2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(100)"},
{NPY_DOUBLE,1,1,NULL,"jpzsubpm3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(100)"},
{NPY_DOUBLE,1,1,NULL,"bj2old",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"pperpold",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"pperpold25",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"pparold",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"betaold",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"qubold",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"qubvold",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dbdpsiold",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dflute3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,2,NULL,"qubv",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix,jx)"},
{NPY_DOUBLE,1,1,NULL,"p2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"dp2dpsi",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"dflute1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dflute2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"flute1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"flute2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"flute3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"dpost1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dpost2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dpost1r",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dpost2r",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dpostjb",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dpostjbo",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"ptot",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"beta",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"betanorm",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,2,NULL,"p2k",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp,jx)"},
{NPY_DOUBLE,1,1,NULL,"deli5",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp)"},
{NPY_DOUBLE,1,1,NULL,"del1new",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp)"},
{NPY_DOUBLE,1,1,NULL,"del2new",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp)"},
{NPY_DOUBLE,1,1,NULL,"del3new",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp)"},
{NPY_DOUBLE,1,1,NULL,"del5new",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp)"},
{NPY_DOUBLE,1,2,NULL,"pperps",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"errprp",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"errprl",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix-2,jx-1)"},
{NPY_DOUBLE,1,2,NULL,"dqubdb",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix,jx)"},
{NPY_DOUBLE,1,1,NULL,"xxxfreq",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,2,NULL,"pperpe",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"epsi",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix,jx)"},
{NPY_DOUBLE,1,1,NULL,"omeg1wkb",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"omeg2wkb",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"gamwkb",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"dflute4",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"rhoave",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"xxxave",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"yyyave",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"p2t",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"dp2dpst",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"p3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"dp3dpsi",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"hpkm",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp)"},
{NPY_DOUBLE,1,1,NULL,"hpkme",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ksimp)"},
{NPY_DOUBLE,1,1,NULL,"droave",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"droterm",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix)"},
{NPY_DOUBLE,1,2,NULL,"ering",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Const_8"," Const_8 ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"drxi",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"drxio",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"drxr",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(ix,jx)"},
{NPY_DOUBLE,1,2,NULL,"drxro",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(ix,jx)"},
{NPY_DOUBLE,1,1,NULL,"dxiz2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dxrz2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dum1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"dum2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(ix)"},
{NPY_DOUBLE,1,2,NULL,"psuma",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(jx,12)"},
{NPY_DOUBLE,1,2,NULL,"psumb",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(jx,4)"},
{NPY_DOUBLE,0,1,NULL,"quad",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(12)"},
{NPY_DOUBLE,0,1,NULL,"quad1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(4)"},
{NPY_DOUBLE,1,1,NULL,"rxi",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"rxr",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(jx)"},
{NPY_DOUBLE,1,1,NULL,"xig",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"xigo",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"xrg",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(ix)"},
{NPY_DOUBLE,1,1,NULL,"xrgo",{NULL},NULL,NULL,NULL,NULL,0,NULL,"GEnergy"," GEnergy ","","","(ix)"},
{NPY_DOUBLE,1,2,NULL,"rhs1b",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Glrexec"," Glrexec ","","","(kxx,1)"},
{NPY_DOUBLE,1,2,NULL,"rhs2b",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Glrexec"," Glrexec ","","","(kxx,1)"},
{NPY_LONG,1,1,NULL,"lsp",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Splines"," Splines ","","","(mspout)"},
{NPY_DOUBLE,1,1,NULL,"dsp",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Splines"," Splines ","","","(mspout)"},
{NPY_DOUBLE,1,1,NULL,"csp1",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Splines"," Splines ","","","(mspin)"},
{NPY_DOUBLE,1,1,NULL,"csp2",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Splines"," Splines ","","","(mspin)"},
{NPY_DOUBLE,1,1,NULL,"csp3",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Splines"," Splines ","","","(mspin)"},
{NPY_DOUBLE,1,1,NULL,"csp4",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Splines"," Splines ","","","(mspin)"},
{NPY_DOUBLE,0,1,NULL,"zks",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Btable"," Btable input ","Z positions for imported B(z) in KS region","cm","(1000)"},
{NPY_DOUBLE,0,1,NULL,"bks",{NULL},NULL,NULL,NULL,NULL,0,NULL,"Btable"," Btable input ","B at zks for imported B(z) in KS region","dimensionless","(1000)"}};
void glrdeclarevars(ForthonObject *obj) {
obj->farrays[0].setarraypointer = *glrsetarraypointerf1_;
obj->farrays[1].setarraypointer = *glrsetarraypointerf2_;
obj->farrays[2].setarraypointer = *glrsetarraypointerf3_;
obj->farrays[3].setarraypointer = *glrsetarraypointerf4_;
obj->farrays[4].setarraypointer = *glrsetarraypointerf5_;
obj->farrays[5].setarraypointer = *glrsetarraypointerf7_;
obj->farrays[6].setarraypointer = *glrsetarraypointerg1_;
obj->farrays[7].setarraypointer = *glrsetarraypointerg2_;
obj->farrays[8].setarraypointer = *glrsetarraypointerg3_;
obj->farrays[9].setarraypointer = *glrsetarraypointerg4_;
obj->farrays[10].setarraypointer = *glrsetarraypointerb_;
obj->farrays[11].setarraypointer = *glrsetarraypointerrho_;
obj->farrays[12].setarraypointer = *glrsetarraypointerqub_;
obj->farrays[13].setarraypointer = *glrsetarraypointerr_;
obj->farrays[14].setarraypointer = *glrsetarraypointeryyy_;
obj->farrays[15].setarraypointer = *glrsetarraypointerxxx_;
obj->farrays[16].setarraypointer = *glrsetarraypointerxioo_;
obj->farrays[17].setarraypointer = *glrsetarraypointerxio_;
obj->farrays[18].setarraypointer = *glrsetarraypointerxiol_;
obj->farrays[19].setarraypointer = *glrsetarraypointerxroo_;
obj->farrays[20].setarraypointer = *glrsetarraypointerxro_;
obj->farrays[21].setarraypointer = *glrsetarraypointerxrol_;
obj->farrays[22].setarraypointer = *glrsetarraypointeromstri1_;
obj->farrays[23].setarraypointer = *glrsetarraypointeromgbi1_;
obj->farrays[24].setarraypointer = *glrsetarraypointeromstri34_;
obj->farrays[25].setarraypointer = *glrsetarraypointeromstri66_;
obj->farrays[26].setarraypointer = *glrsetarraypointeromstr148_;
obj->farrays[27].setarraypointer = *glrsetarraypointeromebj1_;
obj->farrays[28].setarraypointer = *glrsetarraypointeromstrj1_;
obj->farrays[29].setarraypointer = *glrsetarraypointeripvt_;
obj->farrays[30].setarraypointer = *glrsetarraypointera1_;
obj->farrays[31].setarraypointer = *glrsetarraypointera2_;
obj->farrays[32].setarraypointer = *glrsetarraypointera3_;
obj->farrays[33].setarraypointer = *glrsetarraypointerb1_;
obj->farrays[34].setarraypointer = *glrsetarraypointerbc_;
obj->farrays[35].setarraypointer = *glrsetarraypointerrhs1_;
obj->farrays[36].setarraypointer = *glrsetarraypointerrhs2_;
obj->farrays[37].setarraypointer = *glrsetarraypointerabar_;
obj->farrays[44].setarraypointer = *glrsetarraypointerpsi_;
obj->farrays[45].setarraypointer = *glrsetarraypointerz_;
obj->farrays[46].setarraypointer = *glrsetarraypointeru_;
obj->farrays[47].setarraypointer = *glrsetarraypointerv_;
obj->farrays[48].setarraypointer = *glrsetarraypointerdpsi_;
obj->farrays[49].setarraypointer = *glrsetarraypointerdz_;
obj->farrays[50].setarraypointer = *glrsetarraypointervpsi_;
obj->farrays[51].setarraypointer = *glrsetarraypointeruuz_;
obj->farrays[52].setarraypointer = *glrsetarraypointervpsih_;
obj->farrays[53].setarraypointer = *glrsetarraypointeruuzh_;
obj->farrays[54].setarraypointer = *glrsetarraypointerxrtime_;
obj->farrays[55].setarraypointer = *glrsetarraypointerxrspz_;
obj->farrays[56].setarraypointer = *glrsetarraypointerxrsppsi_;
obj->farrays[57].setarraypointer = *glrsetarraypointertime_;
obj->farrays[58].setarraypointer = *glrsetarraypointerxflute_;
obj->farrays[59].setarraypointer = *glrsetarraypointerenpot_;
obj->farrays[60].setarraypointer = *glrsetarraypointertenergy_;
obj->farrays[61].setarraypointer = *glrsetarraypointerenkin_;
obj->farrays[62].setarraypointer = *glrsetarraypointertimengy_;
obj->farrays[63].setarraypointer = *glrsetarraypointertenrel_;
obj->farrays[64].setarraypointer = *glrsetarraypointerenbend_;
obj->farrays[65].setarraypointer = *glrsetarraypointerencurve_;
obj->farrays[66].setarraypointer = *glrsetarraypointerenflr_;
obj->farrays[67].setarraypointer = *glrsetarraypointerh12_;
obj->farrays[68].setarraypointer = *glrsetarraypointerhzt0_;
obj->farrays[69].setarraypointer = *glrsetarraypointerh34_;
obj->farrays[70].setarraypointer = *glrsetarraypointerabp_;
obj->farrays[71].setarraypointer = *glrsetarraypointerbbp_;
obj->farrays[72].setarraypointer = *glrsetarraypointercbp_;
obj->farrays[73].setarraypointer = *glrsetarraypointerabf_;
obj->farrays[74].setarraypointer = *glrsetarraypointerbbf_;
obj->farrays[75].setarraypointer = *glrsetarraypointercbf_;
obj->farrays[76].setarraypointer = *glrsetarraypointerhp3_;
obj->farrays[77].setarraypointer = *glrsetarraypointerhtrans_;
obj->farrays[78].setarraypointer = *glrsetarraypointerabq_;
obj->farrays[79].setarraypointer = *glrsetarraypointerbbq_;
obj->farrays[80].setarraypointer = *glrsetarraypointercbq_;
obj->farrays[81].setarraypointer = *glrsetarraypointerebp_;
obj->farrays[82].setarraypointer = *glrsetarraypointerfbp_;
obj->farrays[83].setarraypointer = *glrsetarraypointergbp_;
obj->farrays[84].setarraypointer = *glrsetarraypointerhp0_;
obj->farrays[85].setarraypointer = *glrsetarraypointerhpm_;
obj->farrays[86].setarraypointer = *glrsetarraypointerhpme_;
obj->farrays[87].setarraypointer = *glrsetarraypointerhflr_;
obj->farrays[88].setarraypointer = *glrsetarraypointerhzp0_;
obj->farrays[89].setarraypointer = *glrsetarraypointerhzp1_;
obj->farrays[90].setarraypointer = *glrsetarraypointerhzp2_;
obj->farrays[91].setarraypointer = *glrsetarraypointerhzp3_;
obj->farrays[92].setarraypointer = *glrsetarraypointerhzt1_;
obj->farrays[93].setarraypointer = *glrsetarraypointerhzt2_;
obj->farrays[94].setarraypointer = *glrsetarraypointerhzt3_;
obj->farrays[95].setarraypointer = *glrsetarraypointerhzt2ks_;
obj->farrays[96].setarraypointer = *glrsetarraypointerhzt3ks_;
obj->farrays[97].setarraypointer = *glrsetarraypointerdterjb_;
obj->farrays[98].setarraypointer = *glrsetarraypointerbvac_;
obj->farrays[99].setarraypointer = *glrsetarraypointerdbvdz_;
obj->farrays[100].setarraypointer = *glrsetarraypointerd2bvdz2_;
obj->farrays[101].setarraypointer = *glrsetarraypointerd3bvdz3_;
obj->farrays[102].setarraypointer = *glrsetarraypointerbint_;
obj->farrays[103].setarraypointer = *glrsetarraypointerdp1dpsi_;
obj->farrays[104].setarraypointer = *glrsetarraypointerp1_;
obj->farrays[105].setarraypointer = *glrsetarraypointerp1k_;
obj->farrays[106].setarraypointer = *glrsetarraypointerhpk0_;
obj->farrays[107].setarraypointer = *glrsetarraypointerdeli1_;
obj->farrays[108].setarraypointer = *glrsetarraypointerdeli2_;
obj->farrays[109].setarraypointer = *glrsetarraypointerdeli3_;
obj->farrays[110].setarraypointer = *glrsetarraypointerdeli4_;
obj->farrays[111].setarraypointer = *glrsetarraypointerrzz_;
obj->farrays[112].setarraypointer = *glrsetarraypointerrzz1a_;
obj->farrays[113].setarraypointer = *glrsetarraypointerrzz1b_;
obj->farrays[114].setarraypointer = *glrsetarraypointerrzz2_;
obj->farrays[115].setarraypointer = *glrsetarraypointerrzz3_;
obj->farrays[116].setarraypointer = *glrsetarraypointerrzz1anew_;
obj->farrays[117].setarraypointer = *glrsetarraypointerrzz1bnew_;
obj->farrays[118].setarraypointer = *glrsetarraypointerrzz2new_;
obj->farrays[119].setarraypointer = *glrsetarraypointerrzz3new_;
obj->farrays[120].setarraypointer = *glrsetarraypointerrzznew_;
obj->farrays[121].setarraypointer = *glrsetarraypointerrzzold_;
obj->farrays[122].setarraypointer = *glrsetarraypointerrd2diff_;
obj->farrays[123].setarraypointer = *glrsetarraypointerrnew_;
obj->farrays[124].setarraypointer = *glrsetarraypointerrnewd2_;
obj->farrays[125].setarraypointer = *glrsetarraypointerrold_;
obj->farrays[126].setarraypointer = *glrsetarraypointerroldd2_;
obj->farrays[127].setarraypointer = *glrsetarraypointericapi2_;
obj->farrays[128].setarraypointer = *glrsetarraypointericapi3_;
obj->farrays[129].setarraypointer = *glrsetarraypointericapi5_;
obj->farrays[130].setarraypointer = *glrsetarraypointericap2new_;
obj->farrays[131].setarraypointer = *glrsetarraypointericap3new_;
obj->farrays[132].setarraypointer = *glrsetarraypointericap5new_;
obj->farrays[133].setarraypointer = *glrsetarraypointerdbdpsi_;
obj->farrays[134].setarraypointer = *glrsetarraypointerphi1_;
obj->farrays[135].setarraypointer = *glrsetarraypointerphi2_;
obj->farrays[136].setarraypointer = *glrsetarraypointerpperp_;
obj->farrays[137].setarraypointer = *glrsetarraypointerppar_;
obj->farrays[138].setarraypointer = *glrsetarraypointerjperpz_;
obj->farrays[151].setarraypointer = *glrsetarraypointerjparz_;
obj->farrays[152].setarraypointer = *glrsetarraypointerjd2fz_;
obj->farrays[153].setarraypointer = *glrsetarraypointerjdfz_;
obj->farrays[154].setarraypointer = *glrsetarraypointerjbtotz_;
obj->farrays[155].setarraypointer = *glrsetarraypointerjmbselfz_;
obj->farrays[156].setarraypointer = *glrsetarraypointerddbprpz_;
obj->farrays[157].setarraypointer = *glrsetarraypointerddbparz_;
obj->farrays[158].setarraypointer = *glrsetarraypointerposh_;
obj->farrays[159].setarraypointer = *glrsetarraypointernosh_;
obj->farrays[160].setarraypointer = *glrsetarraypointerbvacnorm_;
obj->farrays[161].setarraypointer = *glrsetarraypointerbti82_;
obj->farrays[162].setarraypointer = *glrsetarraypointerbtisubp_;
obj->farrays[163].setarraypointer = *glrsetarraypointerbtisubpm1_;
obj->farrays[164].setarraypointer = *glrsetarraypointerbtisubpm2_;
obj->farrays[165].setarraypointer = *glrsetarraypointerbtisubpm3_;
obj->farrays[166].setarraypointer = *glrsetarraypointerjpzsubp_;
obj->farrays[167].setarraypointer = *glrsetarraypointerjpzsubpm1_;
obj->farrays[168].setarraypointer = *glrsetarraypointerjpzsubpm2_;
obj->farrays[169].setarraypointer = *glrsetarraypointerjpzsubpm3_;
obj->farrays[170].setarraypointer = *glrsetarraypointerbj2old_;
obj->farrays[171].setarraypointer = *glrsetarraypointerpperpold_;
obj->farrays[172].setarraypointer = *glrsetarraypointerpperpold25_;
obj->farrays[173].setarraypointer = *glrsetarraypointerpparold_;
obj->farrays[174].setarraypointer = *glrsetarraypointerbetaold_;
obj->farrays[175].setarraypointer = *glrsetarraypointerqubold_;
obj->farrays[176].setarraypointer = *glrsetarraypointerqubvold_;
obj->farrays[177].setarraypointer = *glrsetarraypointerdbdpsiold_;
obj->farrays[178].setarraypointer = *glrsetarraypointerdflute3_;
obj->farrays[179].setarraypointer = *glrsetarraypointerqubv_;
obj->farrays[180].setarraypointer = *glrsetarraypointerp2_;
obj->farrays[181].setarraypointer = *glrsetarraypointerdp2dpsi_;
obj->farrays[182].setarraypointer = *glrsetarraypointerdflute1_;
obj->farrays[183].setarraypointer = *glrsetarraypointerdflute2_;
obj->farrays[184].setarraypointer = *glrsetarraypointerflute1_;
obj->farrays[185].setarraypointer = *glrsetarraypointerflute2_;
obj->farrays[186].setarraypointer = *glrsetarraypointerflute3_;
obj->farrays[187].setarraypointer = *glrsetarraypointerdpost1_;
obj->farrays[188].setarraypointer = *glrsetarraypointerdpost2_;
obj->farrays[189].setarraypointer = *glrsetarraypointerdpost1r_;
obj->farrays[190].setarraypointer = *glrsetarraypointerdpost2r_;
obj->farrays[191].setarraypointer = *glrsetarraypointerdpostjb_;
obj->farrays[192].setarraypointer = *glrsetarraypointerdpostjbo_;
obj->farrays[193].setarraypointer = *glrsetarraypointerptot_;
obj->farrays[194].setarraypointer = *glrsetarraypointerbeta_;
obj->farrays[195].setarraypointer = *glrsetarraypointerbetanorm_;
obj->farrays[196].setarraypointer = *glrsetarraypointerp2k_;
obj->farrays[197].setarraypointer = *glrsetarraypointerdeli5_;
obj->farrays[198].setarraypointer = *glrsetarraypointerdel1new_;
obj->farrays[199].setarraypointer = *glrsetarraypointerdel2new_;
obj->farrays[200].setarraypointer = *glrsetarraypointerdel3new_;
obj->farrays[201].setarraypointer = *glrsetarraypointerdel5new_;
obj->farrays[202].setarraypointer = *glrsetarraypointerpperps_;
obj->farrays[203].setarraypointer = *glrsetarraypointererrprp_;
obj->farrays[204].setarraypointer = *glrsetarraypointererrprl_;
obj->farrays[205].setarraypointer = *glrsetarraypointerdqubdb_;
obj->farrays[206].setarraypointer = *glrsetarraypointerxxxfreq_;
obj->farrays[207].setarraypointer = *glrsetarraypointerpperpe_;
obj->farrays[208].setarraypointer = *glrsetarraypointerepsi_;
obj->farrays[209].setarraypointer = *glrsetarraypointeromeg1wkb_;
obj->farrays[210].setarraypointer = *glrsetarraypointeromeg2wkb_;
obj->farrays[211].setarraypointer = *glrsetarraypointergamwkb_;
obj->farrays[212].setarraypointer = *glrsetarraypointerdflute4_;
obj->farrays[213].setarraypointer = *glrsetarraypointerrhoave_;
obj->farrays[214].setarraypointer = *glrsetarraypointerxxxave_;
obj->farrays[215].setarraypointer = *glrsetarraypointeryyyave_;
obj->farrays[216].setarraypointer = *glrsetarraypointerp2t_;
obj->farrays[217].setarraypointer = *glrsetarraypointerdp2dpst_;
obj->farrays[218].setarraypointer = *glrsetarraypointerp3_;
obj->farrays[219].setarraypointer = *glrsetarraypointerdp3dpsi_;
obj->farrays[220].setarraypointer = *glrsetarraypointerhpkm_;
obj->farrays[221].setarraypointer = *glrsetarraypointerhpkme_;
obj->farrays[222].setarraypointer = *glrsetarraypointerdroave_;
obj->farrays[223].setarraypointer = *glrsetarraypointerdroterm_;
obj->farrays[224].setarraypointer = *glrsetarraypointerering_;
obj->farrays[225].setarraypointer = *glrsetarraypointerdrxi_;
obj->farrays[226].setarraypointer = *glrsetarraypointerdrxio_;
obj->farrays[227].setarraypointer = *glrsetarraypointerdrxr_;
obj->farrays[228].setarraypointer = *glrsetarraypointerdrxro_;
obj->farrays[229].setarraypointer = *glrsetarraypointerdxiz2_;
obj->farrays[230].setarraypointer = *glrsetarraypointerdxrz2_;
obj->farrays[231].setarraypointer = *glrsetarraypointerdum1_;
obj->farrays[232].setarraypointer = *glrsetarraypointerdum2_;
obj->farrays[233].setarraypointer = *glrsetarraypointerpsuma_;
obj->farrays[234].setarraypointer = *glrsetarraypointerpsumb_;
obj->farrays[237].setarraypointer = *glrsetarraypointerrxi_;
obj->farrays[238].setarraypointer = *glrsetarraypointerrxr_;
obj->farrays[239].setarraypointer = *glrsetarraypointerxig_;
obj->farrays[240].setarraypointer = *glrsetarraypointerxigo_;
obj->farrays[241].setarraypointer = *glrsetarraypointerxrg_;
obj->farrays[242].setarraypointer = *glrsetarraypointerxrgo_;
obj->farrays[243].setarraypointer = *glrsetarraypointerrhs1b_;
obj->farrays[244].setarraypointer = *glrsetarraypointerrhs2b_;
obj->farrays[245].setarraypointer = *glrsetarraypointerlsp_;
obj->farrays[246].setarraypointer = *glrsetarraypointerdsp_;
obj->farrays[247].setarraypointer = *glrsetarraypointercsp1_;
obj->farrays[248].setarraypointer = *glrsetarraypointercsp2_;
obj->farrays[249].setarraypointer = *glrsetarraypointercsp3_;
obj->farrays[250].setarraypointer = *glrsetarraypointercsp4_;
}
static char doc_glr_glrgen[] = "glrgen\nAdvance solution in time?";
static PyObject *
glr_glrgen(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
glrgen_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_glr_glrexepy[] = "glrexepy\n";
static PyObject *
glr_glrexepy(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
glrexepy_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_glr_amat[] = "amat\n?";
static PyObject *
glr_amat(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
amat_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_glr_amax2[] = "amax2(a:real,im:integer,jm:integer,amax:real,\n\timx:integer,jmx:integer)\nGiven 2D array a(im,jm), amax2 finds its maximum (amax) and\ncorresponding indices (imx,jmx).";
static PyObject *
glr_amax2(PyObject *self, PyObject *args)
{
  PyObject * pyobj[6];
  PyArrayObject * ax[6];
  int i;
  char e[256];
  for (i=0;i<6;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "OOOOOO", &pyobj[0], &pyobj[1], &pyobj[2], &pyobj[3], &pyobj[4], &pyobj[5])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_DOUBLE)) {
    sprintf(e, "Argument a in amax2 has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_DOUBLE);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument a in amax2");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[1], NPY_LONG)) {
    sprintf(e, "Argument im in amax2 has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[1] = FARRAY_FROMOBJECT(pyobj[1], NPY_LONG);
  if (ax[1] == NULL) {
    sprintf(e, "There is an error in argument im in amax2");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[2], NPY_LONG)) {
    sprintf(e, "Argument jm in amax2 has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[2] = FARRAY_FROMOBJECT(pyobj[2], NPY_LONG);
  if (ax[2] == NULL) {
    sprintf(e, "There is an error in argument jm in amax2");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[3], NPY_DOUBLE)) {
    sprintf(e, "Argument amax in amax2 has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[3] = FARRAY_FROMOBJECT(pyobj[3], NPY_DOUBLE);
  if (ax[3] == NULL) {
    sprintf(e, "There is an error in argument amax in amax2");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[4], NPY_LONG)) {
    sprintf(e, "Argument imx in amax2 has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[4] = FARRAY_FROMOBJECT(pyobj[4], NPY_LONG);
  if (ax[4] == NULL) {
    sprintf(e, "There is an error in argument imx in amax2");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[5], NPY_LONG)) {
    sprintf(e, "Argument jmx in amax2 has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[5] = FARRAY_FROMOBJECT(pyobj[5], NPY_LONG);
  if (ax[5] == NULL) {
    sprintf(e, "There is an error in argument jmx in amax2");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
amax2_((double *)(PyArray_BYTES(ax[0])), (long *)(PyArray_BYTES(ax[1])), (long *)(PyArray_BYTES(ax[2])), (double *)(PyArray_BYTES(ax[3])), (long *)(PyArray_BYTES(ax[4])), (long *)(PyArray_BYTES(ax[5])));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(6, pyobj, ax);
  returnnone;
err:
  for (i=0;i<6;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}
static char doc_glr_bcccal[] = "bcccal(bs:real,zs:real,ass:real,als:real,z:real,n:integer,\n\tbv:real,bvp:real,bvpp:real,b4:real,b5:real,z4:real,\n\tz5:real,nc:integer)\n?";
static PyObject *
glr_bcccal(PyObject *self, PyObject *args)
{
  PyObject * pyobj[14];
  PyArrayObject * ax[14];
  int i;
  char e[256];
  for (i=0;i<14;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "OOOOOOOOOOOOOO", &pyobj[0], &pyobj[1], &pyobj[2], &pyobj[3], &pyobj[4], &pyobj[5], &pyobj[6], &pyobj[7], &pyobj[8], &pyobj[9], &pyobj[10], &pyobj[11], &pyobj[12], &pyobj[13])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_DOUBLE)) {
    sprintf(e, "Argument bs in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_DOUBLE);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument bs in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[1], NPY_DOUBLE)) {
    sprintf(e, "Argument zs in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[1] = FARRAY_FROMOBJECT(pyobj[1], NPY_DOUBLE);
  if (ax[1] == NULL) {
    sprintf(e, "There is an error in argument zs in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[2], NPY_DOUBLE)) {
    sprintf(e, "Argument ass in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[2] = FARRAY_FROMOBJECT(pyobj[2], NPY_DOUBLE);
  if (ax[2] == NULL) {
    sprintf(e, "There is an error in argument ass in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[3], NPY_DOUBLE)) {
    sprintf(e, "Argument als in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[3] = FARRAY_FROMOBJECT(pyobj[3], NPY_DOUBLE);
  if (ax[3] == NULL) {
    sprintf(e, "There is an error in argument als in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[4], NPY_DOUBLE)) {
    sprintf(e, "Argument z in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[4] = FARRAY_FROMOBJECT(pyobj[4], NPY_DOUBLE);
  if (ax[4] == NULL) {
    sprintf(e, "There is an error in argument z in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[5], NPY_LONG)) {
    sprintf(e, "Argument n in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[5] = FARRAY_FROMOBJECT(pyobj[5], NPY_LONG);
  if (ax[5] == NULL) {
    sprintf(e, "There is an error in argument n in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[6], NPY_DOUBLE)) {
    sprintf(e, "Argument bv in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[6] = FARRAY_FROMOBJECT(pyobj[6], NPY_DOUBLE);
  if (ax[6] == NULL) {
    sprintf(e, "There is an error in argument bv in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[7], NPY_DOUBLE)) {
    sprintf(e, "Argument bvp in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[7] = FARRAY_FROMOBJECT(pyobj[7], NPY_DOUBLE);
  if (ax[7] == NULL) {
    sprintf(e, "There is an error in argument bvp in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[8], NPY_DOUBLE)) {
    sprintf(e, "Argument bvpp in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[8] = FARRAY_FROMOBJECT(pyobj[8], NPY_DOUBLE);
  if (ax[8] == NULL) {
    sprintf(e, "There is an error in argument bvpp in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[9], NPY_DOUBLE)) {
    sprintf(e, "Argument b4 in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[9] = FARRAY_FROMOBJECT(pyobj[9], NPY_DOUBLE);
  if (ax[9] == NULL) {
    sprintf(e, "There is an error in argument b4 in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[10], NPY_DOUBLE)) {
    sprintf(e, "Argument b5 in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[10] = FARRAY_FROMOBJECT(pyobj[10], NPY_DOUBLE);
  if (ax[10] == NULL) {
    sprintf(e, "There is an error in argument b5 in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[11], NPY_DOUBLE)) {
    sprintf(e, "Argument z4 in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[11] = FARRAY_FROMOBJECT(pyobj[11], NPY_DOUBLE);
  if (ax[11] == NULL) {
    sprintf(e, "There is an error in argument z4 in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[12], NPY_DOUBLE)) {
    sprintf(e, "Argument z5 in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[12] = FARRAY_FROMOBJECT(pyobj[12], NPY_DOUBLE);
  if (ax[12] == NULL) {
    sprintf(e, "There is an error in argument z5 in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[13], NPY_LONG)) {
    sprintf(e, "Argument nc in bcccal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[13] = FARRAY_FROMOBJECT(pyobj[13], NPY_LONG);
  if (ax[13] == NULL) {
    sprintf(e, "There is an error in argument nc in bcccal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
bcccal_((double *)(PyArray_BYTES(ax[0])), (double *)(PyArray_BYTES(ax[1])), (double *)(PyArray_BYTES(ax[2])), (double *)(PyArray_BYTES(ax[3])), (double *)(PyArray_BYTES(ax[4])), (long *)(PyArray_BYTES(ax[5])), (double *)(PyArray_BYTES(ax[6])), (double *)(PyArray_BYTES(ax[7])), (double *)(PyArray_BYTES(ax[8])), (double *)(PyArray_BYTES(ax[9])), (double *)(PyArray_BYTES(ax[10])), (double *)(PyArray_BYTES(ax[11])), (double *)(PyArray_BYTES(ax[12])), (long *)(PyArray_BYTES(ax[13])));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(14, pyobj, ax);
  returnnone;
err:
  for (i=0;i<14;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}
static char doc_glr_bvcal[] = "bvcal(bs:real,zs:real,ass:real,als:real,z:real,n:integer,\n\tzcc:real,bcc:real,znorm:real,bv:real,bvp:real,\n\tbvpp:real,b4:real,b5:real,z4:real,z5:real,\n\tnc:integer)\n?";
static PyObject *
glr_bvcal(PyObject *self, PyObject *args)
{
  PyObject * pyobj[17];
  PyArrayObject * ax[17];
  int i;
  char e[256];
  for (i=0;i<17;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "OOOOOOOOOOOOOOOOO", &pyobj[0], &pyobj[1], &pyobj[2], &pyobj[3], &pyobj[4], &pyobj[5], &pyobj[6], &pyobj[7], &pyobj[8], &pyobj[9], &pyobj[10], &pyobj[11], &pyobj[12], &pyobj[13], &pyobj[14], &pyobj[15], &pyobj[16])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_DOUBLE)) {
    sprintf(e, "Argument bs in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_DOUBLE);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument bs in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[1], NPY_DOUBLE)) {
    sprintf(e, "Argument zs in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[1] = FARRAY_FROMOBJECT(pyobj[1], NPY_DOUBLE);
  if (ax[1] == NULL) {
    sprintf(e, "There is an error in argument zs in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[2], NPY_DOUBLE)) {
    sprintf(e, "Argument ass in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[2] = FARRAY_FROMOBJECT(pyobj[2], NPY_DOUBLE);
  if (ax[2] == NULL) {
    sprintf(e, "There is an error in argument ass in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[3], NPY_DOUBLE)) {
    sprintf(e, "Argument als in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[3] = FARRAY_FROMOBJECT(pyobj[3], NPY_DOUBLE);
  if (ax[3] == NULL) {
    sprintf(e, "There is an error in argument als in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[4], NPY_DOUBLE)) {
    sprintf(e, "Argument z in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[4] = FARRAY_FROMOBJECT(pyobj[4], NPY_DOUBLE);
  if (ax[4] == NULL) {
    sprintf(e, "There is an error in argument z in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[5], NPY_LONG)) {
    sprintf(e, "Argument n in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[5] = FARRAY_FROMOBJECT(pyobj[5], NPY_LONG);
  if (ax[5] == NULL) {
    sprintf(e, "There is an error in argument n in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[6], NPY_DOUBLE)) {
    sprintf(e, "Argument zcc in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[6] = FARRAY_FROMOBJECT(pyobj[6], NPY_DOUBLE);
  if (ax[6] == NULL) {
    sprintf(e, "There is an error in argument zcc in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[7], NPY_DOUBLE)) {
    sprintf(e, "Argument bcc in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[7] = FARRAY_FROMOBJECT(pyobj[7], NPY_DOUBLE);
  if (ax[7] == NULL) {
    sprintf(e, "There is an error in argument bcc in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[8], NPY_DOUBLE)) {
    sprintf(e, "Argument znorm in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[8] = FARRAY_FROMOBJECT(pyobj[8], NPY_DOUBLE);
  if (ax[8] == NULL) {
    sprintf(e, "There is an error in argument znorm in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[9], NPY_DOUBLE)) {
    sprintf(e, "Argument bv in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[9] = FARRAY_FROMOBJECT(pyobj[9], NPY_DOUBLE);
  if (ax[9] == NULL) {
    sprintf(e, "There is an error in argument bv in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[10], NPY_DOUBLE)) {
    sprintf(e, "Argument bvp in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[10] = FARRAY_FROMOBJECT(pyobj[10], NPY_DOUBLE);
  if (ax[10] == NULL) {
    sprintf(e, "There is an error in argument bvp in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[11], NPY_DOUBLE)) {
    sprintf(e, "Argument bvpp in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[11] = FARRAY_FROMOBJECT(pyobj[11], NPY_DOUBLE);
  if (ax[11] == NULL) {
    sprintf(e, "There is an error in argument bvpp in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[12], NPY_DOUBLE)) {
    sprintf(e, "Argument b4 in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[12] = FARRAY_FROMOBJECT(pyobj[12], NPY_DOUBLE);
  if (ax[12] == NULL) {
    sprintf(e, "There is an error in argument b4 in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[13], NPY_DOUBLE)) {
    sprintf(e, "Argument b5 in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[13] = FARRAY_FROMOBJECT(pyobj[13], NPY_DOUBLE);
  if (ax[13] == NULL) {
    sprintf(e, "There is an error in argument b5 in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[14], NPY_DOUBLE)) {
    sprintf(e, "Argument z4 in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[14] = FARRAY_FROMOBJECT(pyobj[14], NPY_DOUBLE);
  if (ax[14] == NULL) {
    sprintf(e, "There is an error in argument z4 in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[15], NPY_DOUBLE)) {
    sprintf(e, "Argument z5 in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[15] = FARRAY_FROMOBJECT(pyobj[15], NPY_DOUBLE);
  if (ax[15] == NULL) {
    sprintf(e, "There is an error in argument z5 in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[16], NPY_LONG)) {
    sprintf(e, "Argument nc in bvcal has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[16] = FARRAY_FROMOBJECT(pyobj[16], NPY_LONG);
  if (ax[16] == NULL) {
    sprintf(e, "There is an error in argument nc in bvcal");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
bvcal_((double *)(PyArray_BYTES(ax[0])), (double *)(PyArray_BYTES(ax[1])), (double *)(PyArray_BYTES(ax[2])), (double *)(PyArray_BYTES(ax[3])), (double *)(PyArray_BYTES(ax[4])), (long *)(PyArray_BYTES(ax[5])), (double *)(PyArray_BYTES(ax[6])), (double *)(PyArray_BYTES(ax[7])), (double *)(PyArray_BYTES(ax[8])), (double *)(PyArray_BYTES(ax[9])), (double *)(PyArray_BYTES(ax[10])), (double *)(PyArray_BYTES(ax[11])), (double *)(PyArray_BYTES(ax[12])), (double *)(PyArray_BYTES(ax[13])), (double *)(PyArray_BYTES(ax[14])), (double *)(PyArray_BYTES(ax[15])), (long *)(PyArray_BYTES(ax[16])));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(17, pyobj, ax);
  returnnone;
err:
  for (i=0;i<17;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}
static char doc_glr_comat[] = "comat\n?";
static PyObject *
glr_comat(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
comat_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_glr_constant[] = "constant\n?";
static PyObject *
glr_constant(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
constant_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_glr_diagno[] = "diagno\n?";
static PyObject *
glr_diagno(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
diagno_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_glr_ddpsi[] = "ddpsi(f1:real,f2:real,i:integer)\n?";
static PyObject *
glr_ddpsi(PyObject *self, PyObject *args)
{
  PyObject * pyobj[3];
  PyArrayObject * ax[3];
  int i;
  char e[256];
  for (i=0;i<3;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "OOO", &pyobj[0], &pyobj[1], &pyobj[2])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_DOUBLE)) {
    sprintf(e, "Argument f1 in ddpsi has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_DOUBLE);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument f1 in ddpsi");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[1], NPY_DOUBLE)) {
    sprintf(e, "Argument f2 in ddpsi has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[1] = FARRAY_FROMOBJECT(pyobj[1], NPY_DOUBLE);
  if (ax[1] == NULL) {
    sprintf(e, "There is an error in argument f2 in ddpsi");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[2], NPY_LONG)) {
    sprintf(e, "Argument i in ddpsi has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[2] = FARRAY_FROMOBJECT(pyobj[2], NPY_LONG);
  if (ax[2] == NULL) {
    sprintf(e, "There is an error in argument i in ddpsi");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
ddpsi_((double *)(PyArray_BYTES(ax[0])), (double *)(PyArray_BYTES(ax[1])), (long *)(PyArray_BYTES(ax[2])));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(3, pyobj, ax);
  returnnone;
err:
  for (i=0;i<3;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}
static char doc_glr_ddz[] = "ddz(f1:real,f2:real)\n?";
static PyObject *
glr_ddz(PyObject *self, PyObject *args)
{
  PyObject * pyobj[2];
  PyArrayObject * ax[2];
  int i;
  char e[256];
  for (i=0;i<2;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "OO", &pyobj[0], &pyobj[1])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_DOUBLE)) {
    sprintf(e, "Argument f1 in ddz has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_DOUBLE);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument f1 in ddz");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[1], NPY_DOUBLE)) {
    sprintf(e, "Argument f2 in ddz has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[1] = FARRAY_FROMOBJECT(pyobj[1], NPY_DOUBLE);
  if (ax[1] == NULL) {
    sprintf(e, "There is an error in argument f2 in ddz");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
ddz_((double *)(PyArray_BYTES(ax[0])), (double *)(PyArray_BYTES(ax[1])));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(2, pyobj, ax);
  returnnone;
err:
  for (i=0;i<2;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}
static char doc_glr_dydx5[] = "dydx5(x:real,y:real,n:integer,yp1:real,ypn:real)\nEvaluate end-point derivatives";
static PyObject *
glr_dydx5(PyObject *self, PyObject *args)
{
  PyObject * pyobj[5];
  PyArrayObject * ax[5];
  int i;
  char e[256];
  for (i=0;i<5;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "OOOOO", &pyobj[0], &pyobj[1], &pyobj[2], &pyobj[3], &pyobj[4])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_DOUBLE)) {
    sprintf(e, "Argument x in dydx5 has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_DOUBLE);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument x in dydx5");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[1], NPY_DOUBLE)) {
    sprintf(e, "Argument y in dydx5 has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[1] = FARRAY_FROMOBJECT(pyobj[1], NPY_DOUBLE);
  if (ax[1] == NULL) {
    sprintf(e, "There is an error in argument y in dydx5");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[2], NPY_LONG)) {
    sprintf(e, "Argument n in dydx5 has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[2] = FARRAY_FROMOBJECT(pyobj[2], NPY_LONG);
  if (ax[2] == NULL) {
    sprintf(e, "There is an error in argument n in dydx5");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[3], NPY_DOUBLE)) {
    sprintf(e, "Argument yp1 in dydx5 has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[3] = FARRAY_FROMOBJECT(pyobj[3], NPY_DOUBLE);
  if (ax[3] == NULL) {
    sprintf(e, "There is an error in argument yp1 in dydx5");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[4], NPY_DOUBLE)) {
    sprintf(e, "Argument ypn in dydx5 has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[4] = FARRAY_FROMOBJECT(pyobj[4], NPY_DOUBLE);
  if (ax[4] == NULL) {
    sprintf(e, "There is an error in argument ypn in dydx5");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
dydx5_((double *)(PyArray_BYTES(ax[0])), (double *)(PyArray_BYTES(ax[1])), (long *)(PyArray_BYTES(ax[2])), (double *)(PyArray_BYTES(ax[3])), (double *)(PyArray_BYTES(ax[4])));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(5, pyobj, ax);
  returnnone;
err:
  for (i=0;i<5;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}
static char doc_glr_energy[] = "energy\n?";
static PyObject *
glr_energy(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
energy_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_glr_equiltm[] = "equiltm\n?";
static PyObject *
glr_equiltm(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
equiltm_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_glr_errorend[] = "errorend(i:integer,j:integer)\n?";
static PyObject *
glr_errorend(PyObject *self, PyObject *args)
{
  PyObject * pyobj[2];
  PyArrayObject * ax[2];
  int i;
  char e[256];
  for (i=0;i<2;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "OO", &pyobj[0], &pyobj[1])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_LONG)) {
    sprintf(e, "Argument i in errorend has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_LONG);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument i in errorend");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[1], NPY_LONG)) {
    sprintf(e, "Argument j in errorend has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[1] = FARRAY_FROMOBJECT(pyobj[1], NPY_LONG);
  if (ax[1] == NULL) {
    sprintf(e, "There is an error in argument j in errorend");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
errorend_((long *)(PyArray_BYTES(ax[0])), (long *)(PyArray_BYTES(ax[1])));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(2, pyobj, ax);
  returnnone;
err:
  for (i=0;i<2;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}
static char doc_glr_f1to11[] = "f1to11\n?";
static PyObject *
glr_f1to11(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
f1to11_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_glr_grid[] = "grid\n?";
static PyObject *
glr_grid(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
grid_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_glr_initial[] = "initial\n?";
static PyObject *
glr_initial(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
initial_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_glr_inputtm[] = "inputtm\n?";
static PyObject *
glr_inputtm(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
inputtm_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_glr_interp[] = "interp(x:real,y:real,n:integer,bc1:real,bcn:real,x2:real,y2:real,y2p:real,m:integer)\nInterpolates from y(x(1:n)) onto y2(x2(1:m)) using cubic splines.\nThe boundary conditions (see subroutine spline) are specified with\nbc1 and bcn. The 1st derivative of y2, y2p(1:m), is also evaluated.";
static PyObject *
glr_interp(PyObject *self, PyObject *args)
{
  PyObject * pyobj[9];
  PyArrayObject * ax[9];
  int i;
  char e[256];
  for (i=0;i<9;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "OOOOOOOOO", &pyobj[0], &pyobj[1], &pyobj[2], &pyobj[3], &pyobj[4], &pyobj[5], &pyobj[6], &pyobj[7], &pyobj[8])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_DOUBLE)) {
    sprintf(e, "Argument x in interp has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_DOUBLE);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument x in interp");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[1], NPY_DOUBLE)) {
    sprintf(e, "Argument y in interp has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[1] = FARRAY_FROMOBJECT(pyobj[1], NPY_DOUBLE);
  if (ax[1] == NULL) {
    sprintf(e, "There is an error in argument y in interp");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[2], NPY_LONG)) {
    sprintf(e, "Argument n in interp has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[2] = FARRAY_FROMOBJECT(pyobj[2], NPY_LONG);
  if (ax[2] == NULL) {
    sprintf(e, "There is an error in argument n in interp");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[3], NPY_DOUBLE)) {
    sprintf(e, "Argument bc1 in interp has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[3] = FARRAY_FROMOBJECT(pyobj[3], NPY_DOUBLE);
  if (ax[3] == NULL) {
    sprintf(e, "There is an error in argument bc1 in interp");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[4], NPY_DOUBLE)) {
    sprintf(e, "Argument bcn in interp has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[4] = FARRAY_FROMOBJECT(pyobj[4], NPY_DOUBLE);
  if (ax[4] == NULL) {
    sprintf(e, "There is an error in argument bcn in interp");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[5], NPY_DOUBLE)) {
    sprintf(e, "Argument x2 in interp has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[5] = FARRAY_FROMOBJECT(pyobj[5], NPY_DOUBLE);
  if (ax[5] == NULL) {
    sprintf(e, "There is an error in argument x2 in interp");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[6], NPY_DOUBLE)) {
    sprintf(e, "Argument y2 in interp has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[6] = FARRAY_FROMOBJECT(pyobj[6], NPY_DOUBLE);
  if (ax[6] == NULL) {
    sprintf(e, "There is an error in argument y2 in interp");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[7], NPY_DOUBLE)) {
    sprintf(e, "Argument y2p in interp has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[7] = FARRAY_FROMOBJECT(pyobj[7], NPY_DOUBLE);
  if (ax[7] == NULL) {
    sprintf(e, "There is an error in argument y2p in interp");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[8], NPY_LONG)) {
    sprintf(e, "Argument m in interp has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[8] = FARRAY_FROMOBJECT(pyobj[8], NPY_LONG);
  if (ax[8] == NULL) {
    sprintf(e, "There is an error in argument m in interp");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
interp_((double *)(PyArray_BYTES(ax[0])), (double *)(PyArray_BYTES(ax[1])), (long *)(PyArray_BYTES(ax[2])), (double *)(PyArray_BYTES(ax[3])), (double *)(PyArray_BYTES(ax[4])), (double *)(PyArray_BYTES(ax[5])), (double *)(PyArray_BYTES(ax[6])), (double *)(PyArray_BYTES(ax[7])), (long *)(PyArray_BYTES(ax[8])));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(9, pyobj, ax);
  returnnone;
err:
  for (i=0;i<9;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}
static char doc_glr_mymove[] = "mymove(a:real,b:real,len:integer)\n?";
static PyObject *
glr_mymove(PyObject *self, PyObject *args)
{
  PyObject * pyobj[3];
  PyArrayObject * ax[3];
  int i;
  char e[256];
  for (i=0;i<3;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "OOO", &pyobj[0], &pyobj[1], &pyobj[2])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_DOUBLE)) {
    sprintf(e, "Argument a in mymove has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_DOUBLE);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument a in mymove");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[1], NPY_DOUBLE)) {
    sprintf(e, "Argument b in mymove has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[1] = FARRAY_FROMOBJECT(pyobj[1], NPY_DOUBLE);
  if (ax[1] == NULL) {
    sprintf(e, "There is an error in argument b in mymove");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[2], NPY_LONG)) {
    sprintf(e, "Argument len in mymove has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[2] = FARRAY_FROMOBJECT(pyobj[2], NPY_LONG);
  if (ax[2] == NULL) {
    sprintf(e, "There is an error in argument len in mymove");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
mymove_((double *)(PyArray_BYTES(ax[0])), (double *)(PyArray_BYTES(ax[1])), (long *)(PyArray_BYTES(ax[2])));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(3, pyobj, ax);
  returnnone;
err:
  for (i=0;i<3;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}
static char doc_glr_rightvec[] = "rightvec\n?";
static PyObject *
glr_rightvec(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
rightvec_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_glr_simps[] = "simps(fin:real,fout:real,knn:integer,df:real)\n?";
static PyObject *
glr_simps(PyObject *self, PyObject *args)
{
  PyObject * pyobj[4];
  PyArrayObject * ax[4];
  int i;
  char e[256];
  for (i=0;i<4;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "OOOO", &pyobj[0], &pyobj[1], &pyobj[2], &pyobj[3])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_DOUBLE)) {
    sprintf(e, "Argument fin in simps has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_DOUBLE);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument fin in simps");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[1], NPY_DOUBLE)) {
    sprintf(e, "Argument fout in simps has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[1] = FARRAY_FROMOBJECT(pyobj[1], NPY_DOUBLE);
  if (ax[1] == NULL) {
    sprintf(e, "There is an error in argument fout in simps");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[2], NPY_LONG)) {
    sprintf(e, "Argument knn in simps has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[2] = FARRAY_FROMOBJECT(pyobj[2], NPY_LONG);
  if (ax[2] == NULL) {
    sprintf(e, "There is an error in argument knn in simps");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[3], NPY_DOUBLE)) {
    sprintf(e, "Argument df in simps has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[3] = FARRAY_FROMOBJECT(pyobj[3], NPY_DOUBLE);
  if (ax[3] == NULL) {
    sprintf(e, "There is an error in argument df in simps");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
simps_((double *)(PyArray_BYTES(ax[0])), (double *)(PyArray_BYTES(ax[1])), (long *)(PyArray_BYTES(ax[2])), (double *)(PyArray_BYTES(ax[3])));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(4, pyobj, ax);
  returnnone;
err:
  for (i=0;i<4;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}
static char doc_glr_spline[] = "spline(x:real,y:real,n:integer,bc1:real,bcn:real,yp:real,ypp:real,yppp:real,yint:real)\nEvaluate derivatives and integrals of y(x), using cubic splines.\nThe input is contained in x(1:n) and y(1:n) and the boundary\nconditions are specified with bc1 (1st point) and bcn (last point):\nbc1, bcn == -666 periodic;\nbc1, bcn == 777 not-a-knot;\nbc1, bcn == -111 extrapolates for 1st deriv;\nbc1, bcn == 555 natural 2nd deriv=0;\nbc1, bcn == -777 3rd deriv=0;\notherwise bc1 and bcn contain value of 1st derivative.\nThe output consists of the three derivatives: yp, ypp, yppp and\nthe integral yint (all of length 1:n).\nThe running integral is not computed if yint(1)=-999 on input.\nExcept for periodic splines, scalar yi=-999 will work.";
static PyObject *
glr_spline(PyObject *self, PyObject *args)
{
  PyObject * pyobj[9];
  PyArrayObject * ax[9];
  int i;
  char e[256];
  for (i=0;i<9;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "OOOOOOOOO", &pyobj[0], &pyobj[1], &pyobj[2], &pyobj[3], &pyobj[4], &pyobj[5], &pyobj[6], &pyobj[7], &pyobj[8])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_DOUBLE)) {
    sprintf(e, "Argument x in spline has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_DOUBLE);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument x in spline");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[1], NPY_DOUBLE)) {
    sprintf(e, "Argument y in spline has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[1] = FARRAY_FROMOBJECT(pyobj[1], NPY_DOUBLE);
  if (ax[1] == NULL) {
    sprintf(e, "There is an error in argument y in spline");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[2], NPY_LONG)) {
    sprintf(e, "Argument n in spline has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[2] = FARRAY_FROMOBJECT(pyobj[2], NPY_LONG);
  if (ax[2] == NULL) {
    sprintf(e, "There is an error in argument n in spline");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[3], NPY_DOUBLE)) {
    sprintf(e, "Argument bc1 in spline has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[3] = FARRAY_FROMOBJECT(pyobj[3], NPY_DOUBLE);
  if (ax[3] == NULL) {
    sprintf(e, "There is an error in argument bc1 in spline");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[4], NPY_DOUBLE)) {
    sprintf(e, "Argument bcn in spline has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[4] = FARRAY_FROMOBJECT(pyobj[4], NPY_DOUBLE);
  if (ax[4] == NULL) {
    sprintf(e, "There is an error in argument bcn in spline");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[5], NPY_DOUBLE)) {
    sprintf(e, "Argument yp in spline has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[5] = FARRAY_FROMOBJECT(pyobj[5], NPY_DOUBLE);
  if (ax[5] == NULL) {
    sprintf(e, "There is an error in argument yp in spline");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[6], NPY_DOUBLE)) {
    sprintf(e, "Argument ypp in spline has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[6] = FARRAY_FROMOBJECT(pyobj[6], NPY_DOUBLE);
  if (ax[6] == NULL) {
    sprintf(e, "There is an error in argument ypp in spline");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[7], NPY_DOUBLE)) {
    sprintf(e, "Argument yppp in spline has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[7] = FARRAY_FROMOBJECT(pyobj[7], NPY_DOUBLE);
  if (ax[7] == NULL) {
    sprintf(e, "There is an error in argument yppp in spline");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[8], NPY_DOUBLE)) {
    sprintf(e, "Argument yint in spline has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[8] = FARRAY_FROMOBJECT(pyobj[8], NPY_DOUBLE);
  if (ax[8] == NULL) {
    sprintf(e, "There is an error in argument yint in spline");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
spline_((double *)(PyArray_BYTES(ax[0])), (double *)(PyArray_BYTES(ax[1])), (long *)(PyArray_BYTES(ax[2])), (double *)(PyArray_BYTES(ax[3])), (double *)(PyArray_BYTES(ax[4])), (double *)(PyArray_BYTES(ax[5])), (double *)(PyArray_BYTES(ax[6])), (double *)(PyArray_BYTES(ax[7])), (double *)(PyArray_BYTES(ax[8])));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(9, pyobj, ax);
  returnnone;
err:
  for (i=0;i<9;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}
static char doc_glr_tmcon2[] = "tmcon2\n?\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
static PyObject *
glr_tmcon2(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
tmcon2_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}

static struct PyMethodDef glr_methods[] = {
{"glrgen", (PyCFunction)glr_glrgen, 1, doc_glr_glrgen}, 
{"glrexepy", (PyCFunction)glr_glrexepy, 1, doc_glr_glrexepy}, 
{"amat", (PyCFunction)glr_amat, 1, doc_glr_amat}, 
{"amax2", (PyCFunction)glr_amax2, 1, doc_glr_amax2}, 
{"bcccal", (PyCFunction)glr_bcccal, 1, doc_glr_bcccal}, 
{"bvcal", (PyCFunction)glr_bvcal, 1, doc_glr_bvcal}, 
{"comat", (PyCFunction)glr_comat, 1, doc_glr_comat}, 
{"constant", (PyCFunction)glr_constant, 1, doc_glr_constant}, 
{"diagno", (PyCFunction)glr_diagno, 1, doc_glr_diagno}, 
{"ddpsi", (PyCFunction)glr_ddpsi, 1, doc_glr_ddpsi}, 
{"ddz", (PyCFunction)glr_ddz, 1, doc_glr_ddz}, 
{"dydx5", (PyCFunction)glr_dydx5, 1, doc_glr_dydx5}, 
{"energy", (PyCFunction)glr_energy, 1, doc_glr_energy}, 
{"equiltm", (PyCFunction)glr_equiltm, 1, doc_glr_equiltm}, 
{"errorend", (PyCFunction)glr_errorend, 1, doc_glr_errorend}, 
{"f1to11", (PyCFunction)glr_f1to11, 1, doc_glr_f1to11}, 
{"grid", (PyCFunction)glr_grid, 1, doc_glr_grid}, 
{"initial", (PyCFunction)glr_initial, 1, doc_glr_initial}, 
{"inputtm", (PyCFunction)glr_inputtm, 1, doc_glr_inputtm}, 
{"interp", (PyCFunction)glr_interp, 1, doc_glr_interp}, 
{"mymove", (PyCFunction)glr_mymove, 1, doc_glr_mymove}, 
{"rightvec", (PyCFunction)glr_rightvec, 1, doc_glr_rightvec}, 
{"simps", (PyCFunction)glr_simps, 1, doc_glr_simps}, 
{"spline", (PyCFunction)glr_spline, 1, doc_glr_spline}, 
{"tmcon2", (PyCFunction)glr_tmcon2, 1, doc_glr_tmcon2}, 
{NULL, NULL}};

void glrsetstaticdims(ForthonObject *self)
{
   glr_farrays[38].dimensions[0]=(npy_intp)((int)(3) - (1) + 1);
   glr_farrays[39].dimensions[0]=(npy_intp)((int)(3) - (1) + 1);
   glr_farrays[40].dimensions[0]=(npy_intp)((int)(3) - (1) + 1);
   glr_farrays[41].dimensions[0]=(npy_intp)((int)(3) - (1) + 1);
   glr_farrays[42].dimensions[0]=(npy_intp)((int)(3) - (1) + 1);
   glr_farrays[43].dimensions[0]=(npy_intp)((int)(3) - (1) + 1);
   glr_farrays[139].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
   glr_farrays[140].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
   glr_farrays[141].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
   glr_farrays[142].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
   glr_farrays[143].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
   glr_farrays[144].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
   glr_farrays[145].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
   glr_farrays[146].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
   glr_farrays[147].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
   glr_farrays[148].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
   glr_farrays[149].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
   glr_farrays[150].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
   glr_farrays[235].dimensions[0]=(npy_intp)((int)(12) - (1) + 1);
   glr_farrays[236].dimensions[0]=(npy_intp)((int)(4) - (1) + 1);
   glr_farrays[251].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
   glr_farrays[252].dimensions[0]=(npy_intp)((int)(1000) - (1) + 1);
}

static void glrsetdimsFstor(char *name, long i)
{
  if (strcmp(name, "Fstor") || strcmp(name, "*")) {
  if (i == -1 || i == 0) {
   glr_farrays[0].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[0].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 1) {
   glr_farrays[1].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[1].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 2) {
   glr_farrays[2].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[2].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 3) {
   glr_farrays[3].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[3].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 4) {
   glr_farrays[4].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[4].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 5) {
   glr_farrays[5].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[5].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 6) {
   glr_farrays[6].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[6].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 7) {
   glr_farrays[7].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[7].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 8) {
   glr_farrays[8].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[8].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 9) {
   glr_farrays[9].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[9].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 10) {
   glr_farrays[10].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[10].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 11) {
   glr_farrays[11].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[11].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 12) {
   glr_farrays[12].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[12].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 13) {
   glr_farrays[13].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[13].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 14) {
   glr_farrays[14].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[14].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 15) {
   glr_farrays[15].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[15].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 16) {
   glr_farrays[16].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
  }
  if (i == -1 || i == 17) {
   glr_farrays[17].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
  }
  if (i == -1 || i == 18) {
   glr_farrays[18].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
  }
  if (i == -1 || i == 19) {
   glr_farrays[19].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
  }
  if (i == -1 || i == 20) {
   glr_farrays[20].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
  }
  if (i == -1 || i == 21) {
   glr_farrays[21].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
  }
  if (i == -1 || i == 22) {
   glr_farrays[22].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 23) {
   glr_farrays[23].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 24) {
   glr_farrays[24].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 25) {
   glr_farrays[25].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 26) {
   glr_farrays[26].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 27) {
   glr_farrays[27].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 28) {
   glr_farrays[28].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  }}
static void glrsetdimsMatrix(char *name, long i)
{
  if (strcmp(name, "Matrix") || strcmp(name, "*")) {
  if (i == -1 || i == 29) {
   glr_farrays[29].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
  }
  if (i == -1 || i == 30) {
   glr_farrays[30].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
   glr_farrays[30].dimensions[1]=(npy_intp)((int)(9) - (1) + 1);
  }
  if (i == -1 || i == 31) {
   glr_farrays[31].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
   glr_farrays[31].dimensions[1]=(npy_intp)((int)(9) - (1) + 1);
  }
  if (i == -1 || i == 32) {
   glr_farrays[32].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
   glr_farrays[32].dimensions[1]=(npy_intp)((int)(9) - (1) + 1);
  }
  if (i == -1 || i == 33) {
   glr_farrays[33].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
   glr_farrays[33].dimensions[1]=(npy_intp)((int)(3) - (1) + 1);
  }
  if (i == -1 || i == 34) {
   glr_farrays[34].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 35) {
   glr_farrays[35].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
  }
  if (i == -1 || i == 36) {
   glr_farrays[36].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
  }
  if (i == -1 || i == 37) {
   glr_farrays[37].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[9].data) - (1) + 1);
   glr_farrays[37].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
  }
  }}
static void glrsetdimsConst_4(char *name, long i)
{
  if (strcmp(name, "Const_4") || strcmp(name, "*")) {
  if (i == -1 || i == 44) {
   glr_farrays[44].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 45) {
   glr_farrays[45].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 46) {
   glr_farrays[46].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 47) {
   glr_farrays[47].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 48) {
   glr_farrays[48].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 49) {
   glr_farrays[49].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 50) {
   glr_farrays[50].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 51) {
   glr_farrays[51].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 52) {
   glr_farrays[52].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 53) {
   glr_farrays[53].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  }}
static void glrsetdimsConst_5(char *name, long i)
{
  if (strcmp(name, "Const_5") || strcmp(name, "*")) {
  if (i == -1 || i == 54) {
   glr_farrays[54].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[4].data) - (1) + 1);
  }
  if (i == -1 || i == 55) {
   glr_farrays[55].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[55].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[5].data) - (1) + 1);
  }
  if (i == -1 || i == 56) {
   glr_farrays[56].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
   glr_farrays[56].dimensions[1]=(npy_intp)((int)(2**(long *)glr_fscalars[5].data) - (1) + 1);
  }
  if (i == -1 || i == 57) {
   glr_farrays[57].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[4].data) - (1) + 1);
  }
  if (i == -1 || i == 58) {
   glr_farrays[58].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[58].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[5].data) - (1) + 1);
  }
  if (i == -1 || i == 59) {
   glr_farrays[59].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[6].data) - (1) + 1);
  }
  if (i == -1 || i == 60) {
   glr_farrays[60].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[6].data) - (1) + 1);
  }
  if (i == -1 || i == 61) {
   glr_farrays[61].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[6].data) - (1) + 1);
  }
  if (i == -1 || i == 62) {
   glr_farrays[62].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[6].data) - (1) + 1);
  }
  if (i == -1 || i == 63) {
   glr_farrays[63].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[6].data) - (1) + 1);
  }
  if (i == -1 || i == 64) {
   glr_farrays[64].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[6].data) - (1) + 1);
  }
  if (i == -1 || i == 65) {
   glr_farrays[65].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[6].data) - (1) + 1);
  }
  if (i == -1 || i == 66) {
   glr_farrays[66].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[6].data) - (1) + 1);
  }
  }}
static void glrsetdimsConst_7(char *name, long i)
{
  if (strcmp(name, "Const_7") || strcmp(name, "*")) {
  if (i == -1 || i == 67) {
   glr_farrays[67].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 68) {
   glr_farrays[68].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 69) {
   glr_farrays[69].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 70) {
   glr_farrays[70].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 71) {
   glr_farrays[71].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 72) {
   glr_farrays[72].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 73) {
   glr_farrays[73].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 74) {
   glr_farrays[74].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 75) {
   glr_farrays[75].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 76) {
   glr_farrays[76].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 77) {
   glr_farrays[77].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 78) {
   glr_farrays[78].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 79) {
   glr_farrays[79].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 80) {
   glr_farrays[80].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 81) {
   glr_farrays[81].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 82) {
   glr_farrays[82].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 83) {
   glr_farrays[83].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 84) {
   glr_farrays[84].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 85) {
   glr_farrays[85].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 86) {
   glr_farrays[86].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 87) {
   glr_farrays[87].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 88) {
   glr_farrays[88].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 89) {
   glr_farrays[89].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 90) {
   glr_farrays[90].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 91) {
   glr_farrays[91].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 92) {
   glr_farrays[92].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 93) {
   glr_farrays[93].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 94) {
   glr_farrays[94].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 95) {
   glr_farrays[95].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 96) {
   glr_farrays[96].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 97) {
   glr_farrays[97].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  }}
static void glrsetdimsConst_8(char *name, long i)
{
  if (strcmp(name, "Const_8") || strcmp(name, "*")) {
  if (i == -1 || i == 98) {
   glr_farrays[98].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 99) {
   glr_farrays[99].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 100) {
   glr_farrays[100].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 101) {
   glr_farrays[101].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 102) {
   glr_farrays[102].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 103) {
   glr_farrays[103].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 104) {
   glr_farrays[104].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 105) {
   glr_farrays[105].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
   glr_farrays[105].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 106) {
   glr_farrays[106].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
  }
  if (i == -1 || i == 107) {
   glr_farrays[107].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
  }
  if (i == -1 || i == 108) {
   glr_farrays[108].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
  }
  if (i == -1 || i == 109) {
   glr_farrays[109].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
  }
  if (i == -1 || i == 110) {
   glr_farrays[110].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
  }
  if (i == -1 || i == 111) {
   glr_farrays[111].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[111].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 112) {
   glr_farrays[112].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 113) {
   glr_farrays[113].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 114) {
   glr_farrays[114].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 115) {
   glr_farrays[115].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 116) {
   glr_farrays[116].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 117) {
   glr_farrays[117].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 118) {
   glr_farrays[118].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 119) {
   glr_farrays[119].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 120) {
   glr_farrays[120].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 121) {
   glr_farrays[121].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 122) {
   glr_farrays[122].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 123) {
   glr_farrays[123].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 124) {
   glr_farrays[124].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 125) {
   glr_farrays[125].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 126) {
   glr_farrays[126].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 127) {
   glr_farrays[127].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 128) {
   glr_farrays[128].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 129) {
   glr_farrays[129].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 130) {
   glr_farrays[130].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 131) {
   glr_farrays[131].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 132) {
   glr_farrays[132].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 133) {
   glr_farrays[133].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[133].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 134) {
   glr_farrays[134].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 135) {
   glr_farrays[135].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 136) {
   glr_farrays[136].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[136].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 137) {
   glr_farrays[137].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[137].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 138) {
   glr_farrays[138].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 151) {
   glr_farrays[151].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 152) {
   glr_farrays[152].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 153) {
   glr_farrays[153].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 154) {
   glr_farrays[154].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 155) {
   glr_farrays[155].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 156) {
   glr_farrays[156].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 157) {
   glr_farrays[157].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 158) {
   glr_farrays[158].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 159) {
   glr_farrays[159].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 160) {
   glr_farrays[160].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 161) {
   glr_farrays[161].dimensions[0]=(npy_intp)((int)(100) - (1) + 1);
  }
  if (i == -1 || i == 162) {
   glr_farrays[162].dimensions[0]=(npy_intp)((int)(100) - (1) + 1);
  }
  if (i == -1 || i == 163) {
   glr_farrays[163].dimensions[0]=(npy_intp)((int)(100) - (1) + 1);
  }
  if (i == -1 || i == 164) {
   glr_farrays[164].dimensions[0]=(npy_intp)((int)(100) - (1) + 1);
  }
  if (i == -1 || i == 165) {
   glr_farrays[165].dimensions[0]=(npy_intp)((int)(100) - (1) + 1);
  }
  if (i == -1 || i == 166) {
   glr_farrays[166].dimensions[0]=(npy_intp)((int)(100) - (1) + 1);
  }
  if (i == -1 || i == 167) {
   glr_farrays[167].dimensions[0]=(npy_intp)((int)(100) - (1) + 1);
  }
  if (i == -1 || i == 168) {
   glr_farrays[168].dimensions[0]=(npy_intp)((int)(100) - (1) + 1);
  }
  if (i == -1 || i == 169) {
   glr_farrays[169].dimensions[0]=(npy_intp)((int)(100) - (1) + 1);
  }
  if (i == -1 || i == 170) {
   glr_farrays[170].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 171) {
   glr_farrays[171].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 172) {
   glr_farrays[172].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 173) {
   glr_farrays[173].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 174) {
   glr_farrays[174].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 175) {
   glr_farrays[175].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 176) {
   glr_farrays[176].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 177) {
   glr_farrays[177].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 178) {
   glr_farrays[178].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 179) {
   glr_farrays[179].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[179].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 180) {
   glr_farrays[180].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 181) {
   glr_farrays[181].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 182) {
   glr_farrays[182].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 183) {
   glr_farrays[183].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 184) {
   glr_farrays[184].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 185) {
   glr_farrays[185].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 186) {
   glr_farrays[186].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 187) {
   glr_farrays[187].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 188) {
   glr_farrays[188].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 189) {
   glr_farrays[189].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 190) {
   glr_farrays[190].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 191) {
   glr_farrays[191].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 192) {
   glr_farrays[192].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 193) {
   glr_farrays[193].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 194) {
   glr_farrays[194].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 195) {
   glr_farrays[195].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 196) {
   glr_farrays[196].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
   glr_farrays[196].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 197) {
   glr_farrays[197].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
  }
  if (i == -1 || i == 198) {
   glr_farrays[198].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
  }
  if (i == -1 || i == 199) {
   glr_farrays[199].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
  }
  if (i == -1 || i == 200) {
   glr_farrays[200].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
  }
  if (i == -1 || i == 201) {
   glr_farrays[201].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
  }
  if (i == -1 || i == 202) {
   glr_farrays[202].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[202].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 203) {
   glr_farrays[203].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[203].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 204) {
   glr_farrays[204].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data-2) - (1) + 1);
   glr_farrays[204].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data-1) - (1) + 1);
  }
  if (i == -1 || i == 205) {
   glr_farrays[205].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[205].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 206) {
   glr_farrays[206].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 207) {
   glr_farrays[207].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[207].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 208) {
   glr_farrays[208].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[208].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 209) {
   glr_farrays[209].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 210) {
   glr_farrays[210].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 211) {
   glr_farrays[211].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 212) {
   glr_farrays[212].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 213) {
   glr_farrays[213].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 214) {
   glr_farrays[214].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 215) {
   glr_farrays[215].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 216) {
   glr_farrays[216].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 217) {
   glr_farrays[217].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 218) {
   glr_farrays[218].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 219) {
   glr_farrays[219].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 220) {
   glr_farrays[220].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
  }
  if (i == -1 || i == 221) {
   glr_farrays[221].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[3].data) - (1) + 1);
  }
  if (i == -1 || i == 222) {
   glr_farrays[222].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 223) {
   glr_farrays[223].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 224) {
   glr_farrays[224].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[224].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  }}
static void glrsetdimsGEnergy(char *name, long i)
{
  if (strcmp(name, "GEnergy") || strcmp(name, "*")) {
  if (i == -1 || i == 225) {
   glr_farrays[225].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[225].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 226) {
   glr_farrays[226].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[226].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 227) {
   glr_farrays[227].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[227].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 228) {
   glr_farrays[228].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
   glr_farrays[228].dimensions[1]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 229) {
   glr_farrays[229].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 230) {
   glr_farrays[230].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 231) {
   glr_farrays[231].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 232) {
   glr_farrays[232].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 233) {
   glr_farrays[233].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
   glr_farrays[233].dimensions[1]=(npy_intp)((int)(12) - (1) + 1);
  }
  if (i == -1 || i == 234) {
   glr_farrays[234].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
   glr_farrays[234].dimensions[1]=(npy_intp)((int)(4) - (1) + 1);
  }
  if (i == -1 || i == 237) {
   glr_farrays[237].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 238) {
   glr_farrays[238].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[1].data) - (1) + 1);
  }
  if (i == -1 || i == 239) {
   glr_farrays[239].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 240) {
   glr_farrays[240].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 241) {
   glr_farrays[241].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  if (i == -1 || i == 242) {
   glr_farrays[242].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[0].data) - (1) + 1);
  }
  }}
static void glrsetdimsGlrexec(char *name, long i)
{
  if (strcmp(name, "Glrexec") || strcmp(name, "*")) {
  if (i == -1 || i == 243) {
   glr_farrays[243].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
   glr_farrays[243].dimensions[1]=(npy_intp)((int)(1) - (1) + 1);
  }
  if (i == -1 || i == 244) {
   glr_farrays[244].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[7].data) - (1) + 1);
   glr_farrays[244].dimensions[1]=(npy_intp)((int)(1) - (1) + 1);
  }
  }}
static void glrsetdimsSplines(char *name, long i)
{
  if (strcmp(name, "Splines") || strcmp(name, "*")) {
  if (i == -1 || i == 245) {
   glr_farrays[245].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[265].data) - (1) + 1);
  }
  if (i == -1 || i == 246) {
   glr_farrays[246].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[265].data) - (1) + 1);
  }
  if (i == -1 || i == 247) {
   glr_farrays[247].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[264].data) - (1) + 1);
  }
  if (i == -1 || i == 248) {
   glr_farrays[248].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[264].data) - (1) + 1);
  }
  if (i == -1 || i == 249) {
   glr_farrays[249].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[264].data) - (1) + 1);
  }
  if (i == -1 || i == 250) {
   glr_farrays[250].dimensions[0]=(npy_intp)((int)(*(long *)glr_fscalars[264].data) - (1) + 1);
  }
  }}
void glrsetdims(char *name, ForthonObject *obj, long i)
{
  if (i == -1 || (0 <= i && i <= 28))  glrsetdimsFstor(name, i);
  if (i == -1 || (29 <= i && i <= 43))  glrsetdimsMatrix(name, i);
  if (i == -1 || (44 <= i && i <= 53))  glrsetdimsConst_4(name, i);
  if (i == -1 || (54 <= i && i <= 66))  glrsetdimsConst_5(name, i);
  if (i == -1 || (67 <= i && i <= 97))  glrsetdimsConst_7(name, i);
  if (i == -1 || (98 <= i && i <= 224))  glrsetdimsConst_8(name, i);
  if (i == -1 || (225 <= i && i <= 242))  glrsetdimsGEnergy(name, i);
  if (i == -1 || (243 <= i && i <= 244))  glrsetdimsGlrexec(name, i);
  if (i == -1 || (245 <= i && i <= 253))  glrsetdimsSplines(name, i);
}

void glrgrabscalarpointers_real_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  glr_fscalars[*i].data = (char *)p;
}
void glrgrabscalarpointers_float_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  glr_fscalars[*i].data = (char *)p;
}
void glrgrabscalarpointers_double_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  glr_fscalars[*i].data = (char *)p;
}
void glrgrabscalarpointers_integer_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  glr_fscalars[*i].data = (char *)p;
}
void glrgrabscalarpointers_character_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  glr_fscalars[*i].data = (char *)p;
}
void glrgrabscalarpointers_logical_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  glr_fscalars[*i].data = (char *)p;
}
void glrgrabscalarpointers_complex_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  glr_fscalars[*i].data = (char *)p;
}
void glrsetderivedtypepointers_(long *i, char **p)
{
  /* Gabs pointer for the scalar */
  glr_fscalars[*i].data = (char *)(*p);
}
void glrgrabarraypointers_real_(long *i, char *p)
{
  /* Grabs pointer for the array */
  glr_farrays[*i].data.s = (char *)p;
}
void glrgrabarraypointers_float_(long *i, char *p)
{
  /* Grabs pointer for the array */
  glr_farrays[*i].data.s = (char *)p;
}
void glrgrabarraypointers_double_(long *i, char *p)
{
  /* Grabs pointer for the array */
  glr_farrays[*i].data.s = (char *)p;
}
void glrgrabarraypointers_integer_(long *i, char *p)
{
  /* Grabs pointer for the array */
  glr_farrays[*i].data.s = (char *)p;
}
void glrgrabarraypointers_character_(long *i, char *p)
{
  /* Grabs pointer for the array */
  glr_farrays[*i].data.s = (char *)p;
}
void glrgrabarraypointers_logical_(long *i, char *p)
{
  /* Grabs pointer for the array */
  glr_farrays[*i].data.s = (char *)p;
}
void glrgrabarraypointers_complex_(long *i, char *p)
{
  /* Grabs pointer for the array */
  glr_farrays[*i].data.s = (char *)p;
}
void glrgrabarraypointersobj_(Fortranarray *farray, char *p)
{
  /* Grabs pointer for the array */
  farray->data.s = (char *)p;
}
void glrsetarraydims_(Fortranarray *farray, long *dims)
{
  int id;
  for (id=0;id<farray->nd;id++)
    farray->dimensions[id] = (npy_intp)(dims[id]);
}
void initglrobject(PyObject *module)
{
  glrObject=(ForthonObject *)PyObject_GC_New(ForthonObject, &ForthonType);
  glrObject->name = "glr";
  glrObject->typename = "glr";
  glrObject->nscalars = glrnscalars;
  glrObject->fscalars = glr_fscalars;
  glrObject->narrays = glrnarrays;
  glrObject->farrays = glr_farrays;
  glrObject->setdims = *glrsetdims;
  glrObject->setstaticdims = *glrsetstaticdims;
  glrObject->fmethods = glr_methods;
  glrObject->__module__ = Py_BuildValue("s", "flora");
  glrObject->fobj = NULL;
  glrObject->fobjdeallocate = NULL;
  glrObject->nullifycobj = NULL;
  glrObject->allocated = 0;
  glrObject->garbagecollected = 0;
  PyModule_AddObject(module, "glr", (PyObject *)glrObject);
  glrdeclarevars(glrObject);
  Forthon_BuildDicts(glrObject);
  ForthonPackage_allotdims(glrObject);
  glrpasspointers_();
  glrnullifypointers_();
  ForthonPackage_staticarrays(glrObject);
  {
  PyObject *s;
  s = Py_BuildValue("(s)", "*");
  ForthonPackage_gallot((PyObject *)glrObject, s);
  Py_XDECREF(s);
  }
  {
  PyObject *m, *d, *f, *r;
  r = NULL;
  m = PyImport_ImportModule("Forthon");
  if (m != NULL) {
    d = PyModule_GetDict(m);
    if (d != NULL) {
      f = PyDict_GetItemString(d, "registerpackage");
      if (f != NULL) {
        r = PyObject_CallFunction(f, "Os", (PyObject *)glrObject, "glr");
  }}}
  if (NULL == r) {
    if (PyErr_Occurred()) PyErr_Print();
    Py_FatalError("unable to find a compatible Forthon module in which to register module glr");
  }
  Py_XDECREF(m);
  Py_XDECREF(r);
  }
}
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "glrpy", /* m_name */
  "glr", /* m_doc */
  -1,                  /* m_size */
  glr_methods,    /* m_methods */
  NULL,                /* m_reload */
  NULL,                /* m_traverse */
  NULL,                /* m_clear */
  NULL,                /* m_free */
  };
PyMODINIT_FUNC
PyInit_glrpy(void)
{
  PyObject *m;
  if (PyType_Ready(&ForthonType) < 0)
    return NULL;
  m = PyModule_Create(&moduledef);
  import_array();
  initglrobject(m);
  ErrorObject = PyErr_NewException("glrpy.error", NULL, NULL);
  PyModule_AddObject(m, "glrerror", ErrorObject);
  PyModule_AddObject(m, "fcompname", PyUnicode_FromString("gfortran"));
  PyModule_AddObject(m, "realsize", PyLong_FromLong((long)8));
  if (PyErr_Occurred()) {
    PyErr_Print();
    Py_FatalError("can not initialize module glr");
    }
  return m;
}

