/////////////////////////////////////////////////////////////////////////
///	\file mymath.cpp
///	\brief interpolation and root-finding functions for WATPROP
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

#include <cmath>
#include "utilities.h"
/////////////////////////////////////////////////////////////////////////
/// if not already defined, this represents the difference between 1.0
/// and the next value that is representable by double precision floating point
/////////////////////////////////////////////////////////////////////////
#ifndef DBL_EPSILON
	#define DBL_EPSILON 2e-16
#endif


///////////////////////////////////////////////////////////////////////////////
/// \brief interpolates within an array of increasing values
///
/// this routine assumes that the x[] array hase values in order of increasing size.
///
/// extrapolation will occur if values are not bounded by x[]
///
/// \param[in] x array of independent values
/// \param[in] y array of dependent values
/// \param[in] size length of the arrays
/// \param[in] given value used for interpolation
///
/// \return value interpolated from y array
///////////////////////////////////////////////////////////////////////////////
double interpolate(const double x[], const double y[], int size, double given)
{
	for (int i=1; i<size-1; i++) {
		if (given <=x[i]) {
			return (given-x[i-1])/(x[i]-x[i-1])*(y[i]-y[i-1]) + y[i-1];
		}
	}
	int i=size-1;
	return (given-x[i-1])/(x[i]-x[i-1])*(y[i]-y[i-1]) + y[i-1];
}


///////////////////////////////////////////////////////////////////////////////
/// \brief finds root of [f(x,a) - target] using Brent's method
///
/// This is a modified version of "zeroin" from NETLIB.  While the original zeroin
/// was designed for to search for a root of a function with only one argument,
/// this routine permits the search for a root of a function that has two arguments.
///
/// Algorithm
///	G.Forsythe, M.Malcolm, C.Moler, Computer methods for mathematical
///	computations. M., Mir, 1980, p.180 of the Russian edition
///
///	The function makes use of the bissection procedure combined with
///	the linear or quadric inverse interpolation.
///	At every step program operates on three abscissae - a, b, and c.
///	b - the last and the best approximation to the root
///	a - the last but one approximation
///	c - the last but one or even earlier approximation than a that
///		1) |f(b)| <= |f(c)|
///		2) f(b) and f(c) have opposite signs, i.e. b and c confine
///		   the root
///	At every step zeroin1 selects one of the two new approximations, the
///	former being obtained by the bissection procedure and the latter
///	resulting in the interpolation (if a,b, and c are all different
///	the quadric interpolation is utilized, otherwise the linear one).
///	If the latter (i.e. obtained by the interpolation) point is
///	reasonable (i.e. lies within the current interval [b,c] not being
/// too close to the boundaries) it is accepted. The bissection result
///	is used in the other case. Therefore, the range of uncertainty is
///	ensured to be reduced at least by the factor 1.6
///
/// \param[in] *f function under investigation
/// \param[in] dummy fixed value of second argument to function under investigation
/// \param[in] ax lower end of range for function first argument that must contain the root
/// \param[in] bx upper end of the range for function first argument that must contain the root
/// \param[in] target value of f(x,a) corresponding to the desired root
/// \param[in] tol acceptable tolerance
///
/// \return value an estimate for the root with accuracy 4*EPSILON*abs(x) + tol
///////////////////////////////////////////////////////////////////////////////
double zeroin1(double (*f)(double, double), double dummy, double ax, double bx, double target, double tol)
{
  double a,b,c;				/* Abscissae, descr. see above	*/
  double fa;				/* f(a)				*/
  double fb;				/* f(b)				*/
  double fc;				/* f(c)				*/

  a = ax;  b = bx;  fa = (*f)(a,dummy)-target;  fb = (*f)(b,dummy)-target;
  c = a;   fc = fa;

  // verify that we are bracketed
  if (fa*fb > 0)
	  throw "error in brent root routine";

  for(;;)		/* Main iteration loop	*/
  {
    double prev_step = b-a;		/* Distance from the last but one*/
					/* to the last approximation	*/
    double tol_act;			/* Actual tolerance		*/
    double p;      			/* Interpolation step is calcu- */
    double q;      			/* lated in the form p/q; divi- */
  					/* sion operations is delayed   */
 					/* until the last moment	*/
    double new_step;      		/* Step at this iteration       */
   
    if( fabs(fc) < fabs(fb) )
    {                         		/* Swap data for b to be the 	*/
	a = b;  b = c;  c = a;          /* best approximation		*/
	fa=fb;  fb=fc;  fc=fa;
    }
    tol_act = 2*DBL_EPSILON*fabs(b) + tol/2;
    new_step = (c-b)/2;

    if( fabs(new_step) <= tol_act || fb == (double)0 )
      return b;				/* Acceptable approx. is found	*/

    			/* Decide if the interpolation can be tried	*/
    if( fabs(prev_step) >= tol_act	/* If prev_step was large enough*/
	&& fabs(fa) > fabs(fb) )	/* and was in true direction,	*/
    {					/* Interpolatiom may be tried	*/
	register double t1,cb,t2;
	cb = c-b;
	if( a==c )			/* If we have only two distinct	*/
	{				/* points linear interpolation 	*/
	  t1 = fb/fa;			/* can only be applied		*/
	  p = cb*t1;
	  q = 1.0 - t1;
 	}
	else				/* Quadric inverse interpolation*/
	{
	  q = fa/fc;  t1 = fb/fc;  t2 = fb/fa;
	  p = t2 * ( cb*q*(q-t1) - (b-a)*(t1-1.0) );
	  q = (q-1.0) * (t1-1.0) * (t2-1.0);
	}
	if( p>(double)0 )		/* p was calculated with the op-*/
	  q = -q;			/* posite sign; make p positive	*/
	else				/* and assign possible minus to	*/
	  p = -p;			/* q				*/

	if( p < (0.75*cb*q-fabs(tol_act*q)/2)	/* If b+p/q falls in [b,c]*/
	    && p < fabs(prev_step*q/2) )	/* and isn't too large	*/
	  new_step = p/q;			/* it is accepted	*/
					/* If p/q is too large then the	*/
					/* bissection procedure can 	*/
					/* reduce [b,c] range to more	*/
					/* extent			*/
    }

    if( fabs(new_step) < tol_act )	/* Adjust the step to be not less*/
      if( new_step > (double)0 )	/* than tolerance		*/
	new_step = tol_act;
      else
	new_step = -tol_act;

    a = b;  fa = fb;			/* Save the previous approx.	*/
    b += new_step;  fb = (*f)(b,dummy)-target;	/* Do step to a new approxim.	*/
    if( (fb > 0 && fc > 0) || (fb < 0 && fc < 0) )
    {                 			/* Adjust c for it to have a sign*/
      c = a;  fc = fa;                  /* opposite to that of b	*/
    }
  }

}


///////////////////////////////////////////////////////////////////////////////
/// \brief finds root of [f(a,x) - target] using Brent's method
///
/// This is a modified version of "zeroin" from NETLIB.  While the original zeroin
/// was designed for to search for a root of a function with only one argument,
/// this routine permits the search for a root of a function that has two arguments.
///
/// Algorithm
///	G.Forsythe, M.Malcolm, C.Moler, Computer methods for mathematical
///	computations. M., Mir, 1980, p.180 of the Russian edition
///
///	The function makes use of the bissection procedure combined with
///	the linear or quadric inverse interpolation.
///	At every step program operates on three abscissae - a, b, and c.
///	b - the last and the best approximation to the root
///	a - the last but one approximation
///	c - the last but one or even earlier approximation than a that
///		1) |f(b)| <= |f(c)|
///		2) f(b) and f(c) have opposite signs, i.e. b and c confine
///		   the root
///	At every step zeroin2 selects one of the two new approximations, the
///	former being obtained by the bissection procedure and the latter
///	resulting in the interpolation (if a,b, and c are all different
///	the quadric interpolation is utilized, otherwise the linear one).
///	If the latter (i.e. obtained by the interpolation) point is
///	reasonable (i.e. lies within the current interval [b,c] not being
/// too close to the boundaries) it is accepted. The bissection result
///	is used in the other case. Therefore, the range of uncertainty is
///	ensured to be reduced at least by the factor 1.6
///
/// \param[in] *f function under investigation
/// \param[in] dummy fixed value of first argument to function under investigation
/// \param[in] ax lower end of range for function second argument that must contain the root
/// \param[in] bx upper end of the range for function second argument that must contain the root
/// \param[in] target value of f(a,x) corresponding to the desired root
/// \param[in] tol acceptable tolerance
///
/// \return value an estimate for the root with accuracy 4*EPSILON*abs(x) + tol
///////////////////////////////////////////////////////////////////////////////
double zeroin2(double (*f)(double, double), double dummy, double ax, double bx, double target, double tol)
{
  double a,b,c;				/* Abscissae, descr. see above	*/
  double fa;				/* f(a)				*/
  double fb;				/* f(b)				*/
  double fc;				/* f(c)				*/

  a = ax;  b = bx;  fa = (*f)(dummy,a)-target;  fb = (*f)(dummy,b)-target;
  c = a;   fc = fa;

  // verify that we are bracketed
  if (fa*fb > 0)
	  throw "error in brent root routine";

  for(;;)		/* Main iteration loop	*/
  {
    double prev_step = b-a;		/* Distance from the last but one*/
					/* to the last approximation	*/
    double tol_act;			/* Actual tolerance		*/
    double p;      			/* Interpolation step is calcu- */
    double q;      			/* lated in the form p/q; divi- */
  					/* sion operations is delayed   */
 					/* until the last moment	*/
    double new_step;      		/* Step at this iteration       */
   
    if( fabs(fc) < fabs(fb) )
    {                         		/* Swap data for b to be the 	*/
	a = b;  b = c;  c = a;          /* best approximation		*/
	fa=fb;  fb=fc;  fc=fa;
    }
    tol_act = 2*DBL_EPSILON*fabs(b) + tol/2;
    new_step = (c-b)/2;

    if( fabs(new_step) <= tol_act || fb == (double)0 )
      return b;				/* Acceptable approx. is found	*/

    			/* Decide if the interpolation can be tried	*/
    if( fabs(prev_step) >= tol_act	/* If prev_step was large enough*/
	&& fabs(fa) > fabs(fb) )	/* and was in true direction,	*/
    {					/* Interpolatiom may be tried	*/
	register double t1,cb,t2;
	cb = c-b;
	if( a==c )			/* If we have only two distinct	*/
	{				/* points linear interpolation 	*/
	  t1 = fb/fa;			/* can only be applied		*/
	  p = cb*t1;
	  q = 1.0 - t1;
 	}
	else				/* Quadric inverse interpolation*/
	{
	  q = fa/fc;  t1 = fb/fc;  t2 = fb/fa;
	  p = t2 * ( cb*q*(q-t1) - (b-a)*(t1-1.0) );
	  q = (q-1.0) * (t1-1.0) * (t2-1.0);
	}
	if( p>(double)0 )		/* p was calculated with the op-*/
	  q = -q;			/* posite sign; make p positive	*/
	else				/* and assign possible minus to	*/
	  p = -p;			/* q				*/

	if( p < (0.75*cb*q-fabs(tol_act*q)/2)	/* If b+p/q falls in [b,c]*/
	    && p < fabs(prev_step*q/2) )	/* and isn't too large	*/
	  new_step = p/q;			/* it is accepted	*/
					/* If p/q is too large then the	*/
					/* bissection procedure can 	*/
					/* reduce [b,c] range to more	*/
					/* extent			*/
    }

    if( fabs(new_step) < tol_act )	/* Adjust the step to be not less*/
      if( new_step > (double)0 )	/* than tolerance		*/
	new_step = tol_act;
      else
	new_step = -tol_act;

    a = b;  fa = fb;			/* Save the previous approx.	*/
    b += new_step;  fb = (*f)(dummy,b)-target;	/* Do step to a new approxim.	*/
    if( (fb > 0 && fc > 0) || (fb < 0 && fc < 0) )
    {                 			/* Adjust c for it to have a sign*/
      c = a;  fc = fa;                  /* opposite to that of b	*/
    }
  }

}
