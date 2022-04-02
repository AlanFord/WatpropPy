/////////////////////////////////////////////////////////////////////////
///	\file region1.cpp
///	\brief Calculations of properties of compressed liquid (IAPWS Region 1).
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
#include "utilities.h"

////////////////////////////////////////////////////////
///	\brief Reference quantity for the reduced temperature.
////////////////////////////////////////////////////////
const double tstar = 1386;    // K
////////////////////////////////////////////////////////
///	\brief Reference quantity for the reduced pressure.
////////////////////////////////////////////////////////
const double pstar = 16.53;   // MPa
////////////////////////////////////////////////////////
///	\brief Convergence tolerance when searching for zeros of polynomials.
////////////////////////////////////////////////////////
const double tolerance = 1E-18;

////////////////////////////////////////////////////////
///	\brief Length of exponent and coefficient arrays.
////////////////////////////////////////////////////////
#define REG1_COUNT 34

////////////////////////////////////////////////////////
///	\brief Numerical values of the reduced pressure exponents of the dimensionless
///  Gibbs free energy in IAPWS Region 1.
////////////////////////////////////////////////////////
const int I[REG1_COUNT] = {
                                      0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4,
                                      4, 4, 5, 8, 8, 21, 23, 29, 30, 31, 32
                                  };

////////////////////////////////////////////////////////
///	\brief Numerical values of the reduced temperature exponents of the dimensionless
///  Gibbs free energy in IAPWS Region 1.
////////////////////////////////////////////////////////
const int J[REG1_COUNT] = {
                                      -2, -1, 0, 1, 2, 3, 4, 5, -9, -7, -1, 0, 1, 3, -3, 0, 1, 3, 17, -4,
                                      0, 6, -5, -2, 10, -8, -11, -6, -29, -31, -38, -39, -40, -41
                                  };

////////////////////////////////////////////////////////
///	\brief Numerical values of the coefficents of the dimensionless Gibbs free energy in
///  IAPWS Region 1.
////////////////////////////////////////////////////////
const double n[REG1_COUNT] = {
            0.14632971213167E+00, -0.84548187169114E+00, -0.37563603672040E+01,
            0.33855169168385E+01, -0.95791963387872E+00, 0.15772038513228E+00, -0.16616417199501E-01,
            0.81214629983568E-03, 0.28319080123804E-03, -0.60706301565874E-03, -0.18990068218419E-01,
            -0.32529748770505E-01, -0.21841717175414E-01, -0.52838357969930E-04, -0.47184321073267E-03,
            -0.30001780793026E-03, 0.47661393906987E-04, -0.44141845330846E-05, -0.72694996297594E-15,
            -0.31679644845054E-04, -0.28270797985312E-05, -0.85205128120103E-09, -0.22425281908000E-05,
            -0.65171222895601E-06, -0.14341729937924E-12, -0.40516996860117E-06, -0.12734301741641E-08,
            -0.17424871230634E-09, -0.68762131295531E-18, 0.14478307828521E-19, 0.26335781662795E-22,
            -0.11947622640071E-22, 0.18228094581404E-23, -0.93537087292458E-25
        };

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates dimensionless Gibbs free energy for IAPWS Region 1
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return dimensionless Gibbs free energy
///////////////////////////////////////////////////////////////////////////////
double gamma(double pi, double tau)
{
	double answer = 0;
	for (int i=0; i<REG1_COUNT; i++) {
		answer += n[i] * pow(7.1 - pi,I[i]) * pow(tau - 1.222,J[i]);
	}
	return answer;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of the dimensionless Gibbs free energy
///  with respect to reduced pressure for IAPWS Region 1
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of the dimensionless Gibbs free energy with respect
///  to reduced pressure
///////////////////////////////////////////////////////////////////////////////
double gammapi(double pi, double tau)
{
	double answer = 0;
	for (int i=0; i<REG1_COUNT; i++) {
		answer += (-n[i] * I[i] * pow(7.1 - pi,I[i]-1) * pow(tau - 1.222,J[i]));
	}
	return answer;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates second order partial derivative of the dimensionless Gibbs free energy
///  with respect to reduced pressure for IAPWS Region 1
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return second order partial derivative of the dimensionless Gibbs free energy with respect
///  to reduced pressure
///////////////////////////////////////////////////////////////////////////////
double gammapipi(double pi, double tau)
{
	double answer = 0;
	for (int i=0; i<REG1_COUNT; i++) {
		answer += n[i] * I[i] * (I[i] - 1) * pow(7.1 - pi, I[i] - 2) * pow(tau - 1.222, J[i]);
	}
	return answer;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of the dimensionless Gibbs free energy
///  with respect to reduced temperature for IAPWS Region 1
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of the dimensionless Gibbs free energy with respect
///  to reduced temperature
///////////////////////////////////////////////////////////////////////////////
double gammatau(double pi, double tau)
{
	double answer = 0;
	for (int i=0; i<REG1_COUNT; i++) {
		answer += n[i] * pow(7.1 - pi, I[i]) * J[i] * pow(tau - 1.222, J[i] - 1);
	}
	return answer;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates second order partial derivative of the dimensionless Gibbs free energy
///  with respect to reduced temperature for IAPWS Region 1
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return second order partial derivative of the dimensionless Gibbs free energy with respect
///  to reduced temperature
///////////////////////////////////////////////////////////////////////////////
double gammatautau(double pi, double tau)
{
	double answer = 0;
	for (int i=0; i<REG1_COUNT; i++) {
		answer += n[i] * pow(7.1 - pi, I[i]) * J[i] * (J[i] -1) * pow(tau - 1.222, J[i] - 2);
	}
	return answer;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of the dimensionless Gibbs free energy
///  with respect to reduced temperature and reduced pressure for IAPWS Region 1
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of the dimensionless Gibbs free energy with respect
///  to reduced temperature and reduced pressure
///////////////////////////////////////////////////////////////////////////////
double gammapitau(double pi, double tau)
{
	double answer = 0;
	for (int i=0; i<REG1_COUNT; i++) {
		answer += -n[i] * I[i] * pow(7.1 - pi, I[i] -1) * J[i] * pow(tau - 1.222, J[i] - 1);
	}
	return answer;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific volume as a function of pressure and temperature in IAPWS Region 1
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return specific volume
///////////////////////////////////////////////////////////////////////////////
double v_pt_1(double p,double t)
{
	double tau = tstar/t;
	double pi = p/pstar;
	// note that p has units of MPa, so multiply by 1E3 to get the proper units
	return pi * gammapi(pi,tau) * R * t /(p*1E3);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific entropy as a function of pressure and temperature in IAPWS Region 1
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return specific entropy
///////////////////////////////////////////////////////////////////////////////
double s_pt_1(double p,double t)
{
	double tau = tstar/t;
	double pi = p/pstar;
	return (tau * gammatau(pi,tau) - gamma(pi,tau)) * R;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific enthalpy as a function of pressure and temperature in IAPWS Region 1
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return specific enthalpy
///////////////////////////////////////////////////////////////////////////////
double h_pt_1(double p,double t)
{
	double tau = tstar/t;
	double pi = p/pstar;
	return tau * gammatau(pi,tau) * R * t;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates isobaric heat capacity as a function of pressure and temperature in IAPWS Region 1
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return isobaric heat capacity
///////////////////////////////////////////////////////////////////////////////
double cp_pt_1(double p,double t)
{
	double tau = tstar/t;
	double pi = p/pstar;
	return -tau*tau * gammatautau(pi,tau) * R;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates isochoric heat capacity as a function of pressure and temperature in IAPWS Region 1
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return isochoric heat capacity
///////////////////////////////////////////////////////////////////////////////
double cv_pt_1(double p,double t)
{
	double tau = tstar/t;
	double pi = p/pstar;
	double part1 = -tau*tau * gammatautau(pi,tau);
	double part2 = pow(gammapi(pi,tau) - tau*gammapitau(pi,tau),2)/gammapipi(pi,tau);
	return (part1 + part2 ) * R;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates speed of sound as a function of pressure and temperature in IAPWS Region 1
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return speed of sound
///////////////////////////////////////////////////////////////////////////////
double w_pt_1(double p,double t)
{
	double tau = tstar/t;
	double pi = p/pstar;
	double result = (pow(gammapi(pi,tau),2)/(
		pow(gammapi(pi,tau) - tau*gammapitau(pi,tau),2)/(tau*tau*gammatautau(pi,tau)) - gammapipi(pi,tau))) *R*t;
	// note that 1E3 added to make the units work
	return pow(result*1E3,0.5);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates temperature as a function of pressure and specific enthalpy in IAPWS Region 1
///
/// \param[in] p  pressure
/// \param[in] h  specific enthalpy
///
/// \return temperature
///////////////////////////////////////////////////////////////////////////////
double t_ph_1(double p, double h)
{
	double t_low = 273.15 - 1;
	double t_high;
	if (p < 16.5292)
		t_high = TSAT_P(p) + 1;
	else
		t_high = 623.15 + 1;
	return zeroin2(h_pt_1, p, t_low, t_high, h, tolerance);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific volume as a function of pressure and specific enthalpy in IAPWS Region 1
///
/// \param[in] p  pressure
/// \param[in] h  specific enthalpy
///
/// \return specific volume
///////////////////////////////////////////////////////////////////////////////
double v_ph_1(double p, double h)
{
	double t = t_ph_1(p, h);
	return v_pt_1(p, t);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific entropy as a function of pressure and specific enthalpy in IAPWS Region 1
///
/// \param[in] p  pressure
/// \param[in] h  specific enthalpy
///
/// \return specific entropy
///////////////////////////////////////////////////////////////////////////////
double s_ph_1(double p, double h)
{
	double t = t_ph_1(p, h);
	return s_pt_1(p, t);
}
