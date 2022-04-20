// Zach McLean
// 4/18/2022
// Quiz 18
//
// Implement Trapezoids rule T[si]=(1/2*h*(f(0) + 2*f(1) + 2*f(2)+...+f(n-1)))
//
// Richardson's extrapolation, 
//
// and Simpson's rule
//
// for definite integral approximation
//
// Write seperate functions for each integrand and end each 
// of the three methods

#include <iostream>
#include <cmath>


double f1(double);
double f2(double);
double simpsons(double a, double b, double(*f)(double), double ti);
double richardsons(double a, double b, int v, double(*f)(double), int ti);
double trapezoid(double a, double b, int val, double(*f)(double), double ti);

double simpsons(double a, double b, double(*f)(double), double ti){
	double h = (b-a) / ti;
	double sum = (*f)(a) + (*f)(b);
	for(int i = 1; i<b; i+=2){
		sum += (4 * (*f)(i));
		sum += (2 * (*f)(i+1));
	}
	sum += (4 * (*f)(b-1));
	return sum * (h/3);
}

double richardsons(double a, double b, int v, double(*f)(double), int ti){
	// x = a2n + ((A2n - An) / 3)	
	double An = trapezoid(a, b, v, (*f), ti);
	double nn = 2*ti;
	double A2n = trapezoid(a, b, v, (*f), nn);
	double x = A2n + ((A2n - An) / 3);
	return x;
}

double trapezoid(double a, double b, int val, double(*f)(double), double ti){
	// (1/2)*(h)*[f(x0)+f(xn)] * Ef(xn)]
		double h = (b - a) / ti;
		double sum = (*f)(a) + (*f)(b);
		double x = a+h;
		for(int i = 1; i < ti; i++){
			sum += 2*(*f)(x);
			x += h;
		}
		return (h/2)*sum;
}

double f1(double x){
	// [1, 2]x^-1 dx
	return (1 / x);
}

double f2(double x){
	return (1 / (pow(x, 2.0) + 2.0));
}

int main(){
// create the bounds for the first function(a, b) = (1, 2)
	// first create functions for calculating the integrand
	// second create three functions for each method to calculate the integrands
	// trapezoid func1 = // [1, 2]x^-1 dx, sub interval 1 = [1 2],h=1, 2 = [1 3/2 2],h=0.5, 4 = [1 5/4 3/2 7/4 2],h=0.25

	double a = 1.0;
	double b = 2.0;
	double ti = 1.0; // initial number of sub-intervals 
	int v = 0; // this is to determine whether we want to integrate func1 or func2

	double trap = 0.0;
	std::cout<<"Compute Integral[1, 2]; x^-1 dx using Trapezoid rule: \n";
	for(int i = 0; i < 3; i++){
		trap = trapezoid(a, b, v, f1, ti);
		printf("T[%.0f]: %0.5f \n", ti, trap);
		ti *= 2.0;
	}
	std::cout<<"\n";

	double richard = 0.0;
	std::cout<<"Compute Integral[1, 2]; x^-1 dx using Richardson's extrapolation: \n";
	ti = 2.0;
	for(int i = ti; i <= 4;){
		richard = richardsons(a, b, v, f1, ti);
		printf("R[%.0f]: %0.5f \n", ti, richard);
		ti *= 2.0;
		i = ti;
	}
	std::cout<<"\n";

	double simp = 0.0;
	std::cout<<"Compute Integral[1, 2]; x^-1 dx using Simpson's rule: \n";
	ti = 2.0;
	for(int i = ti; i <= 4;){
		simp = simpsons(a, b, f1, ti);
		printf("S[%.0f]: %0.5f \n", ti, simp);
		ti *= 2.0;
		i = ti;
	}
	std::cout<<"\n";

	a = 0.0;
	b = 1.0;
	trap = 0.0;
	ti = 1.0;

	std::cout<<"Compute Integral[0, 1]; (x^2 + 2)^-1 dx using Trapezoid rule: \n";
	for(int i = 0; i < 3; i++){
		trap = trapezoid(a, b, v, f2, ti);
		printf("T[%.0f]: %0.5f \n", ti, trap);
		ti *= 2.0;
	}
	std::cout<<"\n";

	richard = 0.0;
	ti = 2.0;

	std::cout<<"Compute Integral[0, 1]; (x^2 + 2)^-1 dx using Richardson's extrapolation: \n";
	for(int i = ti; i <= 4;){
		richard = richardsons(a, b, v, f2, ti);
		printf("R[%.0f]: %0.5f \n", ti, richard);
		ti *= 2.0;
		i = ti;
	}
	std::cout<<"\n";

	simp = 0.0;
	ti = 2.0;

	std::cout<<"Compute Integral[0, 1]; (x^2 + 2)^-1 dx using Simpson's rule: \n";
	for(int i = ti; i <= 4;){
		simp = simpsons(a, b, f2, ti);
		printf("S[%.0f]: %0.5f \n", ti, simp);
		ti *= 2.0;
		i = ti;
	}
	return 0;
}
/* double fun(double x){ */
	
/* } */

/* double sumIntegral(double lowBound, int n, double dx){ */
/* 	double sum = 0; */
/* 	for(int i = 0; i<n; i++){ */
/* 		double xi = lowBound+i*dx; */
/* 		double funValue = fun(xi); */
/* 		double rectangleArea = funValue*dx; */
/* 		sum += rectangleArea; */
/* 	} */
/* 	return sum; */
/* } */

/* int main() */
/* { */
/* 	double lowBound = 1; */
/* 	double upBound = 2; */
/* 	int n = 5; */
/* 	double dx = (double)(upBound - lowBound)/n; */
/* 	double result = sumIntegral(lowBound, n, dx); */
/* } */
