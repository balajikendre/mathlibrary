#include <stdio.h>
#include "math.h"
#define PI 3.14159265
#define E 2.3025850929940

/*This function returns absolute value of the given number */
double fabs(double x) {
	if (x >= 0.00)
		return x;
	else 
		return (-x);
}

/* This function returns largest integral value less than x. */
double floor(double x) {
	int y = (int) x;
	if(x >= 0) {
		return (double)(y);
	}	
	if((x < 0) && (y > x)) {
		return (double)(--y);
	}
	else if((x < 0) && (x = y)) {
		return (double)(y);
	}
}

/* This function returns smallest integral value that exceeds x. */
double ceil(double x) {
	int y = (int) x;
	if((x >= 0) && (y < x))
		return (double)(++y);
	else if((x >= 0) && (y == x))
		return (double)(y);
	if(x < 0)
		return (double)(y);
}

/* this fuction returns rounding of value of given double value. */
int roundn(double x) {
	if(x < 0.0)
		return (x - 0.5);
	else
		return (x + 0.5);
}

/*This function returns the squareroot of given positive number */
double sqrt(double x) {
	if (x < 0.00000000) {
		printf("input is invalid");
		return -1;
	}
	double low, high = x, b;
	double m;
	int i;
	low = 0.0000;
	m = (low + high) / 2;
	for (i = 0; i <= 128; i++) {
		b = m * m;
		if(b == x) {
	        	return m;
	           	break;
	        } 
		else {
	        	if(m * m > x) {
	        		high = m;
	                	m = (low + high) / 2;
	           	} 
			else {
               			low = m;
               			m = (low + high) / 2;
            		}
         	}
      	}
	return m;
}

/* This function returns the value of x raised to the power of y */
double pow(double x, double y) {
	int sign, i;
	double prod = 1;
	if(y == 0) { 	
		if(x == 0) {
			printf("Bad input \n");
			return -1;
		}
	}
	if(y < 0) {
		sign = -1;
		y = -y;
	}
	for(i=0; i<y; i++) {
		prod = prod * x;
	}
	if(sign == -1)
		prod = 1.0/prod;
	return prod;
}

/* This function returns the factorial of the given number */
long int fact(unsigned int x) {
	long int i = 1;
	long int f = 1;
	if (x == 0)
		return f;
	else {
		for(i = 1; i <= x; i++) {
			f = f * i;
		}
	}
	return f;
}

/* This function returns the exponential value of number */
double exp(double x) {
	double ex = 1;
	double term = 1;
	int n = 1;
	while (!(term >= -0.001 && term <= 0.001)) {
		term = (term * x) / n;
		ex += term;
		n++;
	}	
	return ex;
}

/* This function returns the natural logarithm of x  */
double log(double x) {
	if (x <= 0.00000000) {
		printf("input is invalid ");
		return -1;
	}
	double y;
	y = (x - 1)/(x + 1);
	double sum;
	sum = 0.0000;
	double denominator = 1.0;
	double numerator = y;
	double term = numerator / denominator;
	while(term > 0.00000000000001) {
		sum += term;
		denominator += 2.0;
		numerator = numerator * y * y;
		term = numerator / denominator;
	}
	return (2.0 * sum);
}

/* This fuction returns the logarithmic value of x to the base 10 */
double log10(double x) {
	if (x <= 0.00000000) {
		printf("input is invalid ");
		return -1; 
	}
	else {
		double l;
		l = log(x);
		return (l / E);
	}
}

/* This function returns sine of the angle in radians */
double sin(double x) {
	int n = 1;
	double sin = x, term = x;
	while (!(term >= -0.0000000001 && term <= 0.000000001)) {
		term = (-term) * (x * x) / ((2 * n + 1) * (2 * n));
		sin += term;	
		n++;
	}
	return sin;
}

/* This function returns cosine of the angle in radians */
double cos(double x) {
	int n = 1;
	double cos = 1, term = 1;
	while (!(term >= -0.0000000001 && term <= 0.000000001)) {
		term = (-term) * (x * x) / ((2 * n - 1) * (2 * n));
		cos += term;	
		n++;
	}
	return cos;
}

/* This function returns tan of the angle in radians */
double tan(double x) {
	double tan;
	if(cos(x) == 0) {
		printf("tan value is infnite ");
		return -1;
	}
	tan = sin(x) / cos(x);
	return tan;
}

/* This function returns hyperbolic sine of x */
double sinh(double x) {
	int n = 1;
	double sinh = x, term = x;
	while (!(term >= -0.0000000001 && term <= 0.000000001)) {
		term = (term) * (x * x) / ((2 * n + 1) * (2 * n));
		sinh += term;	
		n++;
	}
	return sinh;
}

/* This function returns hyperbolic cos of x */
double cosh(double x) {
	int n = 1;
	double cosh = 1, term = 1;
	while (!(term >= -1.0000000001 && term <= 1.000000001)) {
		term = (term) * (x * x) / ((2 * n - 1) * (2 * n));
		cosh += term;	
		n++;
	}
	return cosh;
}

/* This function returns hyperbolic tan of x */
double tanh(double x) {
	double tanh;
	tanh =	sinh(x) / cosh(x);
	return tanh;
}

/* This function returns the arc sin of x 
double asin(double x) {
	double asin = x;
	double term = x;
	int n = 1;
	while (!(term >= -0.0000001 && term <= 0.0000001)) {
		term = ((term) * (x * x) * (2 * n - 1) * (2 * n - 1)) / ((2 * n + 1) * (2 * n));
		asin += term;	
		n++;
	}
	return asin;
}

This function returns the arc cos of x 
double acos(double x) {
	
	double acos;
	acos = (PI / 2) - asin(x);
	return acos;
}

This function returns the arc tan of x 
double atan(double x) {
	double atan = x;
	int n = 1;
	double term = x;
	while (!(term >= -0.001 && term <= 0.001)) {
		term = (-term) * (x * x) * (2 * n - 1) / (2 * n + 1);
		atan += t;	
		n++;
	} 
	return atan;
}
*/





