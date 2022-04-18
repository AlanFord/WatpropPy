/////////////////////////////////////////////////////////////////////////
///	\file wat.h
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

#define WATPROP_API	
#define LPXLOPER12 double
#define XLOPER12 double						
//typedef char* LPWSTR, *PWSTR;

enum Units {SI, ENGLISH};

WATPROP_API const char * _WatpropPyVersion(void);

/////////////////////////////////////////////////////////////////////////

WATPROP_API LPXLOPER12 // returns isobaric heat capacity as a function of pressure and temperature 
CP_PT(double p // pressure
	 , double t // temperature
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns specific enthalpy as a function of pressure and temperature 
H_PT(double p // pressure
	 , double t // temperature
	 , Units iunits // units of measure for inputs
	 , Units ounits // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns thermal conductivity as a function of pressure and temperature 
K_PT(double p // pressure
	 , double t // temperature
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns specific entropy as a function of pressure and temperature 
S_PT(double p // pressure
	 , double t // temperature
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns specific volume as a function of pressure and temperature 
V_PT(double p // pressure
	 , double t // temperature
	 , Units iunits // units of measure for inputs
	 , Units ounits // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns viscosity as a function of pressure and temperature 
VIS_PT(double p // pressure
	 , double t // temperature
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns speed of sound as a function of pressure and temperature 
W_PT(double p // pressure
	 , double t // temperature
	 , Units iunits // units of measure for inputs
	 , Units ounits // units of measure for output
	  );

/////////////////////////////////////////////////////////////////////////

WATPROP_API LPXLOPER12 // returns saturation pressure from saturation temperature
P_T(double t // saturation temperature
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	);

WATPROP_API LPXLOPER12 // returns liquid saturation specific enthalpy as a function of temperature 
HF_T(double t // temperature
	 , Units iunits // units of measure for inputs
	 , Units ounits // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns vapor saturation specific enthalpy as a function of temperature 
HG_T(double t // temperature
	 , Units iunits // units of measure for inputs
	 , Units ounits // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns liquid saturation specific entropy as a function of temperature 
SF_T(double t // temperature
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );


WATPROP_API LPXLOPER12 // returns vapor saturation specific entropy as a function of temperature 
SG_T(double t // temperature
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns liquid saturation specific volume as a function of temperature 
VF_T(double t // temperature
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );


WATPROP_API LPXLOPER12 // returns vapor saturation specific volume as a function of temperature 
VG_T(double t // temperature
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

/////////////////////////////////////////////////////////////////////////
   
WATPROP_API LPXLOPER12 // returns saturation temperature from saturation pressure
T_P(double p // saturation pressure
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns liquid saturation specific enthalpy as a function of pressure 
HF_P(double p // pressure
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns vapor saturation specific enthalpy as a function of pressure 
HG_P(double p // pressure
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns liquid saturation specific entropy as a function of pressure 
SF_P(double p // pressure
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns vapor saturation specific entropy as a function of pressure 
SG_P(double p // pressure
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns liquid saturation specific volume as a function of pressure 
VF_P(double p // pressure
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns vapor saturation specific volume as a function of pressure 
VG_P(double p // pressure
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

/////////////////////////////////////////////////////////////////////////
   

WATPROP_API LPXLOPER12 // returns temperature as a function of pressure and specific enthalpy 
T_PH(double p // pressure
	 , double h // enthalpy
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns specific entropy as a function of pressure and specific enthalpy 
S_PH(double p // pressure
	 , double h // enthalpy
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns specific volume as a function of pressure and specific enthalpy 
V_PH(double p // pressure
	 , double h // enthalpy
	, Units iunits  // units of measure for inputs
	, Units ounits  // units of measure for output
	  );
