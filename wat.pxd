##
#	\file wat.pxd
#
##

##
# Copyright (c) 2022 Charles Alan Ford
# 
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
# 
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
##

cdef extern from "wat.h":
    enum Units:
        SI = 0
        ENGLISH = 1
    double _H_PT(double p, double t, Units iunits, Units ounits) except +
    double _V_PT(double p, double t, Units iunits, Units ounits) except +
    double _W_PT(double p, double t, Units iunits, Units ounits) except +
    double _HF_T(double t, Units iunits, Units ounits) except +
    double _HG_T(double t, Units iunits, Units ounits) except +
    double _P_T(double t, Units iunits, Units ounits) except +
    double _T_P(double p, Units iunits, Units ounits) except +
    double _S_PT(double p, double t, Units iunits, Units ounits) except +
    double _CP_PT(double p, double t, Units iunits, Units ounits) except +
    double _VIS_PT(double p, double t, Units iunits, Units ounits) except +
    double _K_PT(double p, double t, Units iunits, Units ounits) except +
    double _SF_T(double t, Units iunits, Units ounits) except +
    double _SG_T(double t, Units iunits, Units ounits) except +
    double _HF_P(double p, Units iunits, Units ounits) except +
    double _HG_P(double p, Units iunits, Units ounits) except +
    double _VF_P(double p, Units iunits, Units ounits) except +
    double _VG_P(double p, Units iunits, Units ounits) except +
    double _SF_P(double p, Units iunits, Units ounits) except +
    double _SG_P(double p, Units iunits, Units ounits) except +
    double _T_PH(double p, double h, Units iunits, Units ounits) except +
    double _V_PH(double p, double h, Units iunits, Units ounits) except +
    double _S_PH(double p, double h, Units iunits, Units ounits) except +



