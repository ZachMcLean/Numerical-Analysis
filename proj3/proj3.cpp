// Zach McLean
// Numerical Analysis
// 4/12/2022
// Project 3
// Construct the divided differences for a Newton Interpolant using a 
// SINGLE dimensional array
//
// user input for x values
// data points x[] = {-6, -4, -2, 0, 2, 4, 6}
//             y[] = 1/(x^2+1) = {1/37, 1/17, 1/5, 1, 1/15, 1/17, 1/37}
// n = 7
// a[] will be initialized to the y values of the data points
// and will be replaced by the divided differences 
//
// use a[] to evaluate the Newton's Interpolant
//	use nested form 

#include <iostream>
#include <stdio.h> // printf
#include <cmath>
#include <math.h> // pow

void horner(double a[], double fxi[], int n, int tn, double x[], double t[]);
int main(){
	// User Input for Data Points:
	std::cout<<"\nHow many data points? ";
	int n;
	std::cin >> n; // size of x

	double x[n];
	std::cout<<"Enter X values separated by spaces: ";
	for(int i = 0; i < n; i++){
	  std::cin >> x[i];
	}
	std::cout<<"\n";

	// hardcoded data points
	//			 a0, a1, a2, a3
	/* double x[] = {-6, -4, -2, 0, 2, 4, 6};   // x values */
	/* int n = sizeof(x)/sizeof(x[0]);			 // length of array */


	double y[n];
	for(int i = 0; i < n; i++){
		y[i] = (1 / (pow(x[i], 2)+1)); // y values
	} 
	/* printf("y6: %.10f", y[n-1]); */
	double a[n]; // divided differences

	// Compute Divided Differences x[], y[]
	std::cout<<"Divided Differences: \n";
	std::cout<<"-------------------- \n";
	for(int i = 0; i<=n-1; i++){
	  printf("\nIteration: %d \n", i);
	  std::cout<<"-------------\n";
	  if(i == 0){ // step 0
		for(int p = 0; p < n; p++){ 
			a[p] = y[p]; // copy y[] to a[]
			printf("     a[%d]= %.10f \n", p, a[p]);
		}
		std::cout<<"\n";
	  }else{
		for(int j = (n-1)-i; j>=0; j--){ // step 1-n
			a[j+i] = (a[j+i] - a[(j+i)-1]) / (x[j+i] - x[(j+i)-i]);
		}
		for(int p = 0; p<n; p++){
			printf("     a[%d]= %.10f \n", p, a[p]); // print total array for each step
		}
		std::cout<<"\n";
	  }
   }
	std::cout<<"\n";

	// User Input for Test Values:
	std::cout<<"How many test values? ";
	int tn;
	std::cin >> tn;

	double t[tn];
	std::cout<<"Enter all X values separated by spaces: ";
	for(int i = 0; i < tn; i++){
	  std::cin >> t[i];
	}
	std::cout<<"\n";
	
	//				Original Hard Coded Test Values
	/* double t[] = {-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6}; */
	/* int tn = sizeof(t)/sizeof(t[0]);	// length of t[] */

	// Calculate new y[] for 13 test variables using 1/(x^2+1)
	double fxi[tn];
	for(int i = 0; i < tn; i++){
		fxi[i] = (1 / (pow(t[i], 2)+1)); // fxi values
	} 

	// Evaluate Newton Interpolant given x[], a[], && x = t, Comput P(t)
	// Call horners algorithm and use a NESTED FORM for the Interpolant
	std::cout<<"| i | Xi |     f(Xi)     |     P(Xi)     | |f(Xi)-P(Xi)| |\n";
	std::cout<<"----------------------------------------------------------\n";
    horner(a, fxi, n, tn, x, t);
}

// Newton's General Nested Form
// a0 + (x-x0)[a1 + (x-x1)[a2 + (x-x2)[a3 + (x-x3)[a4 + (x-x4)[a5 + (x-x5)[a6]]]]]] 
// 
// ans = [a6]
// ans = [a6]* (x-x5) + [a5]
// ans = ans * (x-x4) + [a4]
// ans = ans * (x-x3) + [a3]
// ans = ans * (x-x2) + [a2]
// ans = ans * (x-x1) + [a1]
// ans = ans * (x-x0) + [a0]
//  
//		diff variables	f(Xi)  deg	 x data points test values
void horner(double a[], double fxi[], int n, int tn, double x[], double t[]){

    // Evaluate approximate value of polynomial using Horner's method
	for(int i = 0; i < tn; i++){	
		double ans = a[n-1]; // initialize P(Xi) to [a6]
		double errorbound;   // f(Xi) - P(Xi)

		for (int j=1; j < n; j++){
			ans = ans * (t[i] - x[(n-j)-1]) + a[(n-j)-1];
		}
		errorbound = abs(fxi[i] - ans); 
		printf(" %2d   %2.0f   %12.9f    %12.9f    %12.9f  \n", i, t[i], fxi[i], ans, errorbound);
	}
}
 
