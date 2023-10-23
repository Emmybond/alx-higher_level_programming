void print_python_list(PyObject *p)
{
    setbuf(stdout, NULL);  // Ensure unbuffered output
    if (!PyList_Check(p)) {
        printf("Invalid PyListObject\n");
        return;
    }

    int size = PyList_GET_SIZE(p);
    printf("[*] Python list info\n");
    printf("Size of the Python List = %d\n", size);

    // Print the elements of the list
    for (int i = 0; i < size; i++) {
        PyObject *item = PyList_GET_ITEM(p, i);
        printf("Element %d: %s\n", i, Py_TYPE(item)->tp_name);
    }
}


void print_python_bytes(PyObject *p)
{
    setbuf(stdout, NULL);  // Ensure unbuffered output
    if (!PyBytes_Check(p)) {
        printf("Invalid PyBytesObject\n");
        return;
    }

    int size = PyBytes_GET_SIZE(p);
    printf("[.] bytes object info\n");
    printf("Size of the bytes object = %d\n");
    printf("First %d bytes: ", size < 10 ? size : 10);

    const char *data = PyBytes_AS_STRING(p);
    for (int i = 0; i < (size < 10 ? size : 10); i++) {
        printf("%02hhx", data[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }

    if (size > 10) {
        printf("...");
    }

    printf("\n");
}

void print_python_float(PyObject *p)
{
    setbuf(stdout, NULL);  // Ensure unbuffered output
    if (!PyFloat_Check(p)) {
        printf("Invalid PyFloatObject\n");
        return;
    }

    double value = PyFloat_AS_DOUBLE(p);
    printf("[.] float object info\n");
    printf("Value: %f\n", value);
}

