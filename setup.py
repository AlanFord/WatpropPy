from setuptools import setup, Extension
from Cython.Build import cythonize

ext = Extension("water",
                language='c++',
                sources=["watprop.pyx", "wat.cpp", "mymath.cpp", "region.cpp", "region1.cpp", "region2.cpp", "region3.cpp", "region4.cpp", "region5.cpp", "region23.cpp"])

setup(name='water2',
    ext_modules=(cythonize([ext],language_level = "3")),
    zip_safe=False,
)
