// Zach McLean
// Numerical Analysis
// 4/5/2022
// Quiz 4
// Compute the value of the analytical solution using the C++ sqrt(1+h)
// Input constants of polynomial, the degree of the polynomial, and the value of x

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstdlib>

// f(x+h) = sqrt(x+h) <-- Evaluate approximate value
//
// Compute derivates 0-5 for f(1) = sqrt(1)
//    Store in array of double (six elements)
// F(x) = x^(1/2) + (1/2x^(-1/2))*h - (1/8x^(-3/2))*h^2 + (1/16x^(-5/2))*h^3 + (-5/128x^(-7/2)*h^4) + (7/256x^(-9/2))*h^5
// f(1) = 1 + 1/2h - (1/8)h^2 + (1/16)h^3 + (-5/128)h^4 + (7/256x^(-9/2))h^5
//
// Exact Value = the literal decimal of the function
// Actual Error = (analytical solution)sqrt(1+h) - (approx) => abs(actual))
// Error Bound = Polynomial value of n+1
//
// Horner's Algorithm
// 

void horner(double poly[], int n, double h);

int main() {
	//				f(1) f'(1) f''(1) f'''(1)  f''''(1)   f'''''(1)
	double poly[] = {1.0, 0.5, 0.125, 0.0625, 0.0390625, 0.02734375};
	/* double poly[] = {0.02734375, 0.0390625, 0.0625, 0.125, 0.5, 1.0}; */
	double h = 0;
	int n = sizeof(poly)/sizeof(poly[0]); // init size of array(degree of polynomial)
	// User Input
	std::cout<< "Enter the value of h(<=0.1): ";
	std::cin >> h;
	// Header
	std::cout <<"==================================================================="<<std::endl;
	std::cout <<"n       approximation          actual error          errorbound     \n";
	std::cout <<"==================================================================="<<std::endl;
	// Call Horner's Algorithm
	horner(poly, n, h);
	return 0;
}

// returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
void horner(double poly[], int n, double h)
{
	// init f(x+h)
	double exact = sqrt(1.0+h);
	double approx;
	/* double approx = poly[0]; // Initialize approximate error */
	double actual;
	double errorbound;
    // Evaluate approximate value of polynomial using Horner's method
    for (int i=0; i<n-1; i++){
		if(i==0){
			approx = poly[i]; // Initialize approximate error
			actual = abs(exact - approx);
			errorbound = poly[i+1];
			printf("%d    %.16f    %.16f    %.16f \n", i, approx, actual, errorbound);
		}else{
			// init 1 = (1)*0.1 + 0.5 ???
			approx = approx + poly[i] * pow(h, i);
			actual = abs(exact - approx); 
			errorbound = poly[i+1];
			printf("%d    %.16f    %.16f    %.16f \n", i, approx, actual, errorbound);
		}

	}
}
 
