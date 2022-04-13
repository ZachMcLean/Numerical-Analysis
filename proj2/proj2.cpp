// Zach McLean
// Numerical Analysis
// 4/11/2022
// Project 2
// Approximate the roor of the function using Bisection, Newton's, and Secant Method
// Including the use of Horners Algorithm to evaluate the Taylor Polynomial of e^x - 1 / x



#include <iostream>
#include <cmath>
#include <stdio.h> //for printf
#include <math.h> // cos(x) pow

// define two seperate functions for evaluating Horner's Algorithm of f(x) & f'(x)
//		& 3 functions for evaluating Bisection, Newton's, and Secant Method
//
// Initial Function is x^3 - 2x^2 - 5x + 6
// f'(x) = 3x^2 - 4x - 5

// c prefix indicates cos function
double horners(double poly[], int n, double h);
void bisection(double a, double b, double xTolerance, double yTolerance, double polyf[], int degf);
void newtons(double x0, double xTolerance, double yTolerance, double polyf[], double polyd[], int degf, int degd);
void secant(double x0, double x1, double xTolerance, double yTolerance, double polyf[], int degf);

const int maxIterations = 20;

int main() {
	// Temporary hard coded value for initial guess
	double x = 0.0;
	double y = 4.0;
	// function
	double polyf[4];
	polyf[0] = 1.0;
	polyf[1] = -2.0;
	polyf[2] = -5.0;
	polyf[3] = 6.0;


	// derivative
	double polyd[3];
	polyd[0] = 3.0;
	polyd[1] = -4.0;
	polyd[2] = -5.0;

	int degf = sizeof(polyf)/sizeof(polyf[0]); // calculate degree of p(x)
	int degd = sizeof(polyd)/sizeof(polyd[0]); // calculate degree of p'(x)

	double xTolerance = 0.001;
	double yTolerance = 0.00001;

	std::cout <<"================================================================"<<std::endl;
	printf("Interval: [%.6f, %.6f]\n", x, y);
	
	/* std::cout <<"================"<<std::endl; */
	/* std::cout <<"Bisection Method: \n"; */
	/* bisection(x, y, xTolerance, yTolerance, polyf, degf); */
	std::cout <<"================"<<std::endl;
	std::cout <<"Newton's Method: \n";
	newtons(x, xTolerance, yTolerance, polyf, polyd, degf, degd);
	/* std::cout <<"================"<<std::endl; */
	/* std::cout <<"Secant's Method: \n"; */
	/* secant(x, y, xTolerance, yTolerance, polyf, degf); */

	return 0;
}

// calculate the horners algorithm for the values in the polynomial array
double horners(double poly[], int n, double h) // g(x) for single precision
{
	double approx;
    // Evaluate approximate value of polynomial using Horner's method
    for (int i=0; i<=n-1; i++){
		if(i==0){
			approx = poly[0];
		}else{
			approx = approx * pow(h, n-i) + poly[i] ;
		}
		std::cout<<"approx: "<<approx<<std::endl;
	}
	return approx;
}

// Psuedocode:
//	[a, b] = first two guesses; c = root = (a*b)/2
//	Bisection Method:
//	while (f(c)<0)
//		if f(a)xf(b)<0
//			if f(c)==0
//				stop
//			if f(a)xf(c)<0, there is a root inbetween [a, c]
//				b == c
//			else if f(c)xf(b)<0, there is a root in between [c, b]
//				a == c
//
void bisection(double a, double b, double xTolerance, double yTolerance, double polyf[], int degf){
	int i = 0;
	while(i <= maxIterations && xTolerance >= 0.001 && yTolerance >= 0.00001){
		double c = (a*b) / 2; // calculate the midpoint of our two guesses
		/* int degf = sizeof(*polyf)/sizeof(polyf[0]); // calculate degree of p(x) */

		double fa = horners(polyf, degf, a); // calculate f(a)
		double fb = horners(polyf, degf, b); // calculate f(b)
		double fc = horners(polyf, degf, c); // calculate f(b)
		if((fa*fb) < 0){
			if(fc == 0){
				printf("%d       %.6f       %.6f       %.6f       \n",i, c, xTolerance, yTolerance);
				i = maxIterations;
			}else if(fa*fc < 0){
				b = c;

			}else if(fc*fb < 0){
				a = c;
			}
		}
		/* printf("%d       %.6f       %.6f       %.6f       \n",i, c, xTolerance, yTolerance); */
		
		std::cout <<"================================================================"<<std::endl;
		std::cout <<"Iteration    Approx. root    x_tolerance    y_tolerance    "<<std::endl;
		xTolerance = b-c; 
		yTolerance = abs(fa);
		i++;

	}
	if(i == maxIterations){
		std::cout<<"found no root on the interval\n";
	}
	else{
	std::cout <<"Number of iterations: " << i <<std::endl;
	std::cout <<"x_tolerance: " << xTolerance <<std::endl;
	std::cout <<"y_tolerance: " << yTolerance <<std::endl;
	}
}
//  start with first guess, not two
//  Newtons Method:
//  x(current guess) = x(last guess) - (f(x(last guess)) / f'(x(last guess)))
//		x(current guess) becomes x(last guess)
//		method keeps iterating until until root is found
//

void newtons(double x0, double xTolerance, double yTolerance, double polyf[], double polyd[], int degf, int degd){
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"Iteration    Approx. root    x_tolerance    y_tolerance    "<<std::endl;
	int i = 0;
	double xi; // create approx. root
	while(i <= maxIterations && xTolerance >= 0.001 && yTolerance >= 0.00001){
		
		double func = horners(polyf, degf, x0); // calculate p(x) for x0
		double deriv = horners(polyd, degd, x0); // calculate p'(x) for x0
		xi = x0 - (func/deriv); // newton formula
		printf("func, deriv, x0, x1: %f %f %f %f\n", func, deriv, x0, xi);
		xTolerance = abs(x0 - xi); // xTolerance = 0.001
		yTolerance = abs(xTolerance - 1.048000); // |f(xn)| < tolerance = 0.00001
		x0 = xi; // set x(last guess) == to our new approx. root
		printf("   %d        %.6f        %.6f        %.6f   \n",i, xi, xTolerance, yTolerance);
		i++; // decrease i until number of max iterations is reached
	}
	std::cout <<"    Appromimated root: " << xi <<std::endl;
	std::cout <<"    Number of iterations: " << i <<std::endl;
	std::cout <<"    x_tolerance: " << xTolerance <<std::endl;
	std::cout <<"    y_tolerance: " << yTolerance <<std::endl;
}
//  Take Newton's formula and replace the derivative with the slope of f(x)
//  Need two initial guesses = x0 & x1
//  Secant Method: 
//  x2 = x1 - (f(x1) * (x1 - x0) / (f(x1) - f(x0))
//		

void secant(double x0, double x1, double xTolerance, double yTolerance, double polyf[], int degf){
	std::cout <<"================================================================"<<std::endl;
	std::cout <<"Iteration    Approx. root    x_tolerance    y_tolerance    "<<std::endl;
	int i = 0;
	while(i != maxIterations && xTolerance != 0.001 && yTolerance != 0.00001){
		
		/* int degf = sizeof(polyf)/sizeof(polyf[0]); // calculate degree of p(x) */
		double func1 = horners(polyf, degf, x1); // calculate p(x) for x1
		double func0 = horners(polyf, degf, x0); // calculate p(x) for x0
		double x2 = x1 - func1*(x1 - x0/func1 - func0); // secants formula
		xTolerance = x0 - x1; 
		yTolerance = abs(func0);
		printf("    %d      %.6f      %.6f      %.6f    \n",i, x2, xTolerance, yTolerance);
		x0 = x1; // set x(last guess) == to our new approx. root
		x1 = x2;
		i++; // decrease i until number of max iterations is reached
	}
	std::cout <<"Number of iterations: " << i <<std::endl;
	std::cout <<"x_tolerance: " << xTolerance <<std::endl;
	std::cout <<"y_tolerance: " << yTolerance <<std::endl;
}


