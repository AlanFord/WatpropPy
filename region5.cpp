/////////////////////////////////////////////////////////////////////////
///	\file region5.cpp
///	\brief Calculations of properties of superheated steam (IAPWS Region 5).
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
const double tstar = 1000.;
////////////////////////////////////////////////////////
///	\brief Reference quantity for the reduced pressure.
////////////////////////////////////////////////////////
const double pstar = 1.;
////////////////////////////////////////////////////////
///	\brief Convergence tolerance when searching for zeros of polynomials.
////////////////////////////////////////////////////////
const double tolerance = 1E-18;

//------------------------------------------------------------------------------
// CORRELATION DATA

// Ideal Gas Series Data

////////////////////////////////////////////////////////
///	\brief Length of exponent and coefficient arrays for ideal-gas portion of the dimensionless Gibbs free energy.
////////////////////////////////////////////////////////
#define REG5I_COUNT 6

////////////////////////////////////////////////////////
///	\brief Numerical values of the exponents for ideal-gas portion of the dimensionless
///  Gibbs free energy in IAPWS Region 5.
////////////////////////////////////////////////////////
const int J0[REG5I_COUNT] = { 0, 1, -3, -2, -1, 2 };

////////////////////////////////////////////////////////
///	\brief Numerical values of the coefficents for ideal-gas portion of the dimensionless Gibbs free energy in
///  IAPWS Region 5.
////////////////////////////////////////////////////////
const double N0[REG5I_COUNT] = {
			-0.13179983674201e+02,  0.68540841634434e+01, -0.24805148933466e-01,
		 	 0.36901534980333e+00, -0.31161318213925e+01, -0.32961626538917e+00 };

// Residual Series Data

////////////////////////////////////////////////////////
///	\brief Length of exponent and coefficient arrays for residual portion of the dimensionless Gibbs free energy.
////////////////////////////////////////////////////////
#define REG5R_COUNT 6

////////////////////////////////////////////////////////
///	\brief Numerical values of the reduced pressure exponents for residual portion of the dimensionless
///  Gibbs free energy in IAPWS Region 5.
////////////////////////////////////////////////////////
const int I[REG5R_COUNT] = { 1, 1,1 , 2, 2, 3 };

////////////////////////////////////////////////////////
///	\brief Numerical values of the reduced temperature exponents for residual portion of the dimensionless
///  Gibbs free energy in IAPWS Region 5.
////////////////////////////////////////////////////////
const int J[REG5R_COUNT] = { 1, 2, 3, 3, 9, 7 };

////////////////////////////////////////////////////////
///	\brief Numerical values of the coefficents for residual portion of the dimensionless Gibbs free energy in
///  IAPWS Region 5.
////////////////////////////////////////////////////////
const double N[REG5R_COUNT] = {
			 0.15736404855259e-02,  0.90153761673944e-03, -0.50270077677648e-02,
			 0.22440037409485e-05, -0.41163275453471e-05,  0.37919454822955e-07 };

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates ideal-gas portion of the dimensionless Gibbs free energy for IAPWS Region 5
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return ideal-gas portion of dimensionless Gibbs free energy
///////////////////////////////////////////////////////////////////////////////
double r5gamma0(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG5I_COUNT; i++)
	{
		sum += N0[i]*pow(tau,J0[i]);
	}
	return log(pi) + sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of ideal-gas portion of the dimensionless Gibbs free energy
///  with respect to reduced pressure for IAPWS Region 5
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of the ideal-gas portion of dimensionless Gibbs free energy with respect
///  to reduced pressure
///////////////////////////////////////////////////////////////////////////////
double r5gammapi0(double pi, double tau)
{
	return 1/pi;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates second order partial derivative of ideal-gas portion of the dimensionless Gibbs free energy
///  with respect to reduced pressure for IAPWS Region 5
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return second order partial derivative of ideal-gas portion of the dimensionless Gibbs free energy with respect
///  to reduced pressure
///////////////////////////////////////////////////////////////////////////////
double r5gammapipi0(double pi, double tau)
{
	return 1/pow(pi,2);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of ideal-gas portion of the dimensionless Gibbs free energy
///  with respect to reduced temperature for IAPWS Region 5
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of ideal-gas portion of the dimensionless Gibbs free energy with respect
///  to reduced temperature
///////////////////////////////////////////////////////////////////////////////
double r5gammatau0(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG5I_COUNT; i++)
	{
		sum += N0[i]*J0[i]*pow(tau,J0[i]-1);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates second order partial derivative of ideal-gas portion of the dimensionless Gibbs free energy
///  with respect to reduced temperature for IAPWS Region 5
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return second order partial derivative of ideal-gas portion of the dimensionless Gibbs free energy with respect
///  to reduced temperature
///////////////////////////////////////////////////////////////////////////////
double r5gammatautau0(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG5I_COUNT; i++)
	{
		sum += N0[i]*J0[i]*(J0[i]-1)*pow(tau,J0[i]-2);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of ideal-gas portion of the dimensionless Gibbs free energy
///  with respect to reduced temperature and reduced pressure for IAPWS Region 5
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of ideal-gas portion of the dimensionless Gibbs free energy with respect
///  to reduced temperature and reduced pressure
///////////////////////////////////////////////////////////////////////////////
double r5gammapitau0(double pi, double tau)
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates residual portion of the dimensionless Gibbs free energy for IAPWS Region 5
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return residual portion of dimensionless Gibbs free energy
///////////////////////////////////////////////////////////////////////////////
double r5gammar(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG5R_COUNT; i++)
	{
		sum += N[i]*pow(pi,I[i])*pow(tau,J[i]);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of residual portion of the dimensionless Gibbs free energy
///  with respect to reduced pressure for IAPWS Region 5
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of the residual portion of dimensionless Gibbs free energy with respect
///  to reduced pressure
///////////////////////////////////////////////////////////////////////////////
double r5gammapir(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG5R_COUNT; i++)
	{
		sum += N[i]*I[i]*pow(pi,I[i]-1)*pow(tau,J[i]);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates second order partial derivative of residual portion of the dimensionless Gibbs free energy
///  with respect to reduced pressure for IAPWS Region 5
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return second order partial derivative of residual portion of the dimensionless Gibbs free energy with respect
///  to reduced pressure
///////////////////////////////////////////////////////////////////////////////
double r5gammapipir(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG5R_COUNT; i++)
	{
		sum += N[i]*I[i]*(I[i]-1)*pow(pi,I[i]-2)*pow(tau,J[i]);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of residual portion of the dimensionless Gibbs free energy
///  with respect to reduced temperature for IAPWS Region 5
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of residual portion of the dimensionless Gibbs free energy with respect
///  to reduced temperature
///////////////////////////////////////////////////////////////////////////////
double r5gammataur(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG5R_COUNT; i++)
	{
		sum += N[i]*pow(pi,I[i])*J[i]*pow(tau,J[i]-1);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates second order partial derivative of residual portion of the dimensionless Gibbs free energy
///  with respect to reduced temperature for IAPWS Region 5
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return second order partial derivative of residual portion of the dimensionless Gibbs free energy with respect
///  to reduced temperature
///////////////////////////////////////////////////////////////////////////////
double r5gammatautaur(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG5R_COUNT; i++)
	{
		sum += N[i]*pow(pi,I[i])*J[i]*(J[i]-1)*pow(tau,J[i]-2);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of residual portion of the dimensionless Gibbs free energy
///  with respect to reduced temperature and reduced pressure for IAPWS Region 5
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of residual portion of the dimensionless Gibbs free energy with respect
///  to reduced temperature and reduced pressure
///////////////////////////////////////////////////////////////////////////////
double r5gammapitaur(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG5R_COUNT; i++)
	{
		sum += N[i]*I[i]*pow(pi,I[i]-1)*J[i]*pow(tau,J[i]-1);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific volume as a function of pressure and temperature in IAPWS Region 5
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return specific volume
///////////////////////////////////////////////////////////////////////////////
double v_pt_5(double p,double t)
{
	double pi = p/pstar;
	double tau = tstar/t;
	// note that p has units of MPa, so multiply by 1E3 to get the proper units
	return (r5gammapi0(pi,tau) + r5gammapir(pi,tau))*pi*R*t/(p*1E3);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific entropy as a function of pressure and temperature in IAPWS Region 5
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return specific entropy
///////////////////////////////////////////////////////////////////////////////
double s_pt_5(double p,double t)
{
	double pi = p/pstar;
	double tau = tstar/t;
	return R*(tau*(r5gammatau0(pi,tau) + r5gammataur(pi,tau)) - (r5gamma0(pi,tau) + r5gammar(pi,tau)));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific enthalpy as a function of pressure and temperature in IAPWS Region 5
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return specific enthalpy
///////////////////////////////////////////////////////////////////////////////
double h_pt_5(double p,double t)
{
	double pi = p/pstar;
	double tau = tstar/t;
	return tau*(r5gammatau0(pi,tau) + r5gammataur(pi,tau)) *R*t;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates isobaric heat capacity as a function of pressure and temperature in IAPWS Region 5
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return isobaric heat capacity
///////////////////////////////////////////////////////////////////////////////
double cp_pt_5(double p,double t)
{
	double pi = p/pstar;
	double tau = tstar/t;
	return (-pow(tau,2))*(r5gammatautau0(pi,tau) + r5gammatautaur(pi,tau)) * R;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates speed of sound as a function of pressure and temperature in IAPWS Region 5
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return speed of sound
///////////////////////////////////////////////////////////////////////////////
double w_pt_5(double p,double t)
{
	double pi = p/pstar;
	double tau = tstar/t;
	double top = 1 + 2*pi*r5gammapir(pi,tau) + pow(pi*r5gammapir(pi,tau),2);
	double bottom = pow(1 + pi*r5gammapir(pi,tau) - tau*pi*r5gammapitaur(pi,tau), 2);
	bottom = bottom / (pow(tau,2) * (r5gammatautau0(pi,tau) + r5gammatautaur(pi,tau)));
	bottom = (1 - pow(pi,2)*r5gammapipir(pi,tau)) + bottom;
	// note that 1E3 added to make the units work
	return pow(top/bottom *R*t*1E3,0.5);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates temperature as a function of pressure and specific enthalpy in IAPWS Region 5
///
/// \param[in] p  pressure
/// \param[in] h  specific enthalpy
///
/// \return temperature
///////////////////////////////////////////////////////////////////////////////
double t_ph_5(double p, double h)
{
	double t_low = 1073.15 - 1;
	double t_high = 2273.15 + 1;
	return zeroin2(h_pt_5, p, t_low, t_high, h, tolerance);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific volume as a function of pressure and specific enthalpy in IAPWS Region 5
///
/// \param[in] p  pressure
/// \param[in] h  specific enthalpy
///
/// \return specific volume
///////////////////////////////////////////////////////////////////////////////
double v_ph_5(double p, double h)
{
	double t = t_ph_5(p, h);
	return v_pt_5(p, t);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific entropy as a function of pressure and specific enthalpy in IAPWS Region 5
///
/// \param[in] p  pressure
/// \param[in] h  specific enthalpy
///
/// \return specific entropy
///////////////////////////////////////////////////////////////////////////////
double s_ph_5(double p, double h)
{
	double t = t_ph_5(p, h);
	return s_pt_5(p, t);
}
