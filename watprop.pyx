# cython: c_string_type=str, c_string_encoding=ascii
cimport wat

cdef double H_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the specific enthalpy of water/steam as a function of pressure and temperature'''
	return wat._H_PT(p, t, iunits, ounits)

cdef double V_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the specific volume of water/steam as a function of pressure and temperature'''
	return wat._V_PT(p, t, iunits, ounits)

cdef double W_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the speed of sound in water/steam as a function of pressure and temperature'''
	return wat._W_PT(p, t, iunits, ounits)

cdef double HF_T(double t, char * iunits, char * ounits):
	'''Returns the specific enthalpy of water at saturation conditions as a function of temperature'''
	return wat._HF_T(t, iunits, ounits)

cdef double HG_T(double t, char * iunits, char * ounits):
	'''Returns the specific enthalpy of steam at saturation conditions as a function of temperature'''
	return wat._HG_T(t, iunits, ounits)

cdef double P_T(double t, char * iunits, char * ounits):
	'''Returns the saturation pressure of water/steam as a function of temperature'''
	return wat._P_T(t, iunits, ounits)

cdef double T_P(double p, char * iunits, char * ounits):
	'''Returns the saturation temperature of water/steam as a function of pressure'''
	return wat._T_P(p, iunits, ounits)

cdef double S_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the specific entropy of water/steam as a function of pressure and temperature'''
	return wat._S_PT(p, t, iunits, ounits)

cdef double CP_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the heat capacity of water/steam as a function of pressure and temperature'''
	return wat._CP_PT(p, t, iunits, ounits)

cdef double VIS_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the dynamic viscosity of water/steam as a function of pressure and temperature'''
	return wat._VIS_PT(p, t, iunits, ounits)

cdef double K_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the thermal conductivity of water/steam as a function of pressure and temperature'''
	return wat._K_PT(p, t, iunits, ounits)

cdef double SF_T(double t, char * iunits, char * ounits):
	'''Returns the specific entropy of water at saturation conditions as a function of temperature'''
	return wat._SF_T(t, iunits, ounits)

cdef double SG_T(double t, char * iunits, char * ounits):
	'''Returns the specific entropy of steam at saturation conditions as a function of temperature'''
	return wat._SG_T(t, iunits, ounits)

cdef double HF_P(double p, char * iunits, char * ounits):
	'''Returns the specific enthalpy of water at saturation conditions as a function of pressure'''
	return wat._HF_P(p, iunits, ounits)

cdef double HG_P(double p, char * iunits, char * ounits):
	'''Returns the specific enthalpy of steam at saturation conditions as a function of pressure'''
	return wat._HG_P(p, iunits, ounits)

cdef double VF_P(double p, char * iunits, char * ounits):
	'''Returns the specific volume of water at saturation conditions as a function of pressure'''
	return wat._VF_P(p, iunits, ounits)

cdef double VG_P(double p, char * iunits, char * ounits):
	'''Returns the specific volume of steam at saturation conditions as a function of pressure'''
	return wat._VG_P(p, iunits, ounits)

cdef double SF_P(double p, char * iunits, char * ounits):
	'''Returns the specific entropy of water at saturation conditions as a function of pressure'''
	return wat._SF_P(p, iunits, ounits)

cdef double SG_P(double p, char * iunits, char * ounits):
	'''Returns the specific entropy of steam at saturation conditions as a function of pressure'''
	return wat._SG_P(p, iunits, ounits)

cdef double T_PH(double p, double h, char * iunits, char * ounits):
	'''Returns the temperature of water/steam as a function of pressure and specific enthalpy'''
	return wat._T_PH(p, h, iunits, ounits)

cdef double V_PH(double p, double h, char * iunits, char * ounits):
	'''Returns the specific volume of water/steam as a function of pressure and specific enthalpy'''
	return wat._V_PH(p, h, iunits, ounits)

cdef double S_PH(double p, double h, char * iunits, char * ounits):
	'''Returns the specific entropy of water/steam as a function of pressure and specific enthalpy'''
	return wat._S_PH(p, h, iunits, ounits)

