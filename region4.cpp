/////////////////////////////////////////////////////////////////////////
///	\file region4.cpp
///	\brief Calculations of properties at saturation conditions (IAPWS Region 4).
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
#include<math.h>
#pragma warning (disable : 4996)

////////////////////////////////////////////////////////
///	\brief Numerical values of the coefficents of the dimensionless saturation equations.
////////////////////////////////////////////////////////
const double n[11] = { 0, 0.11670521452767E+04, -0.72421316703206E+06,
-0.17073846940092E+02, 0.12020824702470E+05, -0.32325550322333E+07,
 0.14915108613530E+02, -0.48232657361591E+04, 0.40511340542057E+06,
-0.23855557567849E+00, 0.65017534844798E+03
 };

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturation pressure as a function of temperature
///
/// \param[in] t temperature in Kelvin
///
/// \return pressure in MPa
///////////////////////////////////////////////////////////////////////////////
double PSAT_T(double t)
{
	const double tstar = 1;  // Kelvin
	const double pstar = 1;  // MPa
	double t_red = t/tstar;
	double theta = t_red + n[9]/(t_red - n[10]);
	double thetasq = theta * theta;
	double a = thetasq + n[1]*theta + n[2];
	double b = n[3]*thetasq + n[4]*theta + n[5];
	double c = n[6]*thetasq + n[7]*theta + n[8];
	double p_red = pow((2*c)/(-b + pow(b*b - 4*a*c,0.5)),4);
	return p_red * pstar;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturation temperature as a function of pressure
///
/// \param[in] p pressure in MPa
///
/// \return temperature in Kelvin
///////////////////////////////////////////////////////////////////////////////
double TSAT_P(double p)
{
	const double tstar = 1;  // Kelvin
	const double pstar = 1;  // MPa
	double p_red = p / pstar;
	double beta = pow(p/pstar, 0.25);
	double betasq = beta*beta;
	double e = betasq + n[3]*beta + n[6];
	double f = n[1]*betasq + n[4]*beta + n[7];
	double g = n[2]*betasq + n[5]*beta + n[8];
	double d = 2*g / (-f - pow(f*f - 4*e*g,0.5));
	double t_red = (n[10] + d - pow(pow(n[10]+d,2) - 4*(n[9]+n[10]*d),0.5))/2;
	return t_red * tstar;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturation specific volume as a function of pressure and
///  specific enthalpy
///
/// \param[in] p pressure in MPa
/// \param[in] h enthalpy in kJ/kg
///
/// \return specific volume in m3/kg
///////////////////////////////////////////////////////////////////////////////
double v_ph_4(double p, double h)
{
	if (p > 16.5292)
		throw "pressure out of bounds for function v_ph_4";
	double t = TSAT_P(p);
	double region1_h = h_pt_1(p, t);
	double region2_h = h_pt_2(p, t);
	double region1_v = v_pt_1(p, t);
	double region2_v = v_pt_2(p, t);
	double v = (h - region1_h)/(region2_h - region1_h)*(region2_v - region1_v) + region1_v;
	return v;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates saturation specific entropy as a function of pressure and
///  specific enthalpy
///
/// \param[in] p pressure in MPa
/// \param[in] h enthalpy in kJ/kg
///
/// \return specific entropy in kJ/kg/K
///////////////////////////////////////////////////////////////////////////////
double s_ph_4(double p, double h)
{
	if (p > 16.5292)
		throw "pressure out of bounds for function s_ph_4";
	double t = TSAT_P(p);
	double region1_h = h_pt_1(p, t);
	double region2_h = h_pt_2(p, t);
	double region1_s = s_pt_1(p, t);
	double region2_s = s_pt_2(p, t);
	double s = (h - region1_h)/(region2_h - region1_h)*(region2_s - region1_s) + region1_s;
	return s;
}
