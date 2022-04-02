/////////////////////////////////////////////////////////////////////////
///	\file region3.cpp
///	\brief Calculations of properties of liquid and steam in the vicinity of the critical point (IAPWS Region 3).
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
///	\brief Reference quantity for the reduced density.
////////////////////////////////////////////////////////
const double rhostar = 322;     // kg/m3
////////////////////////////////////////////////////////
///	\brief Reference quantity for the reduced temperature.
////////////////////////////////////////////////////////
const double tstar = 647.096;   // K
////////////////////////////////////////////////////////
///	\brief Convergence tolerance when searching for zeros of polynomials.
////////////////////////////////////////////////////////
const double tolerance = 1E-18;
//------------------------------------------------------------------------------
// DATA TO SUPPORT SEARCHING FOR SATURATION DENSITIES

////////////////////////////////////////////////////////
///	length of the sat_temps,
/// vapor_density_upper_limit, and
/// liquid_density_lower_limit arrays
////////////////////////////////////////////////////////
#define SAT_TEMPS_COUNT 33

////////////////////////////////////////////////////////
///	array of temperatures corresponding to the densities
/// in the vapor_density_upper_limit and
/// liquid_density_lower_limit arrays
////////////////////////////////////////////////////////
const double sat_temps[SAT_TEMPS_COUNT] = {
	623.15, 625.15, 627.15, 629.15, 631.15, 633.15, 634.15, 635.15,
	636.15, 637.15, 638.15, 639.15, 640.15, 641.15, 642.15, 643.15,
	644.15, 645.15, 646.15, 646.4, 646.65, 646.75, 646.85, 646.95,
	647.0, 647.05, 647.06, 647.07, 647.08, 647.09, 647.093, 647.095, 647.096 
};

////////////////////////////////////////////////////////
///	array of vapor densities used as limits when searching for density
/// as a function of temperature and pressure below the critical point
/// in IAPWS Region 3
////////////////////////////////////////////////////////
const double vapor_density_upper_limit[SAT_TEMPS_COUNT] = {
	161.318, 166.327, 171.649, 177.336, 183.453, 190.088, 193.637, 
	197.367, 201.303, 205.478, 209.932, 214.719, 219.914, 225.621, 
	231.996, 239.289, 247.945, 258.897, 274.814, 280.543, 287.863, 
	291.548, 295.972, 301.663, 305.393, 310.431, 311.755, 313.286, 
	315.16,  317.812, 319.04,  320.292, 323 // 321.998 
};

////////////////////////////////////////////////////////
///	array of liquid densities used as limits when searching for density
/// as a function of temperature and pressure below the critical point
/// in IAPWS Region 3
////////////////////////////////////////////////////////
const double liquid_density_lower_limit[SAT_TEMPS_COUNT] = {
	503.431, 496.687, 489.604, 482.129, 474.193, 465.702, 461.209, 
	456.526, 451.624, 446.473, 441.029, 435.238, 429.027, 422.291, 
	414.876, 406.537, 396.845, 384.914, 368.263, 362.468, 355.205, 
	351.601, 347.308, 341.823, 338.234, 333.37,  332.086, 330.597, 
	328.766, 326.16,  324.946, 323.703, 321 // 321.998 
};
//------------------------------------------------------------------------------
// CORRELATION DATA

// NOTE: equations for region 3 are in (rho,T) not (p,T) and series do not use the first value of REGION3_N[i].
// (that's so that the equations can be more readily checked with those published)

////////////////////////////////////////////////////////
///	\brief Length of exponent and coefficient arrays for ideal-gas portion of the
///  dimensionless Helmholtz free energy.
////////////////////////////////////////////////////////
#define REG3_COUNT 40

////////////////////////////////////////////////////////
///	\brief Numerical values of the reduced density exponents for ideal-gas
///  portion of the dimensionless Helmholtz free energy in IAPWS Region 3.
////////////////////////////////////////////////////////
const int I[REG3_COUNT] = {
                                      0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3,
                                      4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 8, 9, 9, 10, 10, 11
                                  };

////////////////////////////////////////////////////////
///	\brief Numerical values of the reduced temperature exponents for ideal-gas
///  portion of the dimensionless Helmholtz free energy in IAPWS Region 3.
////////////////////////////////////////////////////////
const int J[REG3_COUNT] = {
                                      0, 0, 1, 2, 7, 10, 12, 23, 2, 6, 15, 17, 0, 2, 6, 7, 22, 26, 0, 2, 4,
                                      16, 26, 0, 2, 4, 26, 1, 3, 26, 0, 2, 26, 2, 26, 2, 26, 0, 1, 26
                                  };

////////////////////////////////////////////////////////
///	\brief Numerical values of the coefficents for the dimensionless Helmholtz free energy in
///  IAPWS Region 3.
////////////////////////////////////////////////////////
const double N[REG3_COUNT] = {
            0.10658070028513E+01, -0.15732845290239E+02, 0.20944396974307E+02,
            -0.76867707878716E+01, 0.26185947787954E+01, -0.28080781148620E+01, 0.12053369696517E+01,
            -0.84566812812502E-02, -0.12654315477714E+01, -0.11524407806681E+01, 0.88521043984318E+00,
            -0.64207765181607E+00, 0.38493460186671E+00, -0.85214708824206E+00, 0.48972281541877E+01,
            -0.30502617256965E+01, 0.39420536879154E-01, 0.12558408424308E+00, -0.27999329698710E+00,
            0.13899799569460E+01, -0.20189915023570E+01, -0.82147637173963E-02, -0.47596035734923E+00,
            0.43984074473500E-01, -0.44476435428739E+00, 0.90572070719733E+00, 0.70522450087967E+00,
            0.10770512626332E+00, -0.32913623258954E+00, -0.50871062041158E+00, -0.22175400873096E-01,
            0.94260751665092E-01, 0.16436278447961E+00, -0.13503372241348E-01, -0.14834345352472E-01,
            0.57922953628084E-03, 0.32308904703711E-02, 0.80964802996215E-04, -0.16557679795037E-03,
            -0.44923899061815E-04
        };

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates ideal-gas portion of the dimensionless Helmholtz free energy for IAPWS Region 3
///
/// \param[in] del reduced density
/// \param[in] tau reduced temperature
///
/// \return ideal-gas portion of dimensionless Helmholtz free energy
///////////////////////////////////////////////////////////////////////////////
double phi(double del, double tau)
{
	double result = N[0]*log(del);
	for (int i=1; i<REG3_COUNT; i++) {
		result += N[i]*pow(del,I[i])*pow(tau,J[i]);
	}
	return result;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of ideal-gas portion of the dimensionless
///  Helmholtz free energy with respect to reduced density for IAPWS Region 3
///
/// \param[in] del reduced density
/// \param[in] tau reduced temperature
///
/// \return partial derivative of the ideal-gas portion of dimensionless Helmholtz
///  free energy with respect to reduced pressure
///////////////////////////////////////////////////////////////////////////////
double phidel(double del, double tau)
{
	double result = N[0]/del;
	for (int i=1; i<REG3_COUNT; i++) {
		result += N[i]*I[i]*pow(del,I[i]-1)*pow(tau,J[i]);
	}
	return result;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates second order partial derivative of ideal-gas portion of the dimensionless
///  Helmholtz free energy with respect to reduced density for IAPWS Region 3
///
/// \param[in] del reduced density
/// \param[in] tau reduced temperature
///
/// \return second order partial derivative of the ideal-gas portion of dimensionless Helmholtz
///  free energy with respect to reduced pressure
///////////////////////////////////////////////////////////////////////////////
double phideldel(double del, double tau)
{
	double result = -N[0]/del/del;
	for (int i=1; i<REG3_COUNT; i++) {
		result += N[i]*I[i]*(I[i]-1)*pow(del,I[i]-2)*pow(tau,J[i]);
	}
	return result;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of ideal-gas portion of the dimensionless
///  Helmholtz free energy with respect to reduced temperature for IAPWS Region 3
///
/// \param[in] del reduced density
/// \param[in] tau reduced temperature
///
/// \return partial derivative of the ideal-gas portion of dimensionless Helmholtz
///  free energy with respect to reduced temperature
///////////////////////////////////////////////////////////////////////////////
double phitau(double del, double tau)
{
	double result = 0;
	for (int i=1; i<REG3_COUNT; i++) {
		result += N[i]*pow(del,I[i])*J[i]*pow(tau,J[i]-1);
	}
	return result;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates second order partial derivative of ideal-gas portion of the dimensionless
///  Helmholtz free energy with respect to reduced temperature for IAPWS Region 3
///
/// \param[in] del reduced density
/// \param[in] tau reduced temperature
///
/// \return second order partial derivative of the ideal-gas portion of dimensionless Helmholtz
///  free energy with respect to reduced temperature
///////////////////////////////////////////////////////////////////////////////
double phitautau(double del, double tau)
{
	double result = 0;
	for (int i=1; i<REG3_COUNT; i++) {
		result += N[i]*pow(del,I[i])*J[i]*(J[i]-1)*pow(tau,J[i]-2);
	}
	return result;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates partial derivative of ideal-gas portion of the dimensionless Helmholtz free energy
///  with respect to reduced temperature and reduced density for IAPWS Region 3
///
/// \param[in] del reduced density
/// \param[in] tau reduced temperature
///
/// \return partial derivative of ideal-gas portion of the dimensionless Helmholtz free energy with respect
///  to reduced temperature and reduced density
///////////////////////////////////////////////////////////////////////////////
double phideltau(double del, double tau)
{
	double result = 0;
	for (int i=1; i<REG3_COUNT; i++) {
		result += N[i]*I[i]*pow(del,I[i]-1)*J[i]*pow(tau,J[i]-1);
	}
	return result;
}

//-------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific enthalpy as a function of density and temperature in IAPWS Region 3
///
/// \param[in] d  density
/// \param[in] t  temperature
///
/// \return specific enthalpy
///////////////////////////////////////////////////////////////////////////////
double h_dt_3(double d,double t)
{
	double del = d / rhostar;
	double tau = tstar / t;
	return (tau*phitau(del, tau) + del*phidel(del,tau)) *R*t;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific entropy as a function of density and temperature in IAPWS Region 3
///
/// \param[in] d  density
/// \param[in] t  temperature
///
/// \return specific entropy
///////////////////////////////////////////////////////////////////////////////
double s_dt_3(double d,double t)
{
	double del = d / rhostar;
	double tau = tstar / t;
	return (tau*phitau(del, tau) - phi(del,tau)) * R;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates isobaric heat capacity as a function of density and temperature in IAPWS Region 3
///
/// \param[in] d  density
/// \param[in] t  temperature
///
/// \return isobaric heat capacity
///////////////////////////////////////////////////////////////////////////////
double cp_dt_3(double d,double t)
{
	double del = d / rhostar;
	double tau = tstar / t;
	double part = pow(del*phidel(del,tau) - del*tau*phideltau(del,tau),2);
	part = part / (2*del*phidel(del,tau) + del*del*phideldel(del,tau));
	return (-tau*tau*phitautau(del,tau) + part) * R;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates isochoric heat capacity as a function of density and temperature in IAPWS Region 3
///
/// \param[in] d  density
/// \param[in] t  temperature
///
/// \return isochoric heat capacity
///////////////////////////////////////////////////////////////////////////////
double cv_dt_3(double d,double t)
{
	double del = d / rhostar;
	double tau = tstar / t;
	return (-tau*tau*phitautau(del,tau)) * R;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates speed of sound as a function of density and temperature in IAPWS Region 3
///
/// \param[in] d  density
/// \param[in] t  temperature
///
/// \return speed of sound
///////////////////////////////////////////////////////////////////////////////
double w_dt_3(double d,double t)
{
	double del = d / rhostar;
	double tau = tstar / t;
	double part = pow(del*phidel(del,tau)- del*tau*phideltau(del,tau), 2);
	part = part / (tau*tau*phitautau(del,tau));
	part = (2*del*phidel(del,tau) + del*del*phideldel(del,tau) - part)*R*t;
	// note that 1E3 added to make the units work
	return pow(part*1E3,0.5);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates pressure as a function of density and temperature in IAPWS Region 3
///
/// \param[in] d  density
/// \param[in] t  temperature
///
/// \return pressure
///////////////////////////////////////////////////////////////////////////////
double p_dt_3(double d, double t)
{
	double del = d / rhostar;
	double tau = tstar / t;
	double p = del*phidel(del,tau) * d * R * t;
	p /= 1000;  // convert p from kPa to MPa;
	return p;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates density as a function of pressure and temperature in IAPWS Region 3
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return pressure
///////////////////////////////////////////////////////////////////////////////
double d_pt_3(double p,double t)
{
	// the objective here is to "back out" a value of d given p and t.  This
	// is necessary because the region 3 equations are all given in terms of d and t.
	double d_high = 765;  // maximum liquid density on region 1 boundary
	double d_low = 100;  // minimum vapor density on the region 2 boundary
	if (t > TC) {
		// easy calculation - no saturation conditions to deal with
		return zeroin1(p_dt_3, t, d_low, d_high, p, tolerance);
	}
	else if ((t==TC)&&(p==PC)) {
		// we are at the critical point.  return the known value.
		return DC;
	}
	else {
		// liquid, vapor, or saturation conditions.
		// see which one.
		double sat_p = PSAT_T(t);
		if (p >= sat_p) {
			// saturation conditions or liquid (dealt with identically, when on the boundary
			// give the tie to "liquid")
			// get the bounding lower limit for liquid density at this temp
			d_low = interpolate(sat_temps, liquid_density_lower_limit, SAT_TEMPS_COUNT, t);
			return zeroin1(p_dt_3, t, d_low, d_high, p, tolerance);
		}
		else {
			// vapor
			// get the bounding upper limit for vapor density at this temp
			d_high = interpolate(sat_temps, vapor_density_upper_limit, SAT_TEMPS_COUNT, t);
			return zeroin1(p_dt_3, t, d_low, d_high, p, tolerance);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates density of saturated liquid in IAPWSvRegion 3
///
/// For conditions below the critical point (i.e. where a saturation condition
/// exists) this function calculates a saturated liquid density as a function of
/// pressure and temperature in IAPWS Region 3
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return density
///////////////////////////////////////////////////////////////////////////////
double df_pt_3(double p, double t)
{
	if ((t==TC)||(p==PC)) {
		// we are at the critical point.  return the known value.
		return DC;
	}
	if (p == 0)
		p=PSAT_T(t);
	double d_high = 765;  // maximum liquid density on region 1 boundary
	double d_low = interpolate(sat_temps, liquid_density_lower_limit, SAT_TEMPS_COUNT, t);
	return zeroin1(p_dt_3, t, d_low, d_high, p, tolerance);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates density of saturated vapor in IAPWSvRegion 3
///
/// For conditions below the critical point (i.e. where a saturation condition
/// exists) this function calculates a saturated vapor as a function of
/// pressure and temperature in IAPWS Region 3
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return density
///////////////////////////////////////////////////////////////////////////////
double dv_pt_3(double p, double t)
{
	if ((t==TC)||(p==PC)) {
		// we are at the critical point.  return the known value.
		return DC;
	}
	if (p == 0)
	if (p == 0)
		p=PSAT_T(t);
	double d_low = 100;  // minimum vapor density on the region 2 boundary
	double d_high = interpolate(sat_temps, vapor_density_upper_limit, SAT_TEMPS_COUNT, t);
	return zeroin1(p_dt_3, t, d_low, d_high, p, tolerance);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific enthalpy as a function of pressure and temperature in IAPWS Region 3
///
/// \param[in] p  pressure
/// \param[in] t  temperature
///
/// \return specific enthalpy
///////////////////////////////////////////////////////////////////////////////
double h_pt_3(double p, double t)
{
	// note that this won't be continuous below the critical pressure
	double d = d_pt_3(p, t);
	return h_dt_3(d, t);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates temperature as a function of pressure and specific enthalpy in IAPWS Region 3
///
/// \param[in] p  pressure
/// \param[in] h  specific enthalpy
///
/// \return temperature
///////////////////////////////////////////////////////////////////////////////
double t_ph_3(double p, double h)
{
	if (p >= 22.064) {
		// root-find on h_pt_3 to find a value of t that will return h
		// don't need to worry about the saturation region
		double t_low = 623.15 - 1;
		double t_high = b23_t_p(p) + 1;
		return zeroin2(h_pt_3, p, t_low, t_high, h, tolerance);
	}
	// we are at a low enough pressure that saturation will occur and hence
	//     the h_pt_3 function isn't continuous
	double t_sat = TSAT_P(p);
	double d_sat_fluid = df_pt_3(p, t_sat);
	double h_sat_fluid = h_dt_3(d_sat_fluid, t_sat);
	double d_sat_vapor = dv_pt_3(p, t_sat);
	double h_sat_vapor = h_dt_3(d_sat_vapor, t_sat);
	if ((h >= h_sat_fluid) && (h <= h_sat_vapor))
		return t_sat;
	if (h < h_sat_fluid) {
		// liquid
		double t_low = 623.15 - 1;
		double t_high = t_sat + 1;
		return zeroin2(h_pt_3, p, t_low, t_high, h, tolerance);
	}
	else {
		// vapor
		double t_low = t_sat - 1;
		double t_high = b23_t_p(p) + 1;
		return zeroin2(h_pt_3, p, t_low, t_high, h, tolerance);
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates density as a function of pressure and specific enthalpy in IAPWS Region 3
///
/// \param[in] p  pressure
/// \param[in] h  specific enthalpy
///
/// \return density
///////////////////////////////////////////////////////////////////////////////
double d_ph_3(double p, double h)
{
	// call t_ph_3
	double t = t_ph_3(p, h);
	// call d_pt_3
	return d_pt_3(p, t);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief calculates specific entropy as a function of pressure and specific enthalpy in IAPWS Region 3
///
/// \param[in] p  pressure
/// \param[in] h  specific enthalpy
///
/// \return specific entropy
///////////////////////////////////////////////////////////////////////////////
double s_ph_3(double p, double h)
{
	// call t_ph_3
	double t = t_ph_3(p, h);
	// call d_pt_3
	double d = d_pt_3(p, t);
	// call s_dt_3
	return s_dt_3(d, t);
}


