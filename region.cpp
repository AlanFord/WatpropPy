/////////////////////////////////////////////////////////////////////////
///	\file region.cpp
///	\brief Contains functions that are used to determine the IAPWS region
///  that contains the given thermodynamic statepoint.
///
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

#include "iapws.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief determines if the pressure is within the modeling limits
///
/// \param[in] pressure requested pressure
///
/// \exception std::exception "input pressure out of bounds"
///////////////////////////////////////////////////////////////////////////////
void check_saturated_p(double pressure)
{
	// check for validity of pressure
	if ((pressure < PT) || (pressure > PC))
		throw "input pressure out of bounds";
}

///////////////////////////////////////////////////////////////////////////////
/// \brief determines if the temperature is within the modeling limits
///
/// \param[in] temperature requested temperature
///
/// \exception std::exception "input temperature out of bounds"
///////////////////////////////////////////////////////////////////////////////
void check_saturated_t(double temperature)
{
	// check for validity of temperature
	if ((temperature < TT) || (temperature > TC))
		throw "input temperature out of bounds";
}

///////////////////////////////////////////////////////////////////////////////
/// \brief determines the IAPWS region that contains a given pressure, temperature
///
/// \param[in] pressure requested pressure
/// \param[in] temperature requested temperature
/// \return IAPWS region number 1, 2, 3, or 5
/// \exception std::exception "pressure out of bounds"
/// \exception std::exception "temperature out of bounds"
/// \exception std::exception "pressure/temperature combination out of bounds"
///////////////////////////////////////////////////////////////////////////////
int region_pt(double pressure, double temperature)
{
	// check for gross boundary violations
	if ((pressure > 100) || (pressure <= 0))
		throw "pressure out of bounds";
	if ((temperature > 2273.15) || (temperature < 273.15))
		throw "temperature out of bounds";
	// the following is set to ensure that just a wee bit of conversion error doesn't invalidate
	// a temp of 1073.15 and pressure aboe 50 MPa
	if ((temperature > 1073.15) && (pressure > 50))
		throw "pressure/temperature combination out of bounds";
	// check for Region 1 (note that outer boundaries have already been checked)
	if ((temperature <= 623.15) && (pressure >= PSAT_T(temperature)))
		return 1;
	// check for Region 2
	if ((temperature <= 623.15) && (pressure <= PSAT_T(temperature)))
		return 2;
	if ((temperature <= 863.15) && (pressure <= b23_p_t(temperature)))
		return 2;
	if ((temperature <= 863.15) && (pressure > b23_p_t(temperature)))
		return 3;
	if (temperature <= 1073.15)
		return 2;
	// check for Region 5 (easiest one)
	if (temperature > 1073.15)
		return 5;
	return 3;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief determines the IAPWS region that contains a given pressure, enthalpy
///
/// \param[in] pressure requested pressure
/// \param[in] enthalpy requested enthalpy
/// \return IAPWS region number 1, 2, 3, 4, or 5
/// \exception std::exception "pressure out of bounds"
/// \exception std::exception "enthalpy out of bounds"
///////////////////////////////////////////////////////////////////////////////
int region_ph(double pressure, double enthalpy)
{
	// check for gross boundary violations
	if ((pressure > 100) || (pressure <= 0))
		throw "pressure out of bounds";
	if (pressure <= 16.5292 ) {
		// don't need to worry about region 3
		double test_enthalpy = h_pt_5(pressure, 2273.15)+1;
		if (enthalpy > test_enthalpy)
			throw "enthalpy out of bounds";
		if (enthalpy > h_pt_2(pressure, 1073.15))
			return 5;
		if (enthalpy >= h_pt_2(pressure, TSAT_P(pressure)))
			return 2;
		if (enthalpy > h_pt_1(pressure, TSAT_P(pressure)))
			return 4;
		if (enthalpy < h_pt_1(pressure, 273.15))
			throw "enthalpy out of bounds";
		return 1;
	}
	else {
		if (enthalpy <= h_pt_1(pressure, 623.15))
			return 1;
		if (enthalpy <= h_pt_2(pressure, b23_t_p(pressure)))
			return 3;
		if (enthalpy <= h_pt_2(pressure, 1073.15)+1)
			return 2;
		if (pressure > 50) 
			throw "enthalpy out of bounds";
		else {
			double test_enthalpy = h_pt_5(pressure,2273.15)+1;
			if (enthalpy > test_enthalpy)
				throw "enthalpy out of bounds";
			return 5;
		}
	}
}
