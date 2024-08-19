#!/usr/bin/python3

void print_python_list(PyObject *p); {
    if (PyList_Check(p)) {
        Py_ssize_t size = PyObject_Length(p);
        Py_ssize_t i;

        printf("[*] Python list info\n");
        printf("[*] Size of the Python List = %ld\n", size);
        printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

        for (i = 0; i < size; i++) {
            PyObject *item = PyList_GetItem(p, i);
            printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
        }
    } else {
        printf("[*] Invalid List Object\n");
    }
}


void print_python_bytes(PyObject *p); {
    if (PyBytes_Check(p)) {
        Py_ssize_t size = ((PyVarObject *)p)->ob_size;
        Py_ssize_t i;
        char *data = ((PyBytesObject *)p)->ob_sval;

        printf("[.] bytes object info\n");
        printf("  [**] Size: %ld\n", size);
        printf("  [**] trying string: %s\n", data);

        if (size > 10)
            size = 10;

        printf("  [**] first %ld bytes: ", size);
        for (i = 0; i < size; i++) {
            printf("%02x", data[i] & 0xff);
            if (i < size - 1)
                printf(" ");
        }
        printf("\n");
    } else {
        printf("[.] Invalid Bytes Object\n");
    }
}

