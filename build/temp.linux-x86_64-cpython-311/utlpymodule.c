#include "Forthon.h"
#include <setjmp.h>
ForthonObject *utlObject;
extern jmp_buf stackenvironment;
extern int lstackenvironmentset;
extern void utlpasspointers_(void);
extern void utlnullifypointers_(void);
extern long a2i_(FSTRING string, int sl0);
extern void pausef_(long *t);
extern void utlinit_(void);
extern void wmm_(double *a, long *m, long *n, FSTRING astr, FSTRING fname, int sl0, int sl1);

extern void utlsetarraypointercmdline0_(char *p__, char *fobj__, npy_intp *dims__);
extern void utlsetarraypointercodename_(char *p__, char *fobj__, npy_intp *dims__);
extern void utlsetarraypointercodedate_(char *p__, char *fobj__, npy_intp *dims__);
extern void utlsetarraypointercodetime_(char *p__, char *fobj__, npy_intp *dims__);
extern void utlsetarraypointerrundate_(char *p__, char *fobj__, npy_intp *dims__);
extern void utlsetarraypointerruntime_(char *p__, char *fobj__, npy_intp *dims__);
extern void utlsetarraypointerrunnode_(char *p__, char *fobj__, npy_intp *dims__);
extern void utlsetarraypointerprobid_(char *p__, char *fobj__, npy_intp *dims__);
extern void utlsetarraypointernote_(char *p__, char *fobj__, npy_intp *dims__);
extern void utlsetarraypointercode_ts_(char *p__, char *fobj__, npy_intp *dims__);
extern void utlsetarraypointerrun_ts_(char *p__, char *fobj__, npy_intp *dims__);
extern void utlsetarraypointersession_(char *p__, char *fobj__, npy_intp *dims__);
extern void utlsetarraypointerprobname__(char *p__, char *fobj__, npy_intp *dims__);

extern Fortranscalar glr_fscalars[];
int utlnscalars = 4;
Fortranscalar utl_fscalars[4]={
{NPY_LONG,"integer","logunit",NULL,"CodeInfo"," CodeInfo ","Unit number for session log file","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","debug_",NULL,"CommandLine"," CommandLine ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","echo_",NULL,"CommandLine"," CommandLine ","","",0,0,NULL,NULL,NULL,NULL},
{NPY_LONG,"integer","verbose_",NULL,"CommandLine"," CommandLine ","","",0,0,NULL,NULL,NULL,NULL}};
int utlnarrays = 13;
static Fortranarray utl_farrays[13]={
{NPY_STRING,0,1,NULL,"cmdline0",{NULL},NULL,NULL,NULL,NULL,0,NULL,"CodeInfo"," CodeInfo ","Original command line","",""},
{NPY_STRING,0,1,NULL,"codename",{NULL},NULL,NULL,NULL,NULL,0,NULL,"CodeInfo"," CodeInfo ","Name of executable","",""},
{NPY_STRING,0,1,NULL,"codedate",{NULL},NULL,NULL,NULL,NULL,0,NULL,"CodeInfo"," CodeInfo ","Date of build","",""},
{NPY_STRING,0,1,NULL,"codetime",{NULL},NULL,NULL,NULL,NULL,0,NULL,"CodeInfo"," CodeInfo ","Time of build","",""},
{NPY_STRING,0,1,NULL,"rundate",{NULL},NULL,NULL,NULL,NULL,0,NULL,"CodeInfo"," CodeInfo ","Date of execution","",""},
{NPY_STRING,0,1,NULL,"runtime",{NULL},NULL,NULL,NULL,NULL,0,NULL,"CodeInfo"," CodeInfo ","Time of execution","",""},
{NPY_STRING,0,1,NULL,"runnode",{NULL},NULL,NULL,NULL,NULL,0,NULL,"CodeInfo"," CodeInfo ","Note of execution","",""},
{NPY_STRING,0,1,NULL,"probid",{NULL},NULL,NULL,NULL,NULL,0,NULL,"CodeInfo"," CodeInfo ","Problem identification string","",""},
{NPY_STRING,0,1,NULL,"note",{NULL},NULL,NULL,NULL,NULL,0,NULL,"CodeInfo"," CodeInfo ","Problem comment string","",""},
{NPY_STRING,0,1,NULL,"code_ts",{NULL},NULL,NULL,NULL,NULL,0,NULL,"CodeInfo"," CodeInfo ","Code time stamp","",""},
{NPY_STRING,0,1,NULL,"run_ts",{NULL},NULL,NULL,NULL,NULL,0,NULL,"CodeInfo"," CodeInfo ","Run time stamp","",""},
{NPY_STRING,0,1,NULL,"session",{NULL},NULL,NULL,NULL,NULL,0,NULL,"CodeInfo"," CodeInfo ","Session identification","",""},
{NPY_STRING,0,1,NULL,"probname_",{NULL},NULL,NULL,NULL,NULL,0,NULL,"CommandLine"," CommandLine ","","",""}};
void utldeclarevars(ForthonObject *obj) {
}
static char doc_utl_a2i[] = "a2i(string:string)\nConvert string to integer";
static PyObject *
utl_a2i(PyObject *self, PyObject *args)
{
  PyObject * pyobj[1];
  PyArrayObject * ax[1];
  int i;
  char e[256];
  FSTRING fstr[1];
  PyObject * ret_val;
  long r;
  for (i=0;i<1;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "O", &pyobj[0])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_STRING)) {
    sprintf(e, "Argument string in a2i has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_STRING);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument string in a2i");
    PyErr_SetString(ErrorObject, e);
    goto err;}
 FSETSTRING(fstr[0], PyArray_BYTES(ax[0]), PyArray_ITEMSIZE(ax[0]));
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  r = 
a2i_(fstr[0], (int)PyArray_ITEMSIZE(ax[0]));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(1, pyobj, ax);
  ret_val = Py_BuildValue ("l", r);
  return ret_val;
err:
  for (i=0;i<1;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}
static char doc_utl_pausef[] = "pausef(t:integer)\nInterruptable sleep for t seconds";
static PyObject *
utl_pausef(PyObject *self, PyObject *args)
{
  PyObject * pyobj[1];
  PyArrayObject * ax[1];
  int i;
  char e[256];
  for (i=0;i<1;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "O", &pyobj[0])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_LONG)) {
    sprintf(e, "Argument t in pausef has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_LONG);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument t in pausef");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
pausef_((long *)(PyArray_BYTES(ax[0])));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(1, pyobj, ax);
  returnnone;
err:
  for (i=0;i<1;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}
static char doc_utl_utlinit[] = "utlinit\nInitialization routine";
static PyObject *
utl_utlinit(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) return NULL;
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
utlinit_();
  lstackenvironmentset--;
  returnnone;
err:
  return NULL;
}
static char doc_utl_wmm[] = "wmm(a:real,m:integer,n:integer,astr:string,fname:string)\nWrite matrix a in Matrix Market format for MatView";
static PyObject *
utl_wmm(PyObject *self, PyObject *args)
{
  PyObject * pyobj[5];
  PyArrayObject * ax[5];
  int i;
  char e[256];
  FSTRING fstr[2];
  for (i=0;i<5;i++) ax[i] = NULL;
  if (!PyArg_ParseTuple(args, "OOOOO", &pyobj[0], &pyobj[1], &pyobj[2], &pyobj[3], &pyobj[4])) return NULL;
  if (!Forthon_checksubroutineargtype(pyobj[0], NPY_DOUBLE)) {
    sprintf(e, "Argument a in wmm has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[0] = FARRAY_FROMOBJECT(pyobj[0], NPY_DOUBLE);
  if (ax[0] == NULL) {
    sprintf(e, "There is an error in argument a in wmm");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[1], NPY_LONG)) {
    sprintf(e, "Argument m in wmm has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[1] = FARRAY_FROMOBJECT(pyobj[1], NPY_LONG);
  if (ax[1] == NULL) {
    sprintf(e, "There is an error in argument m in wmm");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[2], NPY_LONG)) {
    sprintf(e, "Argument n in wmm has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[2] = FARRAY_FROMOBJECT(pyobj[2], NPY_LONG);
  if (ax[2] == NULL) {
    sprintf(e, "There is an error in argument n in wmm");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  if (!Forthon_checksubroutineargtype(pyobj[3], NPY_STRING)) {
    sprintf(e, "Argument astr in wmm has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[3] = FARRAY_FROMOBJECT(pyobj[3], NPY_STRING);
  if (ax[3] == NULL) {
    sprintf(e, "There is an error in argument astr in wmm");
    PyErr_SetString(ErrorObject, e);
    goto err;}
 FSETSTRING(fstr[0], PyArray_BYTES(ax[3]), PyArray_ITEMSIZE(ax[3]));
  if (!Forthon_checksubroutineargtype(pyobj[4], NPY_STRING)) {
    sprintf(e, "Argument fname in wmm has the wrong type");
    PyErr_SetString(ErrorObject, e);
    goto err;}
  ax[4] = FARRAY_FROMOBJECT(pyobj[4], NPY_STRING);
  if (ax[4] == NULL) {
    sprintf(e, "There is an error in argument fname in wmm");
    PyErr_SetString(ErrorObject, e);
    goto err;}
 FSETSTRING(fstr[1], PyArray_BYTES(ax[4]), PyArray_ITEMSIZE(ax[4]));
  if (!(lstackenvironmentset++) && setjmp(stackenvironment)) goto err;
  
wmm_((double *)(PyArray_BYTES(ax[0])), (long *)(PyArray_BYTES(ax[1])), (long *)(PyArray_BYTES(ax[2])), fstr[0], fstr[1], (int)PyArray_ITEMSIZE(ax[3]), (int)PyArray_ITEMSIZE(ax[4]));
  lstackenvironmentset--;
  Forthon_restoresubroutineargs(5, pyobj, ax);
  returnnone;
err:
  for (i=0;i<5;i++)
    if (ax[i] != NULL) {Py_XDECREF(ax[i]);}
  return NULL;
}

static struct PyMethodDef utl_methods[] = {
{"a2i", (PyCFunction)utl_a2i, 1, doc_utl_a2i}, 
{"pausef", (PyCFunction)utl_pausef, 1, doc_utl_pausef}, 
{"utlinit", (PyCFunction)utl_utlinit, 1, doc_utl_utlinit}, 
{"wmm", (PyCFunction)utl_wmm, 1, doc_utl_wmm}, 
{NULL, NULL}};

void utlsetstaticdims(ForthonObject *self)
{
   utl_farrays[0].dimensions[0]=(npy_intp)((int)(128) - (1) + 1);
   utl_farrays[1].dimensions[0]=(npy_intp)((int)(128) - (1) + 1);
   utl_farrays[2].dimensions[0]=(npy_intp)((int)(8) - (1) + 1);
   utl_farrays[3].dimensions[0]=(npy_intp)((int)(8) - (1) + 1);
   utl_farrays[4].dimensions[0]=(npy_intp)((int)(8) - (1) + 1);
   utl_farrays[5].dimensions[0]=(npy_intp)((int)(8) - (1) + 1);
   utl_farrays[6].dimensions[0]=(npy_intp)((int)(8) - (1) + 1);
   utl_farrays[7].dimensions[0]=(npy_intp)((int)(80) - (1) + 1);
   utl_farrays[8].dimensions[0]=(npy_intp)((int)(80) - (1) + 1);
   utl_farrays[9].dimensions[0]=(npy_intp)((int)(13) - (1) + 1);
   utl_farrays[10].dimensions[0]=(npy_intp)((int)(28) - (1) + 1);
   utl_farrays[11].dimensions[0]=(npy_intp)((int)(80) - (1) + 1);
   utl_farrays[12].dimensions[0]=(npy_intp)((int)(32) - (1) + 1);
}

void utlsetdims(char *name, ForthonObject *obj, long i)
{
}

void utlgrabscalarpointers_real_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  utl_fscalars[*i].data = (char *)p;
}
void utlgrabscalarpointers_float_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  utl_fscalars[*i].data = (char *)p;
}
void utlgrabscalarpointers_double_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  utl_fscalars[*i].data = (char *)p;
}
void utlgrabscalarpointers_integer_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  utl_fscalars[*i].data = (char *)p;
}
void utlgrabscalarpointers_character_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  utl_fscalars[*i].data = (char *)p;
}
void utlgrabscalarpointers_logical_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  utl_fscalars[*i].data = (char *)p;
}
void utlgrabscalarpointers_complex_(long *i, char *p)
{
  /* Gabs pointer for the scalar */
  utl_fscalars[*i].data = (char *)p;
}
void utlsetderivedtypepointers_(long *i, char **p)
{
  /* Gabs pointer for the scalar */
  utl_fscalars[*i].data = (char *)(*p);
}
void utlgrabarraypointers_real_(long *i, char *p)
{
  /* Grabs pointer for the array */
  utl_farrays[*i].data.s = (char *)p;
}
void utlgrabarraypointers_float_(long *i, char *p)
{
  /* Grabs pointer for the array */
  utl_farrays[*i].data.s = (char *)p;
}
void utlgrabarraypointers_double_(long *i, char *p)
{
  /* Grabs pointer for the array */
  utl_farrays[*i].data.s = (char *)p;
}
void utlgrabarraypointers_integer_(long *i, char *p)
{
  /* Grabs pointer for the array */
  utl_farrays[*i].data.s = (char *)p;
}
void utlgrabarraypointers_character_(long *i, char *p)
{
  /* Grabs pointer for the array */
  utl_farrays[*i].data.s = (char *)p;
}
void utlgrabarraypointers_logical_(long *i, char *p)
{
  /* Grabs pointer for the array */
  utl_farrays[*i].data.s = (char *)p;
}
void utlgrabarraypointers_complex_(long *i, char *p)
{
  /* Grabs pointer for the array */
  utl_farrays[*i].data.s = (char *)p;
}
void utlgrabarraypointersobj_(Fortranarray *farray, char *p)
{
  /* Grabs pointer for the array */
  farray->data.s = (char *)p;
}
void utlsetarraydims_(Fortranarray *farray, long *dims)
{
  int id;
  for (id=0;id<farray->nd;id++)
    farray->dimensions[id] = (npy_intp)(dims[id]);
}
void initutlobject(PyObject *module)
{
  utlObject=(ForthonObject *)PyObject_GC_New(ForthonObject, &ForthonType);
  utlObject->name = "utl";
  utlObject->typename = "utl";
  utlObject->nscalars = utlnscalars;
  utlObject->fscalars = utl_fscalars;
  utlObject->narrays = utlnarrays;
  utlObject->farrays = utl_farrays;
  utlObject->setdims = *utlsetdims;
  utlObject->setstaticdims = *utlsetstaticdims;
  utlObject->fmethods = utl_methods;
  utlObject->__module__ = Py_BuildValue("s", "flora");
  utlObject->fobj = NULL;
  utlObject->fobjdeallocate = NULL;
  utlObject->nullifycobj = NULL;
  utlObject->allocated = 0;
  utlObject->garbagecollected = 0;
  PyModule_AddObject(module, "utl", (PyObject *)utlObject);
  utldeclarevars(utlObject);
  Forthon_BuildDicts(utlObject);
  ForthonPackage_allotdims(utlObject);
  utlpasspointers_();
  utlnullifypointers_();
  ForthonPackage_staticarrays(utlObject);
  {
  PyObject *s;
  s = Py_BuildValue("(s)", "*");
  ForthonPackage_gallot((PyObject *)utlObject, s);
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
        r = PyObject_CallFunction(f, "Os", (PyObject *)utlObject, "utl");
  }}}
  if (NULL == r) {
    if (PyErr_Occurred()) PyErr_Print();
    Py_FatalError("unable to find a compatible Forthon module in which to register module utl");
  }
  Py_XDECREF(m);
  Py_XDECREF(r);
  }
}
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "utlpy", /* m_name */
  "utl", /* m_doc */
  -1,                  /* m_size */
  utl_methods,    /* m_methods */
  NULL,                /* m_reload */
  NULL,                /* m_traverse */
  NULL,                /* m_clear */
  NULL,                /* m_free */
  };
PyMODINIT_FUNC
PyInit_utlpy(void)
{
  PyObject *m;
  if (PyType_Ready(&ForthonType) < 0)
    return NULL;
  m = PyModule_Create(&moduledef);
  import_array();
  initutlobject(m);
  ErrorObject = PyErr_NewException("utlpy.error", NULL, NULL);
  PyModule_AddObject(m, "utlerror", ErrorObject);
  PyModule_AddObject(m, "fcompname", PyUnicode_FromString("gfortran"));
  PyModule_AddObject(m, "realsize", PyLong_FromLong((long)8));
  if (PyErr_Occurred()) {
    PyErr_Print();
    Py_FatalError("can not initialize module utl");
    }
  return m;
}

