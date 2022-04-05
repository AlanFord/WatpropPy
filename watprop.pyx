cimport wat

def H_PT(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific enthalpy of water/steam as a function of pressure and temperature'''
	return wat._H_PT(p, t, iunits, ounits)

def V_PT(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific volume of water/steam as a function of pressure and temperature'''
	return wat._V_PT(p, t, iunits, ounits)

def W_PT(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the speed of sound in water/steam as a function of pressure and temperature'''
	return wat._W_PT(p, t, iunits, ounits)

def HF_T(double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific enthalpy of water at saturation conditions as a function of temperature'''
	return wat._HF_T(t, iunits, ounits)

def HG_T(double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific enthalpy of steam at saturation conditions as a function of temperature'''
	return wat._HG_T(t, iunits, ounits)

def P_T(double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the saturation pressure of water/steam as a function of temperature'''
	return wat._P_T(t, iunits, ounits)

def T_P(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the saturation temperature of water/steam as a function of pressure'''
	return wat._T_P(p, iunits, ounits)

def S_PT(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific entropy of water/steam as a function of pressure and temperature'''
	return wat._S_PT(p, t, iunits, ounits)

def CP_PT(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the heat capacity of water/steam as a function of pressure and temperature'''
	return wat._CP_PT(p, t, iunits, ounits)

def VIS_PT(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the dynamic viscosity of water/steam as a function of pressure and temperature'''
	return wat._VIS_PT(p, t, iunits, ounits)

def K_PT(double p, double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the thermal conductivity of water/steam as a function of pressure and temperature'''
	return wat._K_PT(p, t, iunits, ounits)

def SF_T(double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific entropy of water at saturation conditions as a function of temperature'''
	return wat._SF_T(t, iunits, ounits)

def SG_T(double t, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific entropy of steam at saturation conditions as a function of temperature'''
	return wat._SG_T(t, iunits, ounits)

def HF_P(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific enthalpy of water at saturation conditions as a function of pressure'''
	return wat._HF_P(p, iunits, ounits)

def HG_P(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific enthalpy of steam at saturation conditions as a function of pressure'''
	return wat._HG_P(p, iunits, ounits)

def VF_P(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific volume of water at saturation conditions as a function of pressure'''
	return wat._VF_P(p, iunits, ounits)

def VG_P(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific volume of steam at saturation conditions as a function of pressure'''
	return wat._VG_P(p, iunits, ounits)

def SF_P(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific entropy of water at saturation conditions as a function of pressure'''
	return wat._SF_P(p, iunits, ounits)

def SG_P(double p, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific entropy of steam at saturation conditions as a function of pressure'''
	return wat._SG_P(p, iunits, ounits)

def T_PH(double p, double h, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the temperature of water/steam as a function of pressure and specific enthalpy'''
	return wat._T_PH(p, h, iunits, ounits)

def V_PH(double p, double h, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific volume of water/steam as a function of pressure and specific enthalpy'''
	return wat._V_PH(p, h, iunits, ounits)

def S_PH(double p, double h, wat.Units iunits=wat.Units.ENGLISH, wat.Units ounits=wat.Units.ENGLISH):
	'''Returns the specific entropy of water/steam as a function of pressure and specific enthalpy'''
	return wat._S_PH(p, h, iunits, ounits)

