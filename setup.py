from setuptools import setup, Extension
from Cython.Build import cythonize

ext = Extension("water",
                sources=["watprop.pyx", "wat.cpp"])

setup(name='water2',
    ext_modules=(cythonize([ext],language_level = "3")),
    zip_safe=False,
)
