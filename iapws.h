/////////////////////////////////////////////////////////////////////////
///	\file iapws.h
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

/////////////////////////////////////////////////////////////////////////
/// specific gas constant in kJ/kg/K
/////////////////////////////////////////////////////////////////////////
const double R = 0.461526;
// critical point values
/////////////////////////////////////////////////////////////////////////
/// critical point temperature in degK
/////////////////////////////////////////////////////////////////////////
const double TC = 647.096;
/////////////////////////////////////////////////////////////////////////
/// critical point pressure in MPa
/////////////////////////////////////////////////////////////////////////
const double PC = 22.064;
/////////////////////////////////////////////////////////////////////////
/// critical point density in kg/m3
/////////////////////////////////////////////////////////////////////////
const double DC = 322;
/////////////////////////////////////////////////////////////////////////
/// triple point temperature in degK
/////////////////////////////////////////////////////////////////////////
const double TT = 273.15;
/////////////////////////////////////////////////////////////////////////
/// triple point pressure in MPa
/////////////////////////////////////////////////////////////////////////
const double PT = 611.213E-6;

double b23_p_t(double t);
double b23_t_p(double p);
double PSAT_T(double t);
double TSAT_P(double p);
void check_saturated_p(double pressure);
void check_saturated_t(double temperature);
int region_pt(double pressure, double temperature);
int region_ph(double pressure, double enthalpy);

double v_pt_1(double p,double t);
double s_pt_1(double p,double t);
double cp_pt_1(double p,double t);
double cv_pt_1(double p,double t);
double w_pt_1(double p,double t);
double h_pt_1(double p,double t);

double v_pt_2(double p,double t);
double s_pt_2(double p,double t);
double cp_pt_2(double p,double t);
double cv_pt_2(double p,double t);
double w_pt_2(double p,double t);
double h_pt_2(double p,double t);

double v_pt_5(double p,double t);
double s_pt_5(double p,double t);
double cp_pt_5(double p,double t);
double w_pt_5(double p,double t);
double h_pt_5(double p,double t);

double d_pt_3(double p,double t);
double s_dt_3(double d,double t);
double cp_dt_3(double d,double t);
double cv_dt_3(double d,double t);
double w_dt_3(double d,double t);
double h_dt_3(double d,double t);
double p_dt_3(double d, double t);

double df_pt_3(double p, double t);
double dv_pt_3(double p, double t);

double v_ph_1(double p, double h);
double v_ph_2(double p, double h);
double d_ph_3(double p, double h);
double v_ph_4(double p, double h);
double v_ph_5(double p, double h);

double t_ph_1(double p, double h);
double t_ph_2(double p, double h);
double t_ph_3(double p, double h);
double t_ph_5(double p, double h);

double s_ph_1(double p, double h);
double s_ph_2(double p, double h);
double s_ph_3(double p, double h);
double s_ph_4(double p, double h);
double s_ph_5(double p, double h);

