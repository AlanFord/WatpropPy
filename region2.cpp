/////////////////////////////////////////////////////////////////////////
///	\file region2.cpp
///	\brief Calculations of properties of superheated steam (IAPWS Region 2).
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
const double tstar = 540;
////////////////////////////////////////////////////////
///	\brief Reference quantity for the reduced pressure.
////////////////////////////////////////////////////////
const double pstar = 1;
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
#define REG2I_COUNT 9

////////////////////////////////////////////////////////
///	\brief Numerical values of the exponents for ideal-gas portion of the dimensionless
///  Gibbs free energy in IAPWS Region 2.
////////////////////////////////////////////////////////
const int J0[REG2I_COUNT] = { 0, 1, -5, -4, -3, -2, -1, 2, 3 };

////////////////////////////////////////////////////////
///	\brief Numerical values of the coefficents for ideal-gas portion of the dimensionless Gibbs free energy in
///  IAPWS Region 2.
////////////////////////////////////////////////////////
const double N0[REG2I_COUNT] = {
            -0.96927686500217E+01, 0.10086655968018E+02, -0.56087911283020E-02,
            0.71452738081455E-01, -0.40710498223928E+00, 0.14240819171444E+01, -0.43839511319450E+01,
            -0.28408632460772E+00, 0.21268463753307E-01
        };

// Residual Series Data

////////////////////////////////////////////////////////
///	\brief Length of exponent and coefficient arrays for residual portion of the dimensionless Gibbs free energy.
////////////////////////////////////////////////////////
#define REG2R_COUNT 43

////////////////////////////////////////////////////////
///	\brief Numerical values of the reduced pressure exponents for residual portion of the dimensionless
///  Gibbs free energy in IAPWS Region 2.
////////////////////////////////////////////////////////
const int I[REG2R_COUNT] = {
                                       1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 5, 6, 6, 6, 7,
                                       7, 7, 8, 8, 9, 10, 10, 10, 16, 16, 18, 20, 20, 20, 21, 22, 23, 24, 24, 24
                                   };

////////////////////////////////////////////////////////
///	\brief Numerical values of the reduced temperature exponents for residual portion of the dimensionless
///  Gibbs free energy in IAPWS Region 2.
////////////////////////////////////////////////////////
const int J[REG2R_COUNT] = {
                                       0, 1, 2, 3, 6, 1, 2, 4, 7, 36, 0, 1, 3, 6, 35, 1, 2, 3, 7, 3, 16, 35,
                                       0, 11, 25, 8, 36, 13, 4, 10, 14, 29, 50, 57, 20, 35, 48, 21, 53, 39, 26, 40, 58
                                   };

////////////////////////////////////////////////////////
///	\brief Numerical values of the coefficents for residual portion of the dimensionless Gibbs free energy in
///  IAPWS Region 2.
////////////////////////////////////////////////////////
const double N[REG2R_COUNT] = {
            -0.17731742473213E-02, -0.17834862292358E-01, -0.45996013696365E-01,
            -0.57581259083432E-01, -0.50325278727930E-01, -0.33032641670203E-04, -0.18948987516315E-03,
            -0.39392777243355E-02, -0.43797295650573E-01, -0.26674547914087E-04, 0.20481737692309E-07,
            0.43870667284435E-06, -0.32277677238570E-04, -0.15033924542148E-02, -0.40668253562649E-01,
            -0.78847309559367E-09, 0.12790717852285E-07, 0.48225372718507E-06, 0.22922076337661E-05,
            -0.16714766451061E-10, -0.21171472321355E-02, -0.23895741934104E+02, -0.59059564324270E-17,
            -0.12621808899101E-05, -0.38946842435739E-01, 0.11256211360459E-10, -0.82311340897998E+01,
            0.19809712802088E-07, 0.10406965210174E-18, -0.10234747095929E-12, -0.10018179379511E-08,
            -0.80882908646985E-10, 0.10693031879409E+00, -0.33662250574171E+00, 0.89185845355421E-24,
            0.30629316876232E-12, -0.42002467698208E-05, -0.59056029685639E-25, 0.37826947613457E-05,
            -0.12768608934681E-14, 0.73087610595061E-28, 0.55414715350778E-16, -0.94369707241210E-06
        };

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates ideal-gas portion of the dimensionless Gibbs free energy for IAPWS Region 2
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return ideal-gas portion of dimensionless Gibbs free energy
///////////////////////////////////////////////////////////////////////////////
double gamma0(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG2I_COUNT; i++)
	{
		sum += N0[i]*pow(tau,J0[i]);
	}
	return log(pi) + sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of ideal-gas portion of the dimensionless Gibbs free energy
///  with respect to reduced pressure for IAPWS Region 2
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of the ideal-gas portion of dimensionless Gibbs free energy with respect
///  to reduced pressure
///////////////////////////////////////////////////////////////////////////////
double gammapi0(double pi, double tau)
{
	return 1/pi;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates second order partial derivative of ideal-gas portion of the dimensionless Gibbs free energy
///  with respect to reduced pressure for IAPWS Region 2
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return second order partial derivative of ideal-gas portion of the dimensionless Gibbs free energy with respect
///  to reduced pressure
///////////////////////////////////////////////////////////////////////////////
double gammapipi0(double pi, double tau)
{
	return 1/pow(pi,2);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of ideal-gas portion of the dimensionless Gibbs free energy
///  with respect to reduced temperature for IAPWS Region 2
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of ideal-gas portion of the dimensionless Gibbs free energy with respect
///  to reduced temperature
///////////////////////////////////////////////////////////////////////////////
double gammatau0(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG2I_COUNT; i++)
	{
		sum += N0[i]*J0[i]*pow(tau,J0[i]-1);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates second order partial derivative of ideal-gas portion of the dimensionless Gibbs free energy
///  with respect to reduced temperature for IAPWS Region 2
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return second order partial derivative of ideal-gas portion of the dimensionless Gibbs free energy with respect
///  to reduced temperature
///////////////////////////////////////////////////////////////////////////////
double gammatautau0(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG2I_COUNT; i++)
	{
		sum += N0[i]*J0[i]*(J0[i]-1)*pow(tau,J0[i]-2);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of ideal-gas portion of the dimensionless Gibbs free energy
///  with respect to reduced temperature and reduced pressure for IAPWS Region 2
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of ideal-gas portion of the dimensionless Gibbs free energy with respect
///  to reduced temperature and reduced pressure
///////////////////////////////////////////////////////////////////////////////
double gammapitau0(double pi, double tau)
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates residual portion of the dimensionless Gibbs free energy for IAPWS Region 2
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return residual portion of dimensionless Gibbs free energy
///////////////////////////////////////////////////////////////////////////////
double gammar(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG2R_COUNT; i++)
	{
		sum += N[i]*pow(pi,I[i])*pow(tau-0.5,J[i]);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of residual portion of the dimensionless Gibbs free energy
///  with respect to reduced pressure for IAPWS Region 2
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of the residual portion of dimensionless Gibbs free energy with respect
///  to reduced pressure
///////////////////////////////////////////////////////////////////////////////
double gammapir(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG2R_COUNT; i++)
	{
		sum += N[i]*I[i]*pow(pi,I[i]-1)*pow(tau-0.5,J[i]);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates second order partial derivative of residual portion of the dimensionless Gibbs free energy
///  with respect to reduced pressure for IAPWS Region 2
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return second order partial derivative of residual portion of the dimensionless Gibbs free energy with respect
///  to reduced pressure
///////////////////////////////////////////////////////////////////////////////
double gammapipir(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG2R_COUNT; i++)
	{
		sum += N[i]*I[i]*(I[i]-1)*pow(pi,I[i]-2)*pow(tau-0.5,J[i]);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of residual portion of the dimensionless Gibbs free energy
///  with respect to reduced temperature for IAPWS Region 2
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of residual portion of the dimensionless Gibbs free energy with respect
///  to reduced temperature
///////////////////////////////////////////////////////////////////////////////
double gammataur(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG2R_COUNT; i++)
	{
		sum += N[i]*pow(pi,I[i])*J[i]*pow(tau-0.5,J[i]-1);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates second order partial derivative of residual portion of the dimensionless Gibbs free energy
///  with respect to reduced temperature for IAPWS Region 2
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return second order partial derivative of residual portion of the dimensionless Gibbs free energy with respect
///  to reduced temperature
///////////////////////////////////////////////////////////////////////////////
double gammatautaur(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG2R_COUNT; i++)
	{
		sum += N[i]*pow(pi,I[i])*J[i]*(J[i]-1)*pow(tau-0.5,J[i]-2);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of residual portion of the dimensionless Gibbs free energy
///  with respect to reduced temperature and reduced pressure for IAPWS Region 2
///
/// \param[in] pi reduced pressure
/// \param[in] tau reduced temperature
///
/// \return partial derivative of residual portion of the dimensionless Gibbs free energy with respect
///  to reduced temperature and reduced pressure
///////////////////////////////////////////////////////////////////////////////
double gammapitaur(double pi, double tau)
{
	double sum = 0;
	for (int i=0; i<REG2R_COUNT; i++)
	{
		sum += N[i]*I[i]*pow(pi,I[i]-1)*J[i]*pow(tau-0.5,J[i]-1);
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific volume as a function of pressure and temperature in IAPWS Region 2
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return specific volume
///////////////////////////////////////////////////////////////////////////////
double v_pt_2(double p,double t)
{
	double pi = p/pstar;
	double tau = tstar/t;
	// note that p has units of MPa, so multiply by 1E3 to get the proper units
	return (gammapi0(pi,tau) + gammapir(pi,tau))*pi*R*t/(p*1E3);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific entropy as a function of pressure and temperature in IAPWS Region 2
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return specific entropy
///////////////////////////////////////////////////////////////////////////////
double s_pt_2(double p,double t)
{
	double pi = p/pstar;
	double tau = tstar/t;
	return R*(tau*(gammatau0(pi,tau) + gammataur(pi,tau)) - (gamma0(pi,tau) + gammar(pi,tau)));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific enthalpy as a function of pressure and temperature in IAPWS Region 2
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return specific enthalpy
///////////////////////////////////////////////////////////////////////////////
double h_pt_2(double p,double t)
{
	double pi = p/pstar;
	double tau = tstar/t;
	return tau*(gammatau0(pi,tau) + gammataur(pi,tau)) *R*t;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates isobaric heat capacity as a function of pressure and temperature in IAPWS Region 2
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return isobaric heat capacity
///////////////////////////////////////////////////////////////////////////////
double cp_pt_2(double p,double t)
{
	double pi = p/pstar;
	double tau = tstar/t;
	return (-pow(tau,2))*(gammatautau0(pi,tau) + gammatautaur(pi,tau)) * R;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates isochoric heat capacity as a function of pressure and temperature in IAPWS Region 2
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return isochoric heat capacity
///////////////////////////////////////////////////////////////////////////////
double cv_pt_2(double p,double t)
{
	double pi = p/pstar;
	double tau = tstar/t;
	double part1 = pow(tau,2)*(gammatautau0(pi,tau) + gammatautaur(pi,tau));
	double zip = 1 + pi*gammapir(pi,tau) - tau*pi*gammapitaur(pi,tau);
	double part2 = pow(zip,2)/(1 - pow(pi,2)*gammapipir(pi,tau));
	return (-part1 - part2) * R;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates speed of sound as a function of pressure and temperature in IAPWS Region 2
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return speed of sound
///////////////////////////////////////////////////////////////////////////////
double w_pt_2(double p,double t)
{
	double pi = p/pstar;
	double tau = tstar/t;
	double top = 1 + 2*pi*gammapir(pi,tau) + pow(pi*gammapir(pi,tau),2);
	double bottom = pow(1 + pi*gammapir(pi,tau) - tau*pi*gammapitaur(pi,tau), 2);
	bottom = bottom / (pow(tau,2) * (gammatautau0(pi,tau) + gammatautaur(pi,tau)));
	bottom = (1 - pow(pi,2)*gammapipir(pi,tau)) + bottom;
	// note that 1E3 added to make the units work
	return pow(top/bottom *R*t*1E3,0.5);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates temperature as a function of pressure and specific enthalpy in IAPWS Region 2
///
/// \param[in] p  pressure
/// \param[in] h  specific enthalpy
///
/// \return temperature
///////////////////////////////////////////////////////////////////////////////
double t_ph_2(double p, double h)
{
	double t_low;
	if (p < 16.5292)
		t_low = TSAT_P(p) - 1;
	else
		t_low = b23_t_p(p) - 1;
	double t_high = 1073.15 + 1;
	return zeroin2(h_pt_2, p, t_low, t_high, h, tolerance);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific volume as a function of pressure and specific enthalpy in IAPWS Region 2
///
/// \param[in] p  pressure
/// \param[in] h  specific enthalpy
///
/// \return specific volume
///////////////////////////////////////////////////////////////////////////////
double v_ph_2(double p, double h)
{
	double t = t_ph_2(p, h);
	return v_pt_2(p, t);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific entropy as a function of pressure and specific enthalpy in IAPWS Region 2
///
/// \param[in] p  pressure
/// \param[in] h  specific enthalpy
///
/// \return specific entropy
///////////////////////////////////////////////////////////////////////////////
double s_ph_2(double p, double h)
{
	double t = t_ph_2(p, h);
	return s_pt_2(p, t);
}
