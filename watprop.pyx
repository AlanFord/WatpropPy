# cython: c_string_type=str, c_string_encoding=ascii
cimport wat

def H_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the specific enthalpy of water/steam as a function of pressure and temperature'''
	wat._H_PT(p, t, iunits, ounits)

def V_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the specific volume of water/steam as a function of pressure and temperature'''
	wat._V_PT(p, t, iunits, ounits)

def W_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the speed of sound in water/steam as a function of pressure and temperature'''
	wat._W_PT(p, t, iunits, ounits)

def HF_T(double t, char * iunits, char * ounits):
	'''Returns the specific enthalpy of water at saturation conditions as a function of temperature'''
	wat._HF_T(t, iunits, ounits)

def HG_T(double t, char * iunits, char * ounits):
	'''Returns the specific enthalpy of steam at saturation conditions as a function of temperature'''
	wat._HG_T(t, iunits, ounits)

def P_T(double t, char * iunits, char * ounits):
	'''Returns the saturation pressure of water/steam as a function of temperature'''
	wat._P_T(t, iunits, ounits)

def T_P(double p, char * iunits, char * ounits):
	'''Returns the saturation temperature of water/steam as a function of pressure'''
	wat._T_P(p, iunits, ounits)

def S_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the specific entropy of water/steam as a function of pressure and temperature'''
	wat._S_PT(p, t, iunits, ounits)

def CP_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the heat capacity of water/steam as a function of pressure and temperature'''
	wat._CP_PT(p, t, iunits, ounits)

def VIS_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the dynamic viscosity of water/steam as a function of pressure and temperature'''
	wat._VIS_PT(p, t, iunits, ounits)

def K_PT(double p, double t, char * iunits, char * ounits):
	'''Returns the thermal conductivity of water/steam as a function of pressure and temperature'''
	wat._K_PT(p, t, iunits, ounits)

def SF_T(double t, char * iunits, char * ounits):
	'''Returns the specific entropy of water at saturation conditions as a function of temperature'''
	wat._SF_T(t, iunits, ounits)

def SG_T(double t, char * iunits, char * ounits):
	'''Returns the specific entropy of steam at saturation conditions as a function of temperature'''
	wat._SG_T(t, iunits, ounits)

def HF_P(double p, char * iunits, char * ounits):
	'''Returns the specific enthalpy of water at saturation conditions as a function of pressure'''
	wat._HF_P(p, iunits, ounits)

def HG_P(double p, char * iunits, char * ounits):
	'''Returns the specific enthalpy of steam at saturation conditions as a function of pressure'''
	wat._HG_P(p, iunits, ounits)

def VF_P(double p, char * iunits, char * ounits):
	'''Returns the specific volume of water at saturation conditions as a function of pressure'''
	wat._VF_P(p, iunits, ounits)

def VG_P(double p, char * iunits, char * ounits):
	'''Returns the specific volume of steam at saturation conditions as a function of pressure'''
	wat._VG_P(p, iunits, ounits)

def SF_P(double p, char * iunits, char * ounits):
	'''Returns the specific entropy of water at saturation conditions as a function of pressure'''
	wat._SF_P(p, iunits, ounits)

def SG_P(double p, char * iunits, char * ounits):
	'''Returns the specific entropy of steam at saturation conditions as a function of pressure'''
	wat._SG_P(p, iunits, ounits)

def T_PH(double p, double h, char * iunits, char * ounits):
	'''Returns the temperature of water/steam as a function of pressure and specific enthalpy'''
	wat._T_PH(p, h, iunits, ounits)

def V_PH(double p, double h, char * iunits, char * ounits):
	'''Returns the specific volume of water/steam as a function of pressure and specific enthalpy'''
	wat._V_PH(p, h, iunits, ounits)

def S_PH(double p, double h, char * iunits, char * ounits):
	'''Returns the specific entropy of water/steam as a function of pressure and specific enthalpy'''
	wat._S_PH(p, h, iunits, ounits)

