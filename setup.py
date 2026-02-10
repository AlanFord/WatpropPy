from setuptools import setup, Extension
from Cython.Build import cythonize

MIN_PY = "0x030A0000"  # Python 3.10 baseline

ext = Extension("WatpropPy",
                language='c++',
                sources=["watprop.pyx", "wat.cpp", "mymath.cpp", "region.cpp", "region1.cpp", "region2.cpp", "region3.cpp", "region4.cpp", "region5.cpp", "region23.cpp", "utilities.cpp"],
                define_macros=[
                    ("Py_LIMITED_API", MIN_PY),
                    ("PY_SSIZE_T_CLEAN", None),
                ],
                py_limited_api=True)

setup(name='WatpropPy',
    version='0.0.1',
    author= 'Alan Ford',
    ext_modules=(cythonize([ext],language_level = "3")),
    zip_safe=False,
)
