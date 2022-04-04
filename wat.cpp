/////////////////////////////////////////////////////////////////////////
///	\file watprop.cpp
///	\brief Calculations of properties of water and steam.
///
///	\author Alan Ford
///
/// This file was modified for use by Dominion Energy
/////////////////////////////////////////////////////////////////////////

/*
 Copyright (c) 1995-2017 Charles Alan Ford
 
  Permission is hereby granted, free of charge, to any person obtaining
  a copy of this software and associated documentation files (the
  "Software"), to deal in the Software without restriction, including
  without limitation the rights to use, copy, modify, merge, publish,
  distribute, sublicense, and/or sell copies of the Software, and to
  permit persons to whom the Software is furnished to do so, subject to
  the following conditions:
 
  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.
 
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <math.h>
#include <string>
#include "wat.h"
#include "utilities.h"
#include "iapws.h"

////////////////////////////////////////////////////////
///	string identifying the version of the WATPROP library
///
///  *****************UPDATE THIS STRING FOR EACH NEW RELEASE ***********************
////////////////////////////////////////////////////////
static LPWSTR watpropPy_version = "WatpropPy";
/*
////////////////////////////////////////////////////////
///	length of the rgFuncs table
////////////////////////////////////////////////////////
#define rgFuncsRows 25

////////////////////////////////////////////////////////
///	width of the rgFuncs table
////////////////////////////////////////////////////////
#define rgFuncsCols 13

////////////////////////////////////////////////////////
///	table of all the functions exported by WATPROP
///
/// This is a table of all the functions exported by this module.
/// These functions are all registered (in xlAutoOpen) when you
/// open the XLL. Before every string, leave a space for the
/// byte count. The format of this table is the same as
/// the last seven arguments to the REGISTER function.
/// rgFuncsRows define the number of rows in the table. The
/// dimension [3] represents the number of columns in the table.
////////////////////////////////////////////////////////
static LPWSTR rgFuncs[rgFuncsRows][rgFuncsCols] = {
	{L"H_PT",					L"UBBCC", L"H_PT",    L"Pressure, Temperature, Input Units, Output Units", L"1", L"Watprop-D", L"", L"", L"Returns the specific enthalpy of water/steam as a function of pressure and temperature", L"", L"", L"ENGLISH or SI", L"ENGLISH or SI"},
	{L"V_PT",					L"UBBCC", L"V_PT",    L"Pressure, Temperature, Input Units, Output Units", L"1", L"Watprop-D", L"", L"", L"Returns the specific volume of water/steam as a function of pressure and temperature", L"", L"", L"ENGLISH or SI", L"ENGLISH or SI"},
	{L"W_PT",					L"UBBCC", L"W_PT",    L"Pressure, Temperature, Input Units, Output Units", L"1", L"Watprop-D", L"", L"", L"Returns the speed of sound in water/steam as a function of pressure and temperature", L"", L"", L"ENGLISH or SI", L"ENGLISH or SI"},
	{L"S_PT",					L"UBBCC", L"S_PT",    L"Pressure, Temperature, Input Units, Output Units", L"1", L"Watprop-D", L"", L"", L"Returns the specific entropy of water/steam as a function of pressure and temperature", L"", L"", L"ENGLISH or SI", L"ENGLISH or SI"},
	{L"CP_PT",					L"UBBCC", L"CP_PT",   L"Pressure, Temperature, Input Units, Output Units", L"1", L"Watprop-D", L"", L"", L"Returns the heat capacity of water/steam as a function of pressure and temperature", L"", L"", L"ENGLISH or SI", L"ENGLISH or SI"},
	{L"VIS_PT",					L"UBBCC", L"VIS_PT",  L"Pressure, Temperature, Input Units, Output Units", L"1", L"Watprop-D", L"", L"", L"Returns the dynamic viscosity of water/steam as a function of pressure and temperature", L"", L"", L"ENGLISH or SI", L"ENGLISH or SI"},
	{L"K_PT",					L"UBBCC", L"K_PT",    L"Pressure, Temperature, Input Units, Output Units", L"1", L"Watprop-D", L"", L"", L"Returns the thermal conductivity of water/steam as a function of pressure and temperature", L"", L"", L"ENGLISH or SI", L"ENGLISH or SI"},
	{L"T_PH",					L"UBBCC", L"T_PH",    L"Pressure, Enthalpy, Input Units, Output Units",    L"1", L"Watprop-D", L"", L"", L"Returns the temperature of water/steam as a function of pressure and specific enthalpy", L"", L"", L"ENGLISH or SI", L"ENGLISH or SI" },
	{L"V_PH",					L"UBBCC", L"V_PH",    L"Pressure, Enthalpy, Input Units, Output Units",    L"1", L"Watprop-D", L"", L"", L"Returns the specific volume of water/steam as a function of pressure and specific enthalpy", L"", L"", L"ENGLISH or SI", L"ENGLISH or SI"},
	{L"S_PH",					L"UBBCC", L"S_PH",    L"Pressure, Enthalpy, Input Units, Output Units",    L"1", L"Watprop-D", L"", L"", L"Returns the specific entropy of water/steam as a function of pressure and specific enthalpy", L"", L"", L"ENGLISH or SI", L"ENGLISH or SI"},
	{L"SF_T",					L"UBCC",  L"SF_T",    L"Temperature, Input Units, Output Units",           L"1", L"Watprop-D", L"", L"", L"Returns the specific entropy of water at saturation conditions as a function of temperature", L"", L"ENGLISH or SI", L"ENGLISH or SI", L"" },
	{L"SG_T",					L"UBCC",  L"SG_T",    L"Temperature, Input Units, Output Units",           L"1", L"Watprop-D", L"", L"", L"Returns the specific entropy of steam at saturation conditions as a function of temperature", L"", L"ENGLISH or SI", L"ENGLISH or SI", L""},
	{L"HF_P",					L"UBCC",  L"HF_P",    L"Pressure, Input Units, Output Units",              L"1", L"Watprop-D", L"", L"", L"Returns the specific enthalpy of water at saturation conditions as a function of pressure", L"", L"ENGLISH or SI", L"ENGLISH or SI", L""},
	{L"HG_P",					L"UBCC",  L"HG_P",    L"Pressure, Input Units, Output Units",              L"1", L"Watprop-D", L"", L"", L"Returns the specific enthalpy of steam at saturation conditions as a function of pressure", L"", L"ENGLISH or SI", L"ENGLISH or SI", L""},
 	{L"VF_P",					L"UBCC",  L"VF_P",    L"Pressure, Input Units, Output Units",              L"1", L"Watprop-D", L"", L"", L"Returns the specific volume of water at saturation conditions as a function of pressure", L"", L"ENGLISH or SI", L"ENGLISH or SI", L""},
	{L"VG_P",					L"UBCC",  L"VG_P",    L"Pressure, Input Units, Output Units",              L"1", L"Watprop-D", L"", L"", L"Returns the specific volume of steam at saturation conditions as a function of pressure", L"", L"ENGLISH or SI", L"ENGLISH or SI", L""},
	{L"SF_P",					L"UBCC",  L"SF_P",    L"Pressure, Input Units, Output Units",              L"1", L"Watprop-D", L"", L"", L"Returns the specific entropy of water at saturation conditions as a function of pressure", L"", L"ENGLISH or SI", L"ENGLISH or SI", L""},
	{L"SG_P",					L"UBCC",  L"SG_P",    L"Pressure, Input Units, Output Units",              L"1", L"Watprop-D", L"", L"", L"Returns the specific entropy of steam at saturation conditions as a function of pressure", L"", L"ENGLISH or SI", L"ENGLISH or SI", L""},
	{L"HF_T",					L"UBCC",  L"HF_T",    L"Temperature, Input Units, Output Units",           L"1", L"Watprop-D", L"", L"", L"Returns the specific enthalpy of water at saturation conditions as a function of temperature", L"", L"ENGLISH or SI", L"ENGLISH or SI", L""},
	{L"HG_T",					L"UBCC",  L"HG_T",    L"Temperature, Input Units, Output Units",           L"1", L"Watprop-D", L"", L"", L"Returns the specific enthalpy of steam at saturation conditions as a function of temperature", L"", L"ENGLISH or SI", L"ENGLISH or SI", L""},
	{L"VF_T",					L"UBCC",  L"VF_T",    L"Temperature, Input Units, Output Units",           L"1", L"Watprop-D", L"", L"", L"Returns the specific volume of water at saturation conditions as a function of temperature", L"", L"ENGLISH or SI", L"ENGLISH or SI", L""},
	{L"VG_T",					L"UBCC",  L"VG_T",    L"Temperature, Input Units, Output Units",           L"1", L"Watprop-D", L"", L"", L"Returns the specific volume of steam at saturation conditions as a function of temperature", L"", L"ENGLISH or SI", L"ENGLISH or SI", L""},
	{L"P_T",					L"UBCC",  L"P_T",     L"Temperature, Input Units, Output Units",           L"1", L"Watprop-D", L"", L"", L"Returns the saturation pressure of water/steam as a function of temperature", L"", L"ENGLISH or SI", L"ENGLISH or SI", L""},
	{L"T_P",					L"UBCC",  L"T_P",     L"Pressure, Input Units, Output Units",              L"1", L"Watprop-D", L"", L"", L"Returns the saturation temperature of water/steam as a function of pressure", L"", L"ENGLISH or SI", L"ENGLISH or SI", L""},
	{L"WatpropVersion",         L"U",     L"Watprop_Version", L" ",                                        L"1", L"Watprop-D", L"", L"", L"Returns the WATPROP-D library version as a string", L"", L"", L"", L"" }
};
*/

///////////////////////////////////////////////////////////////////////////////
/// \brief returns the version number for the WATPROP library
///
/// \return a string containing the WATPROP version
///////////////////////////////////////////////////////////////////////////////
 LPWSTR _WatpropPyVersion(void)
{
	return watpropPy_version;
} 

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific enthalpy as a function of pressure and temperature
///
/// \param[in] p pressure
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific enthalpy
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _H_PT(double p, double t, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
			t = convert_temp_english_to_kelvin(t);
		} 
		else {
			t = convert_temp_centigrade_to_kelvin(t);
		}
		// check for region
		int region = region_pt(p,t);
		// call region function for h
		double h = 0;
		double v = 0;
		double d = 0;
		switch (region) {
			case 1:
				h = h_pt_1(p,t);
				break;
			case 2:
				h = h_pt_2(p,t);
				break;
			case 3:
				d = d_pt_3(p,t);
				h = h_dt_3(d,t);
				break;
			case 5:
				h = h_pt_5(p,t);
				break;
			default:
				throw "invalid region number in h_pt";
		}
		// convert units
		if (output_units== ENGLISH)
			h = convert_enthalpy_si_to_english(h);
		// return
		return h;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific volume as a function of pressure and temperature
///
/// \param[in] p pressure
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific volume
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _V_PT(double p, double t, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
			t = convert_temp_english_to_kelvin(t);
		} 
		else {
			t = convert_temp_centigrade_to_kelvin(t);
		}
		// check for region
		int region = region_pt(p,t);
		// call region function for v (or d)
		double v = 0;
		switch (region) {
			case 1:
				v = v_pt_1(p,t);
				break;
			case 2:
				v = v_pt_2(p,t);
				break;
			case 3:
				v = 1. / d_pt_3(p,t);
				break;
			case 5:
				v = v_pt_5(p,t);
				break;
			default:
				throw "invalid region number in v_pt";
		}
		// convert units
		if (output_units== ENGLISH)
			v = convert_spvolume_si_to_english(v);
		return v;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates speed of sound as a function of pressure and temperature
///
/// \param[in] p pressure
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return speed of sound
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _W_PT(double p, double t, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
			t = convert_temp_english_to_kelvin(t);
		} 
		else {
			t = convert_temp_centigrade_to_kelvin(t);
		}
		// check for region
		int region = region_pt(p,t);
		// call region function for w
		double v = 0;
		double w = 0;
		double d = 0;
		switch (region) {
			case 1:
				w = w_pt_1(p,t);
				break;
			case 2:
				w = w_pt_2(p,t);
				break;
			case 3:
				d = d_pt_3(p,t);
				w = w_dt_3(d,t);
				break;
			case 5:
				w = w_pt_5(p,t);
				break;
			default:
				throw "invalid region number in w_pt";
		}
		// convert units
		if (output_units== ENGLISH)
			w = convert_w_si_to_english(w);
		// return
		return w;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturated liquid specific enthalpy as a function of temperature
///
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific enthalpy
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _HF_T(double t, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			t = convert_temp_english_to_kelvin(t);
		} 
		else {
			t = convert_temp_centigrade_to_kelvin(t);
		}
		// verify that saturation conditions can exist at this temperature
		if ((t < 273.15) || (t > 647.096))
			throw "invalid temperature in hf_t";
		// calculate the saturation pressure
		double p = PSAT_T(t);
		double h = 0;
		if (t<= 623.15) {
			// get the enthalpy from the region 1 correlations
			h = h_pt_1(p, t);
		}
		else {
			// need to get the enthalpy from the region 3 correlations
			double d = df_pt_3(p,t);
			h = h_dt_3(d,t);
		}
		// convert units
		if (output_units== ENGLISH)
			h = convert_enthalpy_si_to_english(h);
		// return
		return h;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturated vapor specific enthalpy as a function of temperature
///
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific enthalpy
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _HG_T(double t, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			t = convert_temp_english_to_kelvin(t);
		} 
		else {
			t = convert_temp_centigrade_to_kelvin(t);
		}
		// verify that saturation conditions can exist at this temperature
		if ((t < 273.15) || (t > 647.096))
			throw "invalid temperature in hf_t";
		// calculate the saturation pressure
		double p = PSAT_T(t);
		double h = 0;
		if (t<= 623.15) {
			// get the enthalpy from the region 2 correlations
			h = h_pt_2(p, t);
		}
		else {
			// need to get the enthalpy from the region 3 correlations
			double d = dv_pt_3(p,t);
			h = h_dt_3(d,t);
		}
		// convert units
		if (output_units== ENGLISH)
			h = convert_enthalpy_si_to_english(h);
		// return
		return h;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturated liquid specific volume as a function of temperature
///
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific volume
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _VF_T(double t, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			t = convert_temp_english_to_kelvin(t);
		} 
		else {
			t = convert_temp_centigrade_to_kelvin(t);
		}
		// verify that saturation conditions can exist at this temperature
		if ((t < 273.15) || (t > 647.096))
			throw "invalid temperature in hf_t";
		// calculate the saturation pressure
		double p = PSAT_T(t);
		double v = 0;
		if (t<= 623.15) {
			// get the enthalpy from the region 1 correlations
			v = v_pt_1(p, t);
		}
		else {
			// need to get the enthalpy from the region 3 correlations
			v = 1 / df_pt_3(p,t);
		}
		// convert units
		if (output_units== ENGLISH)
			v = convert_spvolume_si_to_english(v);
		// return
		return v;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturated vapor specific volume as a function of temperature
///
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific volume
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _VG_T(double t, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			t = convert_temp_english_to_kelvin(t);
		} 
		else {
			t = convert_temp_centigrade_to_kelvin(t);
		}
		// verify that saturation conditions can exist at this temperature
		if ((t < 273.15) || (t > 647.096))
			throw "invalid temperature in hf_t";
		// calculate the saturation pressure
		double p = PSAT_T(t);
		double v = 0;
		if (t<= 623.15) {
			// get the specific volume from the region 2 correlations
			v = v_pt_2(p, t);
		}
		else {
			// need to get the specific volume from the region 3 correlations
			v = 1 / dv_pt_3(p,t);
		}
		// convert units
		if (output_units== ENGLISH)
			v = convert_spvolume_si_to_english(v);
		// return
		return v;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturation pressure as a function of temperature
///
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return pressure
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _P_T(double t, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		// convert the temperature to kelvin if necessary
		if (input_units== ENGLISH)
			t = convert_temp_english_to_kelvin(t);
		else
			t = convert_temp_centigrade_to_kelvin(t);
		check_saturated_t(t);
		double p = PSAT_T(t);
		if (output_units== ENGLISH)
			p = convert_pressure_si_to_english(p);
		// return
		return p;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturation temperature as a function of pressure
///
/// \param[in] p pressure
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return temperature
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _T_P(double p, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		// convert the pressure to MPa if necessary
		if (input_units== ENGLISH)
			p = convert_pressure_english_to_si(p);
		check_saturated_p(p);
		double t = TSAT_P(p);
		if (output_units== ENGLISH)
			t=convert_temp_kelvin_to_english(t);
		else
			t=convert_temp_kelvin_to_centigrade(t);
		// return
		return t;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific entropy as a function of pressure and temperature
///
/// \param[in] p pressure
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific entropy
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _S_PT(double p, double t, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
			t = convert_temp_english_to_kelvin(t);
		} 
		else {
			t = convert_temp_centigrade_to_kelvin(t);
		}
		// check for region
		int region = region_pt(p,t);
		// call region function for s
		double v = 0;
		double s = 0;
		double d = 0;
		switch (region) {
			case 1:
				s = s_pt_1(p,t);
				break;
			case 2:
				s = s_pt_2(p,t);
				break;
			case 3:
				d = d_pt_3(p,t);
				s = s_dt_3(d,t);
				break;
			case 5:
				s = s_pt_5(p,t);
				break;
			default:
				throw "invalid region number in s_pt";
		}
		// convert units
		if (output_units== ENGLISH)
			s = convert_entropy_si_to_english(s);
		// return
		return s;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates isobaric heat capacity as a function of pressure and temperature
///
/// \param[in] p pressure
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return isobaric heat capacity
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _CP_PT(double p, double t, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
			t = convert_temp_english_to_kelvin(t);
		} 
		else {
			t = convert_temp_centigrade_to_kelvin(t);
		}
		// check for region
		int region = region_pt(p,t);
		// call region function for cp
		double v = 0;
		double cp = 0;
		double d = 0;
		switch (region) {
			case 1:
				cp = cp_pt_1(p,t);
				break;
			case 2:
				cp = cp_pt_2(p,t);
				break;
			case 3:
				d = d_pt_3(p,t);
				cp = cp_dt_3(d,t);
				break;
			case 5:
				cp = cp_pt_5(p,t);
				break;
			default:
				throw "invalid region number in cp_pt";
		}
		// convert units
		if (output_units== ENGLISH)
			cp = convert_cp_si_to_english(cp);
		// return
		return cp;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates dynamic viscosity as a function of pressure and temperature
///
/// \param[in] p pressure
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return dynamic viscosity
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _VIS_PT(double p, double t, char * Xiunits, char * Xounits)
{
	double t_star = 647.226;
	double d_star = 317.763;
	double vis_star = 55.071e-6;
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
			t = convert_temp_english_to_kelvin(t);
		} 
		else {
			t = convert_temp_centigrade_to_kelvin(t);
		}
		// check for region
		int region = region_pt(p,t);
		// calculate density
		// call region function for v (or d)
		double d = 0;
		switch (region) {
			case 1:
				d = 1. / v_pt_1(p,t);
				break;
			case 2:
				d = 1. / v_pt_2(p,t);
				break;
			case 3:
				d = d_pt_3(p,t);
				break;
			case 5:
				if (t > 1173.15)
					throw "shear viscosity calculation is not valid in portions of Region 5";
				d = 1. / v_pt_5(p,t);
				break;
			default:
				throw "invalid region number in vis_pt";
		}
		// calculate reduced properties
		double t_bar = t/t_star;
		double d_bar = d/d_star;
		// calculate part 1
		const int PART1_COUNT = 4;
		double h[PART1_COUNT] = {1.000000,0.978197, 0.579829,-0.202354};
		double part1 = 0;
		for (int i=0; i<PART1_COUNT; i++) {
			part1 += h[i]/pow(t_bar,i);
		}
		part1 = pow(t_bar, 0.5)/part1;

		// calculate part 2
		const int PART2_COUNT = 19;
		double I[PART2_COUNT] = {0,1,4,5,0,1,2,3,0,1,2,0,1,2,3,0,3,1,3};
		double J[PART2_COUNT] = {0,0,0,0,1,1,1,1,2,2,2,3,3,3,3,4,4,5,6};
		double H[PART2_COUNT] = {0.5132047, 0.3205656, -0.7782567, 0.1885447, 0.2151778, 0.7317883, 1.241044, 1.476783, 
								-0.2818107, -1.070786, -1.263184, 0.1778064, 0.4605040, 0.2340379, -0.4924179, -0.04176610,
								 0.1600435, -0.01578386, -0.003629481};
		double tt = 1 / t_bar - 1;
		double dd = d_bar - 1;
		double part2 = 0;
		for (int i = 0; i < PART2_COUNT; i++) {
			part2 += H[i] * pow(tt, I[i]) * pow(dd, J[i]);
		}
		part2 = exp(part2*d_bar);
		// combined parts
		double vis = part1*part2*vis_star;
		// convert units
		if (output_units== ENGLISH)
			vis = convert_vis_si_to_english(vis);
		else
			vis = vis * 1E6; // convert to microPa*sec
		// return
		return vis;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

#define THCON_a_COUNT 4
const double THCON_a[THCON_a_COUNT] = {
	0.0102811
	,0.0299621
	,0.0156146
	,-0.00422464
};


#define THCON_b0 -0.397070
#define THCON_b1 0.400302
#define THCON_b2 1.060000
#define THCON_B1 -0.171587
#define THCON_B2 2.392190

#define THCON_d1 0.0701309
#define THCON_d2 0.0118520
#define THCON_d3 0.00169937
#define THCON_d4 -1.0200

#define THCON_C1 0.642857
#define THCON_C2 -4.11717
#define THCON_C3 -6.17937
#define THCON_C4 0.00308976
#define THCON_C5 0.0822994
#define THCON_C6 10.0932


///////////////////////////////////////////////////////////////////////////////
/// \brief calculates thermal conductivity as a function of pressure and temperature
///
/// \param[in] p pressure
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return thermal conductivity
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _K_PT(double p, double t, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
			t = convert_temp_english_to_kelvin(t);
		} 
		else {
			t = convert_temp_centigrade_to_kelvin(t);
		}
		// check for a valid set of conditions
		if ((t < 273.15) || (t > 1075.15))
			throw "invalid temperature in k_pt";
		if ((p > 100) || (p <= 0))
			throw "invalid pressure in k_pt";

		// check for region
		int region = region_pt(p,t);
		// call region function for v (or d)
		double d = 0;
		switch (region) {
			case 1:
				d = 1. / v_pt_1(p,t);
				break;
			case 2:
				d = 1. / v_pt_2(p,t);
				break;
			case 3:
				d = d_pt_3(p,t);
				break;
			case 5:
				d = 1. / v_pt_5(p,t);
				break;
			default:
				throw "invalid region number in d_pt";
		}

		double t_ref = 647.26;
		double d_ref = 317.7;
		double k_ref = 1;

		double Tbar = t/t_ref;
		double rhobar = d/d_ref;

		// calculate lambda0
		double Tpow = sqrt(Tbar);
		double acc = 0;
		for(int k = 0; k < THCON_a_COUNT; ++k) {
			acc += THCON_a[k] * Tpow;
			Tpow *= Tbar;
		}
		double l0 = acc;

		// calculate lambda1
		double l1 = THCON_b0 + THCON_b1 * rhobar + THCON_b2 * exp(THCON_B1 * pow(rhobar + THCON_B2,2));

		// calculate lambda2
		double DTbar = fabs(Tbar - 1) + THCON_C4;

		double Q = 2 + THCON_C5 / pow(DTbar,0.6);

		double S;
		if(Tbar > 1){
			S = 1 / DTbar;
		}else{
			S = THCON_C6 / pow(DTbar,0.6);
		}

		double l2 = 
			(THCON_d1 / pow(Tbar,10) + THCON_d2) * pow(rhobar,1.8) * 
				exp(THCON_C1 * (1 - pow(rhobar,2.8)))
			+ THCON_d3 * S * pow(rhobar,Q) *
				exp((Q/(1+Q))*(1 - pow(rhobar,1+Q)))
			+ THCON_d4 *
				exp(THCON_C2 * pow(Tbar,1.5) + THCON_C3 / pow(rhobar,5));
		double k = l0+l1+l2;
		// convert units
		if (output_units== ENGLISH)
			k = convert_k_si_to_english(k);
		else
			k = k * 1E3; // convert to mW/m/K
		// return
		return k;

	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturated vapor specific entropy as a function of temperature
///
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific entropy
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _SF_T(double t, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			t = convert_temp_english_to_kelvin(t);
		} 
		else {
			t = convert_temp_centigrade_to_kelvin(t);
		}
		// verify that saturation conditions can exist at this temperature
		if ((t < 273.15) || (t > 647.096))
			throw "invalid temperature in hf_t";
		// calculate the saturation pressure
		double p = PSAT_T(t);
		double s = 0;
		if (t<= 623.15) {
			// get the entropy from the region 1 correlations
			s = s_pt_1(p, t);
		}
		else {
			// need to get the entropy from the region 3 correlations
			double d = df_pt_3(p,t);
			s = s_dt_3(d,t);
		}
		// convert units
		if (output_units== ENGLISH)
			s = convert_entropy_si_to_english(s);
		// return
		return s;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturated vapor specific entropy as a function of temperature
///
/// \param[in] t temperature
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific entropy
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _SG_T(double t, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			t = convert_temp_english_to_kelvin(t);
		} 
		else {
			t = convert_temp_centigrade_to_kelvin(t);
		}
		// verify that saturation conditions can exist at this temperature
		if ((t < 273.15) || (t > 647.096))
			throw "invalid temperature in hf_t";
		// calculate the saturation pressure
		double p = PSAT_T(t);
		double s = 0;
		if (t<= 623.15) {
			// get the entropy from the region 2 correlations
			s = s_pt_2(p, t);
		}
		else {
			// need to get the entropy from the region 3 correlations
			double d = dv_pt_3(p,t);
			s = s_dt_3(d,t);
		}
		// convert units
		if (output_units== ENGLISH)
			s = convert_entropy_si_to_english(s);
		// return
		return s;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturated liquid specific enthalpy as a function of pressure
///
/// \param[in] p pressure
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific enthalpy
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _HF_P(double p, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
		} 
		// verify that saturation conditions can exist at this pressure
		if ((p < 6.11213E-4) || (p > 22.064))
			throw "invalid pressure in hf_p";
		// calculate the saturation temperature
		double t = TSAT_P(p);
		double h = 0;
		if (t<= 623.15) {
			// get the enthalpy from the region 1 correlations
			h = h_pt_1(p, t);
		}
		else {
			// need to get the enthalpy from the region 3 correlations
			double d = df_pt_3(p,t);
			h = h_dt_3(d,t);
		}
		// convert units
		if (output_units== ENGLISH)
			h = convert_enthalpy_si_to_english(h);
		// return
		return h;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturated vapor specific enthalpy as a function of pressure
///
/// \param[in] p pressure
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific enthalpy
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _HG_P(double p, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
		} 
		// verify that saturation conditions can exist at this pressure
		if ((p < 6.11213E-4) || (p > 22.064))
			throw "invalid pressure in hg_p";
		// calculate the saturation temperature
		double t = TSAT_P(p);
		double h = 0;
		if (t<= 623.15) {
			// get the enthalpy from the region 2 correlations
			h = h_pt_2(p, t);
		}
		else {
			// need to get the enthalpy from the region 3 correlations
			double d = dv_pt_3(p,t);
			h = h_dt_3(d,t);
		}
		// convert units
		if (output_units== ENGLISH)
			h = convert_enthalpy_si_to_english(h);
		// return
		return h;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturated liquid specific volume as a function of pressure
///
/// \param[in] p pressure
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific volume
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _VF_P(double p, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
		} 
		// verify that saturation conditions can exist at this pressure
		if ((p < 6.11213E-4) || (p > 22.064))
			throw "invalid pressure in vf_p";
		// calculate the saturation temperature
		double t = TSAT_P(p);
		double v = 0;
		if (t<= 623.15) {
			// get the enthalpy from the region 1 correlations
			v = v_pt_1(p, t);
		}
		else {
			// need to get the enthalpy from the region 3 correlations
			v = 1 / df_pt_3(p,t);
		}
		// convert units
		if (output_units== ENGLISH)
			v = convert_spvolume_si_to_english(v);
		// return
		return v;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturated vapor specific volume as a function of pressure
///
/// \param[in] p pressure
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific volume
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _VG_P(double p, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
		} 
		// verify that saturation conditions can exist at this pressure
		if ((p < 6.11213E-4) || (p > 22.064))
			throw "invalid pressure in vg_p";
		// calculate the saturation temperature
		double t = TSAT_P(p);
		double v = 0;
		if (t<= 623.15) {
			// get the specific volume from the region 2 correlations
			v = v_pt_2(p, t);
		}
		else {
			// need to get the specific volume from the region 3 correlations
			v = 1 / dv_pt_3(p,t);
		}
		// convert units
		if (output_units== ENGLISH)
			v = convert_spvolume_si_to_english(v);
		// return
		return v;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturated liquid specific enthalpy as a function of pressure
///
/// \param[in] p pressure
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific enthalpy
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _SF_P(double p, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
		} 
		// verify that saturation conditions can exist at this pressure
		if ((p < 6.11213E-4) || (p > 22.064))
			throw "invalid pressure in sf_p";
		// calculate the saturation temperature
		double t = TSAT_P(p);
		double s = 0;
		if (t<= 623.15) {
			// get the entropy from the region 1 correlations
			s = s_pt_1(p, t);
		}
		else {
			// need to get the entropy from the region 3 correlations
			double d = df_pt_3(p,t);
			s = s_dt_3(d,t);
		}
		// convert units
		if (output_units== ENGLISH)
			s = convert_entropy_si_to_english(s);
		// return
		return s;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturated vapor specific enthalpy as a function of pressure
///
/// \param[in] p pressure
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific enthalpy
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _SG_P(double p, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
		} 
		// verify that saturation conditions can exist at this pressure
		if ((p < 6.11213E-4) || (p > 22.064))
			throw "invalid pressure in sg_p";
		// calculate the saturation temperature
		double t = TSAT_P(p);
		double s = 0;
		if (t<= 623.15) {
			// get the entropy from the region 2 correlations
			s = s_pt_2(p, t);
		}
		else {
			// need to get the entropy from the region 3 correlations
			double d = dv_pt_3(p,t);
			s = s_dt_3(d,t);
		}
		// convert units
		if (output_units== ENGLISH)
			s = convert_entropy_si_to_english(s);
		// return
		return s;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates temperature as a function of pressure and specific enthalpy
///
/// \param[in] p pressure
/// \param[in] h specific enthalpy
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return temperature
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _T_PH(double p, double h, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
			h = convert_enthalpy_english_to_si(h);
		} 
		int region = region_ph(p, h);
		// call the appropriate region function
		double t = 0;
		switch (region) {
			case 1:
				t = t_ph_1(p,h);
				break;
			case 2:
				t = t_ph_2(p,h);
				break;
			case 3:
				t = t_ph_3(p,h);
				break;
			case 4:
				t = TSAT_P(p);
				break;
			case 5:
				t = t_ph_5(p,h);
				break;
			default:
				throw "invalid region number in t_ph";
		}
		// convert units
		if (output_units== ENGLISH)
			t=convert_temp_kelvin_to_english(t);
		else
			t=convert_temp_kelvin_to_centigrade(t);
		// return
		return t;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific volume as a function of pressure and specific enthalpy
///
/// \param[in] p pressure
/// \param[in] h specific enthalpy
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific entropy
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _V_PH(double p, double h, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
			h = convert_enthalpy_english_to_si(h);
		}
		int region = region_ph(p, h);
		// call the appropriate region function
		double v = 0;
		switch (region) {
			case 1:
				v = v_ph_1(p,h);
				break;
			case 2:
				v = v_ph_2(p,h);
				break;
			case 3:
				v = 1. / d_ph_3(p,h);
				break;
			case 4:
				v = v_ph_4(p,h);
				break;
			case 5:
				v = v_ph_5(p,h);
				break;
			default:
				throw "invalid region number in v_ph";
		}
		// convert units
		if (output_units== ENGLISH)
			v = convert_spvolume_si_to_english(v);
		// return
		return v;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific entropy as a function of pressure and specific enthalpy
///
/// \param[in] p pressure
/// \param[in] h specific enthalpy
/// \param[in] Xiunits input units of measure
/// \param[in] Xounits output units of measure
///
/// \return specific entropy
///////////////////////////////////////////////////////////////////////////////
 LPXLOPER12 _S_PH(double p, double h, char * Xiunits, char * Xounits)
{
	try {
		std::string iunits = Xiunits;
		std::string ounits = Xounits;
		int input_units = check_input_units(iunits);
		int output_units = check_output_units(ounits);
		if (input_units== ENGLISH) {
			p = convert_pressure_english_to_si(p);
			h = convert_enthalpy_english_to_si(h);
		}
		int region = region_ph(p, h);
		// call the appropriate region function
		double s = 0;
		switch (region) {
			case 1:
				s = s_ph_1(p,h);
				break;
			case 2:
				s = s_ph_2(p,h);
				break;
			case 3:
				s = s_ph_3(p,h);
				break;
			case 4:
				s = s_ph_4(p,h);
				break;
			case 5:
				s = s_ph_5(p,h);
				break;
			default:
				throw "invalid region number in s_ph";
		}
		// convert units
		if (output_units== ENGLISH)
			s = convert_entropy_si_to_english(s);
		// return
		return s;
	}
	catch(...) {
		// for now, just rethrow the original error
		throw;
		//xResult.xltype = xltypeErr;
		//xResult.val.err = xlerrValue;
		//return (LPXLOPER12) &xResult;
	}
}
