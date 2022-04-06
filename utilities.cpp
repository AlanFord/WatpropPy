/////////////////////////////////////////////////////////////////////////
///	\file utilities.cpp
///	\brief Utility functions to support the steam table calculations.
///  This includes unit conversion routines and verifying acceptable input
///  and output systems of units.
///
/////////////////////////////////////////////////////////////////////////

/*
 Copyright (c) 1995-2022 Charles Alan Ford
 
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

#include "utilities.h"


////////////////////////////////////////////////////////
///	\brief MPa to psia pressure conversion factor.
////////////////////////////////////////////////////////
const double english_p = 145.0377;
////////////////////////////////////////////////////////
///	\brief Multiplier for converting temperatures from degK to degF.
////////////////////////////////////////////////////////
const double english_tmult = 1.8;
////////////////////////////////////////////////////////
///	\brief Addition constant for converting temperatures from degK to degF.
////////////////////////////////////////////////////////
const double english_tadd = -459.67;
////////////////////////////////////////////////////////
///	\brief Temperature conversion from  from degK to degC.
////////////////////////////////////////////////////////
const double centigrade = -273.15;
////////////////////////////////////////////////////////
///	\brief kJ/kg to Btu/lbm specific enthalpy conversion factor.
////////////////////////////////////////////////////////
const double english_h = 1./2.326;
////////////////////////////////////////////////////////
///	\brief kJ/kg/K to Btu/lbm/R specific entropy conversion factor.
////////////////////////////////////////////////////////
const double english_s = 1./4.1868;
////////////////////////////////////////////////////////
///	\brief m3/kg to ft3/lbm specific volume conversion factor.
////////////////////////////////////////////////////////
const double english_v = 16.01846;
////////////////////////////////////////////////////////
///	\brief kg/m3 to lbm/ft3 density conversion factor.
////////////////////////////////////////////////////////
const double english_d = 1/english_v;
////////////////////////////////////////////////////////
///	\brief kJ/kg/K to Btu/lbm/R specific isobaric heast capacity conversion factor.
////////////////////////////////////////////////////////
const double english_cp = 1./4.1868;
////////////////////////////////////////////////////////
///	\brief m/s to ft/s speed of sound conversion factor.
////////////////////////////////////////////////////////
const double english_w = 3.2808399;
////////////////////////////////////////////////////////
///	\brief Pa*sec to lbm/sec/ft dynamic viscosity conversion factor.
////////////////////////////////////////////////////////
const double english_vis = 6.719690e-1;
////////////////////////////////////////////////////////
///	\brief W/m/K to Btu/hr/ft/F thermal conductivity conversion factor.
////////////////////////////////////////////////////////
const double english_k = 0.5777893;
/*
///////////////////////////////////////////////////////////////////////////////
/// \brief checks to see if a string variable represents a valid set of input
///  units of measurement
///
/// \param[in] units requested units of measurement
///
/// \return SI      valid SI units
///         ENGLISH valid english units
/// \exception std::exception "bad output units"
///////////////////////////////////////////////////////////////////////////////
int check_input_units(std::string units)
{
	// convert the units string to lowercase
	std::string fixed_units = units;
	for(unsigned int i=0; i<fixed_units.size();++i)
		fixed_units[i] = tolower(fixed_units[i]);
	// check for bogus units
	if (fixed_units=="si")
		return SI;
	else if ((fixed_units=="english")||(fixed_units==""))
		return ENGLISH;
	else
		throw "bad input units";
}

///////////////////////////////////////////////////////////////////////////////
/// \brief checks to see if a string variable represents a valid set of output
///  units of measurement
///
/// \param[in] units requested units of measurement
///
/// \return SI      valid SI units
///         ENGLISH valid english units
/// \exception std::exception "bad output units"
///////////////////////////////////////////////////////////////////////////////
int check_output_units(std::string units)
{
	// convert the units string to lowercase
	std::string fixed_units = units;
	for(unsigned int i=0; i<fixed_units.size();++i)
		fixed_units[i] = tolower(fixed_units[i]);
	// check for bogus units
	if (fixed_units=="si")
		return SI;
	else if ((fixed_units=="english")||(fixed_units==""))
		return ENGLISH;
	else
		throw "bad output units";
}
*/
///////////////////////////////////////////////////////////////////////////////
/// \brief converts pressure from si units to english units
///
/// \param[in] pressure pressure in si units
///
/// \return pressure in english units
///////////////////////////////////////////////////////////////////////////////
double convert_pressure_si_to_english(double pressure)
{
	return pressure*english_p;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts pressure from english units to si units
///
/// \param[in] pressure pressure in english units
///
/// \return pressure in si units
///////////////////////////////////////////////////////////////////////////////
double convert_pressure_english_to_si(double pressure)
{
	return pressure/english_p;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts temperature from kelvin to english units
///
/// \param[in] temperature temperature in kelvin
///
/// \return temperature in english units
///////////////////////////////////////////////////////////////////////////////
double convert_temp_kelvin_to_english(double temperature)
{
	return temperature*english_tmult + english_tadd;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts temperature from english units to kelvin
///
/// \param[in] temperature temperature in english units
///
/// \return temperature in kelvin
///////////////////////////////////////////////////////////////////////////////
double convert_temp_english_to_kelvin(double temperature)
{
	return (temperature - english_tadd)/english_tmult;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts temperature from kelvin to centigrade
///
/// \param[in] temperature temperature in kelvin
///
/// \return temperature in centigrade
///////////////////////////////////////////////////////////////////////////////
double convert_temp_kelvin_to_centigrade(double temperature)
{
	return temperature + centigrade;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts temperature from centigrade to kelvin
///
/// \param[in] temperature temperature in centigrade
///
/// \return temperature in kelvin
///////////////////////////////////////////////////////////////////////////////
double convert_temp_centigrade_to_kelvin(double temperature)
{
	return temperature - centigrade;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts specific enthalpy from si units to english units
///
/// \param[in] enthalpy specific enthalpy in si units
///
/// \return specific enthalpy in english units
///////////////////////////////////////////////////////////////////////////////
double convert_enthalpy_si_to_english(double enthalpy)
{
	return enthalpy*english_h;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts specific enthalpy from english units to si units
///
/// \param[in] enthalpy specific enthalpy in english units
///
/// \return specific enthalpy in si units
///////////////////////////////////////////////////////////////////////////////
double convert_enthalpy_english_to_si(double enthalpy)
{
	return enthalpy/english_h;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts specific entropy from si units to english units
///
/// \param[in] entropy specific entropy in si units
///
/// \return specific entropy in english units
///////////////////////////////////////////////////////////////////////////////
double convert_entropy_si_to_english(double entropy)
{
	return entropy*english_s;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts specific entropy from english units to si units
///
/// \param[in] entropy specific entropy in english units
///
/// \return specific entropy in si units
///////////////////////////////////////////////////////////////////////////////
double convert_entropy_english_to_si(double entropy)
{
	return entropy/english_s;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts specific volume from si units to english units
///
/// \param[in] spvolume specific volume in si units
///
/// \return specific volume in english units
///////////////////////////////////////////////////////////////////////////////
double convert_spvolume_si_to_english(double spvolume)
{
	return spvolume*english_v;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts specific volume from english units to si units
///
/// \param[in] spvolume specific volume in english units
///
/// \return specific volume in si units
///////////////////////////////////////////////////////////////////////////////
double convert_spvolume_english_to_si(double spvolume)
{
	return spvolume/english_v;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts density from si units to english units
///
/// \param[in] density density in si units
///
/// \return density in english units
///////////////////////////////////////////////////////////////////////////////
double convert_density_si_to_english(double density)
{
	return density*english_d;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts density from english units to si units
///
/// \param[in] density density in english units
///
/// \return density in si units
///////////////////////////////////////////////////////////////////////////////
double convert_density_english_to_si(double density)
{
	return density/english_d;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts heat capacity from si units to english units
///
/// \param[in] cp heat capacity in si units
///
/// \return heat capacity in english units
///////////////////////////////////////////////////////////////////////////////
double convert_cp_si_to_english(double cp)
{
	return cp*english_cp;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts heat capacity from english units to si units
///
/// \param[in] cp heat capacity in english units
///
/// \return heat capacity in si units
///////////////////////////////////////////////////////////////////////////////
double convert_cp_english_to_si(double cp)
{
	return cp/english_cp;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts speed of sound in water/steam from si units to english units
///
/// \param[in] w speed of sound in water/steam in si units
///
/// \return speed of sound in water/steam in english units
///////////////////////////////////////////////////////////////////////////////
double convert_w_si_to_english(double w)
{
	return w*english_w;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts speed of sound in water/steam from english units to si units
///
/// \param[in] w speed of sound in water/steam in english units
///
/// \return speed of sound in water/steam in si units
///////////////////////////////////////////////////////////////////////////////
double convert_w_english_to_si(double w)
{
	return w/english_w;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts dynamic viscosity from si units to english units
///
/// \param[in] vis dynamic viscosity in si units
///
/// \return dynamic viscosity in english units
///////////////////////////////////////////////////////////////////////////////
double convert_vis_si_to_english(double vis)
{
	return vis*english_vis;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts dynamic viscosity from english units to si units
///
/// \param[in] vis dynamic viscosity in english units
///
/// \return dynamic viscosity in si units
///////////////////////////////////////////////////////////////////////////////
double convert_vis_english_to_si(double vis)
{
	return vis/english_vis;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief converts thermal conductivity from si units to english units
///
/// \param[in] k thermal conductivity in si units
///
/// \return thermal conductivity in english units
///////////////////////////////////////////////////////////////////////////////
double convert_k_si_to_english(double k)
{
	return k*english_k;
}
///////////////////////////////////////////////////////////////////////////////
/// \brief converts thermal conductivity from english units to si units
///
/// \param[in] k thermal conductivity in english units
///
/// \return thermal conductivity in si units
///////////////////////////////////////////////////////////////////////////////
double convert_k_english_to_si(double k)
{
	return k/english_k;
}

