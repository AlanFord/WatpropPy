/////////////////////////////////////////////////////////////////////////
///	\file region23.cpp
///	\brief Contains functions that define the boundary between IAPWS Regions 2 and 3.
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

////////////////////////////////////////////////////////
///	\brief Numerical values of the coefficents of the IAPWS B23-equation.
////////////////////////////////////////////////////////
const double n[6] = { 0, 0.34805185628969E+03, -0.11671859879975E+01
	, 0.10192970039326E-02, 0.57254459862746E+03, 0.13918839778870E+02
};

///////////////////////////////////////////////////////////////////////////////
/// \brief determines the pressure on the Region2/3 boundary for a given temperature
///
/// \param[in] t temperature
///
/// \return pressure
///////////////////////////////////////////////////////////////////////////////
double b23_p_t(double t)
{
	double pstar = 1;
	double tstar = 1;
	double theta = t/tstar;
	double thetasq = theta*theta;
	double pi = n[1] + n[2]*theta + n[3]*thetasq;
	return pi*pstar;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief determines the temperature on the Region2/3 boundary for a given pressure
///
/// \param[in] p pressure
///
/// \return temperature
///////////////////////////////////////////////////////////////////////////////
double b23_t_p(double p)
{
	double pstar = 1;
	double tstar = 1;
	double pi = p/pstar;
	double theta = n[4] + pow((pi-n[5])/n[3],0.5);
	return theta*tstar;
}
