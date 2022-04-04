/////////////////////////////////////////////////////////////////////////
///	\file watprop.h
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

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the WATPROP_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// WATPROP_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#define WATPROP_API	
#define LPXLOPER12 double
#define XLOPER12 double						
typedef wchar_t* LPWSTR, *PWSTR;

WATPROP_API LPWSTR _WatpropPyVersion(void);

WATPROP_API LPXLOPER12 // returns specific enthalpy as a function of pressure and temperature 
_H_PT(double p // pressure
	 , double t // temperature
	 , char * iunits // units of measure for inputs
	 , char * ounits // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns specific volume as a function of pressure and temperature 
_V_PT(double p // pressure
	 , double t // temperature
	 , char * iunits // units of measure for inputs
	 , char * ounits // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns speed of sound as a function of pressure and temperature 
_W_PT(double p // pressure
	 , double t // temperature
	 , char * iunits // units of measure for inputs
	 , char * ounits // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns liquid saturation specific enthalpy as a function of temperature 
_HF_T(double t // temperature
	 , char * iunits // units of measure for inputs
	 , char * ounits // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns vapor saturation specific enthalpy as a function of temperature 
_HG_T(double t // temperature
	 , char * iunits // units of measure for inputs
	 , char * ounits // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns saturation pressure from saturation temperature
_P_T(double t // saturation temperature
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	);
   
WATPROP_API LPXLOPER12 // returns saturation temperature from saturation pressure
_T_P(double p // saturation pressure
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns specific entropy as a function of pressure and temperature 
_S_PT(double p // pressure
	 , double t // temperature
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns isobaric heat capacity as a function of pressure and temperature 
_CP_PT(double p // pressure
	 , double t // temperature
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns viscosity as a function of pressure and temperature 
_VIS_PT(double p // pressure
	 , double t // temperature
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns thermal conductivity as a function of pressure and temperature 
_K_PT(double p // pressure
	 , double t // temperature
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns liquid saturation specific entropy as a function of temperature 
_SF_T(double t // temperature
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );


WATPROP_API LPXLOPER12 // returns vapor saturation specific entropy as a function of temperature 
_SG_T(double t // temperature
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns liquid saturation specific enthalpy as a function of pressure 
_HF_P(double p // pressure
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns vapor saturation specific enthalpy as a function of pressure 
_HG_P(double p // pressure
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns liquid saturation specific volume as a function of pressure 
_VF_P(double p // pressure
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns vapor saturation specific volume as a function of pressure 
_VG_P(double p // pressure
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns liquid saturation specific entropy as a function of pressure 
_SF_P(double p // pressure
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns vapor saturation specific entropy as a function of pressure 
_SG_P(double p // pressure
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns temperature as a function of pressure and specific enthalpy 
_T_PH(double p // pressure
	 , double h // enthalpy
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns specific volume as a function of pressure and specific enthalpy 
_V_PH(double p // pressure
	 , double h // enthalpy
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );

WATPROP_API LPXLOPER12 // returns specific entropy as a function of pressure and specific enthalpy 
_S_PH(double p // pressure
	 , double h // enthalpy
	, char * iunits  // units of measure for inputs
	, char * ounits  // units of measure for output
	  );
