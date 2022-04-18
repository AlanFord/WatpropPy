##
#	\file watprop.pyx
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

cimport wat

cpdef enum units:
	si = wat.Units.SI
	english = wat.Units.ENGLISH

# functions of (p,t)

def cp_pt(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the heat capacity of water/steam as a function of pressure and temperature'''
	return wat.CP_PT(p, t, iunits, ounits)

def h_pt(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific enthalpy of water/steam as a function of pressure and temperature'''
	return wat.H_PT(p, t, iunits, ounits)

def k_pt(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the thermal conductivity of water/steam as a function of pressure and temperature'''
	return wat.K_PT(p, t, iunits, ounits)

def s_pt(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific entropy of water/steam as a function of pressure and temperature'''
	return wat.S_PT(p, t, iunits, ounits)

def v_pt(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific volume of water/steam as a function of pressure and temperature'''
	return wat.V_PT(p, t, iunits, ounits)

def vis_pt(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the dynamic viscosity of water/steam as a function of pressure and temperature'''
	return wat.VIS_PT(p, t, iunits, ounits)

def w_pt(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the speed of sound in water/steam as a function of pressure and temperature'''
	return wat.W_PT(p, t, iunits, ounits)

# functions of (t)

def p_t(double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the saturation pressure of water/steam as a function of temperature'''
	return wat.P_T(t, iunits, ounits)

def hf_t(double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific enthalpy of water at saturation conditions as a function of temperature'''
	return wat.HF_T(t, iunits, ounits)

def hg_t(double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific enthalpy of steam at saturation conditions as a function of temperature'''
	return wat.HG_T(t, iunits, ounits)

def sf_t(double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific entropy of water at saturation conditions as a function of temperature'''
	return wat.SF_T(t, iunits, ounits)

def sg_t(double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific entropy of steam at saturation conditions as a function of temperature'''
	return wat.SG_T(t, iunits, ounits)

def vf_t(double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific volume of water at saturation conditions as a function of temperature'''
	return wat.VF_T(t, iunits, ounits)

def vg_t(double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific volume of steam at saturation conditions as a function of temperature'''
	return wat.VG_T(t, iunits, ounits)
	
# functions of (p)

def t_p(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the saturation temperature of water/steam as a function of pressure'''
	return wat.T_P(p, iunits, ounits)

def hf_p(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific enthalpy of water at saturation conditions as a function of pressure'''
	return wat.HF_P(p, iunits, ounits)

def hg_p(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific enthalpy of steam at saturation conditions as a function of pressure'''
	return wat.HG_P(p, iunits, ounits)

def sf_p(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific entropy of water at saturation conditions as a function of pressure'''
	return wat.SF_P(p, iunits, ounits)

def sg_p(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific entropy of steam at saturation conditions as a function of pressure'''
	return wat.SG_P(p, iunits, ounits)

def vf_p(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific volume of water at saturation conditions as a function of pressure'''
	return wat.VF_P(p, iunits, ounits)

def vg_p(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific volume of steam at saturation conditions as a function of pressure'''
	return wat.VG_P(p, iunits, ounits)
	
# functions of (p,h)

def t_ph(double p, double h, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the temperature of water/steam as a function of pressure and specific enthalpy'''
	return wat.T_PH(p, h, iunits, ounits)

def s_ph(double p, double h, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific entropy of water/steam as a function of pressure and specific enthalpy'''
	return wat.S_PH(p, h, iunits, ounits)

def v_ph(double p, double h, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific volume of water/steam as a function of pressure and specific enthalpy'''
	return wat.V_PH(p, h, iunits, ounits)

