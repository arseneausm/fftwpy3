#include <stdio.h>
#include <stdlib.h>
#include <io.h>

#include <Python.h>

/* PyObject tells the python interpreter to treat a pointer to an object as an object */

static PyObject *method_fputs(PyObject *self, PyObject *args) {
	/*	
	 *str: string to write
	 *filename: file to write to
	*/

	char *str, *filename = NULL;
	int bytes_copied = -1;

	/*
	PyArg_ParseTuple:
	  - args are a type of PyObject
	  - "ss" is a format specifier telling the data type
	  - &str and &filename point to local variables 
	*/
	
	if(!PyArg_ParseTuple(args, "ss", &str, &filename)) {
		return NULL;
	}

	/* passing the name of the file */

	FILE *fp = fopen(filename, "w");
	bytes_copied = fputs(str, fp);
	fclose(fp);

	return PyLong_FromLong(bytes_copied);

}	

static PyMethodDef FputsMethods[] = {
	/* name to call | name of function | number of args | final string */
	{"fputs", method_fputs, METH_VARARGS, "Python interface for fputs C library function"},
    {NULL, NULL, 0, NULL}
};

/* https://docs.python.org/3/c-api/module.html#c.PyModuleDef */
static struct PyModuleDef fputsmodule = {
	PyModuleDef_HEAD_INIT,
	"fputs",
	"Python interface for the fputs C library function",
	-1,
	FputsMethods
};

PyMODINIT_FUNC PyInit_fputs(void) {
	return PyModule_Create(&fputsmodule);
}
