/////////////////////////////////////////////////////////////////////////
///	\file utilities.h
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

#include<cctype>
#include<string>

//////////////////////////////////////////////////////
/// flag for SI units
//////////////////////////////////////////////////////
//#define SI 0
//////////////////////////////////////////////////////
/// flag for ENGLISH units
//////////////////////////////////////////////////////
//#define ENGLISH 1

double interpolate(const double x[], const double y[], int size, double given);
double zeroin1(double (*f)(double, double), double dummy, double ax, double bx, double target, double tol);	
double zeroin2(double (*f)(double, double), double dummy, double ax, double bx, double target, double tol);	

//int check_input_units(std::string units);
//int check_output_units(std::string units);

double convert_pressure_si_to_english(double pressure);
double convert_pressure_english_to_si(double pressure);

double convert_temp_kelvin_to_english(double temperature);
double convert_temp_english_to_kelvin(double temperature);

double convert_temp_kelvin_to_centigrade(double temperature);
double convert_temp_centigrade_to_kelvin(double temperature);

double convert_enthalpy_si_to_english(double enthalpy);
double convert_enthalpy_english_to_si(double enthalpy);

double convert_entropy_si_to_english(double entropy);
double convert_entropy_english_to_si(double entropy);

double convert_spvolume_si_to_english(double spvolume);
double convert_spvolume_english_to_si(double spvolume);

double convert_density_si_to_english(double density);
double convert_density_english_to_si(double density);

double convert_cp_si_to_english(double cp);
double convert_cp_english_to_si(double cp);

double convert_w_si_to_english(double w);
double convert_w_english_to_si(double w);

double convert_vis_si_to_english(double vis);
double convert_vis_english_to_si(double vis);

double convert_k_si_to_english(double k);
double convert_k_english_to_si(double k);
