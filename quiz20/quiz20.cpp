// Zach McLean
// Numerical Analysis
// 4/15/2022
// Quiz 20
// Calculate and verify the answers of Quiz 19 using Eulers and Huen's Method
// to find the approximate value of x' = t-x with x(2) = 4 && h = 1
//
// Heun's method is a two step process and can be written as
// Step 1: K = x(t) + h*f(t, x(t)) (Euler's Method)
//						= x'(t)
//						= (t - x(t))
// Step 2: x(t+h) = x(t) + 1/2*h*[f(t, x(t)) + f(t+h, K)]
//
// Compute the approximate value of x(3) && x(4)
//

#include <iostream>
#include <stdio.h> // printf

double func(double x, double t);

int main(){
	int n; // x(t+h)
	double t = 2.0;
	double xt = 4.0;
	int h = 1;
	double K=0.0;

	std::cout<<"Enter number of iterations: ";
	std::cin>>n;
	std::cout<<"\n";
	// set up hardcoded values
	// x' = t - x


	printf("Compute Euler's method for x(%.2f) iterations. \n", n);
	for(int i = 1; i <= n; i++){
		xt = 
	}

	printf("Compute Heuns method for x(%.2f) iterations. \n", n);
	for(int i = t; i<n; i++){
		K = xt + h * func(xt, t);
		xt = xt + 0.5*(h*((t-xt)+((t+h)-K)));
		t = t + h;
		printf("x(t+h)= %.2f\n", xt);
	}
}

double func(double x, double t){
	return (x - t);	
}


