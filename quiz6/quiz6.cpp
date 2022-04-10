// Zach McLean
// Numerical Analysis
// 4/6/2022
// Quiz 6 
// Show loss of significance difference between floating point(single precision) and double values(float precision)
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
// Show how a loss of significance can occur when values of x are to big

float ffx(float x);
float fgx(float x);
double dfx(double x);
double dgx(double x);

int main() {
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"                      Single Precision                       \n";
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"         x                F(x)                     G(x)      "<<std::endl;
	
	float s = 1;
	for(int i=0; i <= 9; i++) {
		printf("%10.0f  %24.16f  %24.16f \n", s, ffx(s), fgx(s));
		s *= 10;
	}
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"                      Double Precision                       \n";
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"         x                F(x)                     G(x)      "<<std::endl;

	double d = 1;
	for(int i=0; i <= 9; i++) {
		printf("%10.0f  %24.16f  %24.16f \n", d, dfx(d), dgx(d));
		d *= 10;
	}
	return 0;
}

// single precision for f(x)
float ffx(float x) // f(x) for single precision
{
	float val;
	val = x*(sqrt(x+1)-sqrt(x));
	return val;
}
// single precision for g(x)
float fgx(float x) // g(x) for single precision
{
	float val;
	val = (x/(sqrt(x+1)+sqrt(x)));
	return val;
}

// single precision for f(x)
double dfx(double x) // g(x) for single precision
{
	double val;
	val = x*(sqrt(x+1)-sqrt(x));
	return val;
}

// double precision for g(x)
double dgx(double x) // g(x) for single precision
{
	double val;
	val = (x/(sqrt(x+1)+sqrt(x)));
	return val;
}
