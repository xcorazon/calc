/* Для правильной компиляции в кодировке UTF-8 под Windows
   этот файл должен быть в кодировке UTF-8 BOM
   http://stackoverflow.com/questions/688760/how-to-create-a-utf-8-string-literal-in-visual-c-2008
*/
#include <Python.h>
#include <wchar.h>
#include "unitest.h"

extern const char *appName = "PythonUniTest";

static PyObject *uni_hello(PyObject *self) {
  wchar_t *hello = L"Привет!";
  PyObject *res;
  //char errors[1024];
  
  res = PyUnicode_FromUnicode(hello, (Py_ssize_t)wcslen(hello));
  if(res == NULL){
    Py_RETURN_NONE;
  } else {
    return res;
  }
  
}

static PyObject *UHelloError;

#ifndef PyMODINIT_FUNC /*declarations for DLL import/export*/
#define PyMODINIT_FUNC void
#endif

PyMODINIT_FUNC initunic(void)
{
  PyObject *m;

  m = Py_InitModule("unic", UHelloMethods);
  if (m == NULL)
    return;

  UHelloError = PyErr_NewException("unic.error", NULL, NULL);
  Py_INCREF(UHelloError);
  PyModule_AddObject(m, "error", UHelloError);
}

#ifndef OS_WINDOWS
int main(int argc, char *argv[])
{
    /* Pass argv[0] to the Python interpreter */
    Py_SetProgramName(argv[0]);

    /* Initialize the Python interpreter.  Required. */
    Py_Initialize();

    /* Add a static module */
    initunic();

    return 0;
}
#endif