# WatpropPy
## A version of the WATPROP water properties library designed for use with Python

The venerable WATPROP library of steam table routines for Microsoft EXCEL is now almost 30 years old.
What began as an EXCEL add-in implementation of the Westinghouse HOH routines transitioned to
modeling the ASME steam tables, followed by the IAPWS 1967 Release (the source of the ASME steam tables),
and finally the IAPWS 1997 Release.  Now, with the success of Python and Jupyter notebooks,
it's time for WATPROP to move beyond EXCEL.

But then why continue to use WATPROP?  Why not transition to another Python IAPWS library?
The primary argument for WATPROP in Python is consistency of results.  Different libraries
use different iterative methods when seeking the roots of polynomials, leading to slightly different
results in some applications.  Alternatively, using the (more recent) "backward" equations
can introduce additional differences in results.  These differences may impact the results of
numerical models when steam tables are used as inputs to engineering work.

WatpropPy is still in development.  At this time the interface remains close to the original
WATPROP API.  For example, to determine the enthalpy at 2250 psia and 546 deg F the function
call would be H_PT(22050, 547).  Available units are English (the default) and SI.

Compilation and testing require a C++ compiler (compliant with C++11) and the following Python packages:

- Python (version >= 3.10)
- Cython
- python-abi3
- pytest

