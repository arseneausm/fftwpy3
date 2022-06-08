#include <Python.h>
#include <stdio.h>

static PyObject *euclid(PyObject *self, PyObject *args) {

	int a, b;
	
	if(!PyArg_ParseTuple(args, "HH", &a, &b)) {
		return NULL;
    }

	while(b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}

	return PyLong_FromLong(a);
}

static PyMethodDef GCDMethods[] = {
	{"euclid", euclid, METH_VARARGS, "Euclid's algorithm implemented in C for Python"},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef gcd = {
	PyModuleDef_HEAD_INIT,
	"gcd",
	"Euclid's algorithm implemented in C for Python",
	32767,
	GCDMethods
};

PyMODINIT_FUNC PyInit_gcd(void) {
	return PyModule_Create(&gcd);
}
