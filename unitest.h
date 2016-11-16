
static PyObject *uni_hello(PyObject *self);

static PyMethodDef UHelloMethods[] = {
    {"hello",  uni_hello, METH_NOARGS, "Get \"Hello\" string."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};