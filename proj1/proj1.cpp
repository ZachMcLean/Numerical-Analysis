// Zach McLean
// Numerical Analysis
// 4/7/2022
// Project 1
// Show loss of significance difference between floating point(single precision) and double values(float precision)
// Including the use of Horners Algorithm to evaluate the Taylor Polynomial of e^x - 1 / x
// input x = 1, 10, 10^2, 10^3, ...., 10^9
// output the values of F(x) and G(x) as the value of x increases in value

#include <iostream>
#include <cmath>
#include <stdio.h> //for printf
#include <math.h> // cos(x) pow

// define four seperate functions for f(x) and g(x) using single and double precision
//
// single precision: 32 bit floating point values
// double precision: 64 bit double values
//
// Show how a loss of significance can occur when values of x get close to zero
//

// c prefix indicates cos function
float cffx(float x);
float cfgx(float x);
double cdfx(double x);
double cdgx(double x);

// e prefix indicates exp function
float effx(float x);
float efgx(float poly[], int n, float h);
double edfx(double x);
double edgx(double poly[], int n, double h);

/* void horner(double poly[], int n, double h); */

int main() {
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"                      Single Precision                       \n";
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"         x                F(x)                     G(x)      "<<std::endl;
	
	float s = 0.1;
	for(int i=0; i <= 9; i++) {
		printf("%0.10f      %.16f       %.16f \n", s, cffx(s), cfgx(s));
		s = s / 10.0;
	}
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"                      Double Precision                       \n";
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"         x                F(x)                     G(x)      "<<std::endl;

	double d = 0.1;
	for(int i=0; i <= 9; i++) {
		printf("%0.10f      %.16f       %.16f \n", d, cdfx(d), cdgx(d));
		d = d / 10.0;
	}
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"                      Single Precision                       \n";
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"         x                F(x)                     G(x)      "<<std::endl;
	
	float fpoly[6];
	fpoly[0] = 1.0;
	fpoly[1] = (1.0 / 2.0);
	fpoly[2] = (1.0 / 6.0);
	fpoly[3] = (1.0 / 24.0);
	fpoly[4] = (1.0 / 120.0);
	fpoly[5] = (1.0 / 720.0);

	int degf = sizeof(fpoly)/sizeof(fpoly[0]);

	s = 0.1;
	for(int i=0; i <= 15; i++) {
		printf("%0.16f     %.16f       %.16f \n", s, effx(s), efgx(fpoly, degf, s));
		s = s / 10.0;
	}
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"                      Double Precision                       \n";
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"         x                F(x)                     G(x)      "<<std::endl;

	double dpoly[6];
	dpoly[0] = 1.0;
	dpoly[1] = (1.0 / 2.0);
	dpoly[2] = (1.0 / 6.0);
	dpoly[3] = (1.0 / 24.0);
	dpoly[4] = (1.0 / 120.0);
	dpoly[5] = (1.0 / 720.0);

	int degd = sizeof(dpoly)/sizeof(dpoly[0]);

	d = 0.1;
	for(int i=0; i <= 15; i++) {
		printf("%0.16f     %.16f       %.16f \n", d, edfx(d), edgx(dpoly, degd, d));
		d = d / 10.0;
	}
	return 0;
}

// Functions for Cos function
//
// single precision for f(x)
float cffx(float x) // f(x) for single precision
{
	float val;
	val = (1-cos(x));
	val /= pow(x, 2);
	return val;
}
// single precision for g(x)
float cfgx(float x) // g(x) for single precision
{
	float val;
	val = pow(sin(x), 2);
	val /= (pow(x, 2)*(1+cos(x)));
	return val;
}

// single precision for f(x)
double cdfx(double x) // g(x) for double precision
{
	double val;
	val = (1-cos(x)) / pow(x, 2);
	return val;
}

// double precision for g(x)
double cdgx(double x) // g(x) for double precision
{
	double val;
	val = pow(sin(x), 2) / (pow(x, 2)*(1+cos(x)));
	return val;
}

// Functions for exponential function 
//
// single precision for f(x)
float effx(float x) // f(x) for single precision
{
	float val;
	val = ((exp (x)- 1) / x);
	return val;
}
// single precision for g(x)
float efgx(float poly[], int n, float h) // g(x) for single precision
{
	float approx;
    // Evaluate approximate value of polynomial using Horner's method
    for (int i=0; i<n-1; i++){
		if(i==0){
			approx = poly[0];
		}else{
			approx = approx + poly[i] * pow(h, i);
		}
	}
	return approx;
}

// single precision for f(x)
double edfx(double x) // g(x) for double precision
{
	double val;
	val = ((exp (x)- 1) / x);
	return val;
}

// double precision for g(x)
double edgx(double poly[], int n, double h) // g(x) for double precision
{
	double approx;
    // Evaluate approximate value of polynomial using Horner's method
    for (int i=0; i<n-1; i++){
		/* if(i==0){ */
		/* 	approx = poly[0]; */
		/* }else{ */
			approx = approx + poly[i] * pow(h, i);
		/* } */
	}
	return approx;
}

