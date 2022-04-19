// Zach McLean
// 4/18/2022
// Quiz 18
// Implement Trapezoids, rule, Richardson's extrapolation, 
// and Simpson's rule for definite integral approximation
//
// Write seperate functions for each integrand and end each 
// of the three methods

#include <iostream>
#include <cmath>

richardsons(double a, double b, int n, int t){
	// x = a2n + ((A2n - An) / 3)	
	double An = trapezoid(a, b, n, t);
	double 2n = 
	double A2n = trapezoid();
	double x = A2n + ((A2n - An) / 3)
}

trapezoid(double a, double b, int val, int t){
	// (1/2)*(h)*E[f(x0) -> f(xn)]
	if(val == 0){
		double h = b - a;
		double sum = 0.0;
		double fx = integrand1(a);	
		for(int i = 1; i <= t-1; i++){
			double sum = integrand1(a + h);	
		}
		sum = (1/2) * (h) * sum;
		return sum;
	}else if(val == 1){
		double h = b - a;
		double sum = 0.0;
		double fx = integrand2(a);	
		for(int i = 1; i <= t-1; i++){
			double sum = integrand2(a + h);	
		}
		sum = (1/2) * (h) * sum;
		return sum;
	}	
}

integrand1(double x){
	// [1, 2]x^-1 dx
	return 1 / x;
}

integrand2(double x){
	return 1 / (double pow(x, 2.0) + 2.0);
}

int main(){
// create the bounds for the first function(a, b) = (1, 2)
	double a = 1.0;
	double b = 2.0;
	int t = 0.0; // number of sub intervals
	int val = 0; // this is to determine whether we want to integrate func1 or func2
	// first create functions for calculating the integrand
	// second create three functions for each method to calculate the integrands
	// trapezoid func1 = // [1, 2]x^-1 dx, sub interval 1 = [1 2],h=1, 2 = [1 3/2 2],h=0.5, 4 = [1 5/4 3/2 7/4 2],h=0.25
	//
	double trap = 0.0;
	double richard = 0.0;
	double simp = 0.0;
	for(int i = 0; i < 3; i++){
		trap = trapezoid(a, b, val, t);
		t *= 2;
	}
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
