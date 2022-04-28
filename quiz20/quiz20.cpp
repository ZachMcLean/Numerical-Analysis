// Zach McLean
// Numerical Analysis
// 4/27/2022
// Quiz 20
// Calculate and verify the answers of Quiz 19 using Eulers and Huen's Method
// to find the approximate value of x' = x + t*t with x(0) = 1 && h = b - a / n
//										a = 0 ; b = 1 ; n = 5
//
// Heun's method is a two step process and can be written as
// Step 1: K = x(t) + h*f(t, x(t)) (Euler's Method)
//			 = x(t) + h * x'(t)
//					= (x(t) + t*t)
// Step 2: x(t+h) = x(t) + 1/2*h*[f(t, x(t)) + f(t+h, K)]
//								 [(x(t) + t*t) + (K + x(t+h))]
//
// Compute the approximate value of x(1)
//

#include <iostream>
#include <stdio.h> // printf

double func(double x, double t);

int main(){
	int n; // number of sub intervals
	std::cout<<"Enter number of iterations: ";
	std::cin>>n;
	std::cout<<"\n";

	double t = 0.0;
	double x = 1.0;
	double h = (x-t)/n;
	double K=0.0;
	bool stop = false;
	double k[n];

	printf("Compute Euler's method for x(%.2f) with %.2f iterations. \n", x, n);
	for(int i = 0; i < n; i++){
		x = x + (h * func(x, t));
		t = t+h;
		printf("x(%.2f)= %.2f \n", t, x);
	}

	x = 1.0;
	t = 0.0;
	printf("Compute Heuns method for x(%.2f) with %.2f iterations. \n", x, n);
	for(int i = 0; i<n; i++){
		K = x + (h * func(x, t));
		x = x + ((h/2) * ((func(x, t) + (func(K, t+h)))));
		t = t + h;
		printf("x(%.2f + h)= %.2f \n", t, x);
	}

	x = 1.0;
	t = 0.0;
	n = 1; // Entire sub-interval
	printf("Compute Runge-Kutta method for x(%.f) with %.2f iterations. \n", x, n);
	h = (x-t)/n;
	while(stop==false){
		k[0] = h*(func(x, t));
		k[1] = h*(func(x + (k[0]/2), t + (h/2)));
		k[2] = h*(func(x + (k[1]/2), t + (h/2)));
		k[3] = h*(func(x + k[2], t+h));
		K = x + ((1.0/6.0) * (k[0] + 2*k[1] + 2*k[2] + k[3]));
		printf("x(%.f)= %.2f \n", h, K);
		stop = true;
	}
}





double func(double x, double t){
	return (x + (t*t));	
}


