#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <string>

template <class T>
inline void print(T const &a) {
    std::cout << a << std::endl;
}

/// Intentionally re_unplayplay and not re_unplayplay_python,
/// because we're renaming it later on in setup.py
PYBIND11_MODULE(re_unplayplay, m) {
    m.def("testprint", &print<std::string>)
        .def("testprint", &print<int>)
        .def("testprint", &print<double>);
}