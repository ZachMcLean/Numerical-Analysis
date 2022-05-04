// Zach McLean
// 4/14/2022
// 
// Newton/Lagrange Form - One function
// Spline function - Collection of Functions
//
// data points: t0, t1,... tn
// What to evaluate S(t)
// Assume i = 0
// While (ti+1 <= t) && (i < n-1)
//	for each t, must determine which S(x) piece to use for the evaluation
//	i++
// 
// Output:
// Data Points: (ti, yi)
// (tn, yn) = ()
//
// Tridiagonal System for z1 through z(n-1)
//
//
// Tridiagonal system after Forward Elimination
//
// Solutions for S''(ti) = zi
// ---------------------------
// z0: = 0
// z1:
// z2:
//
// z8: = 0
//
// Coefficients for Natural Cubic Spline in nested form
// -----------------------------------------------------
// A0: _____ B0: _____ C0: _____ D0: _____
//
//
// An
//
// Natural Cubic Spline in nested form
// ------------------------------------
// s) : ___+(x+_)*(___ + (x+_)* etc
//
//
// Evaluation of Original and Spline functions and the absolute errors
// i   xi     f(xi)      S(xi)    |f(xi)-S(xi)|
// ---------------------------------------------
//
//

#include <iostream>
/* #include <stdlib> */
#include <cmath>

int main() {
	
	// Data points (ti, yi)
	//

	// hardcoded data points
	//			 a0, a1, a2, a3
	double x[] = {-6, -4, -2, 0, 2, 4, 6};   // x values
	int n = sizeof(x)/sizeof(x[0]);			 // length of array
	
	double y[n];
	for(int i = 0; i < n; i++){
		y[i] = (1 / (pow(x[i], 2)+1)); // y values
	} 

	for (int i = 0; i < 
	/* printf("y6: %.10f", y[n-1]); */
	double a[n]; // 

	//				Original Hard Coded Test Values
	/* double t[] = {-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6}; */
	/* int tn = sizeof(t)/sizeof(t[0]);	// length of t[] */

// Load Si(x) Functions into a Tri-diagonal Matrix
	int size;
	
	double d_arr[size];
	double u_arr[size-1];
	double l_arr[size-1];
	double b_arr[size];
	for(int i = 0; i < 4; i++){
		if(i == 0){
			std::cout<<"Please enter diagnal array values seperated by space: ";
			for(int j = 0; j < size; j++){
				std::cin>>d_arr[j];
				/* printf("d[%d]: %.2f \n", j, d_arr[j]); */
			}
		}
		if(i == 1){
			std::cout<<"Please enter upper array values seperated by space: ";
			for(int j = 0; j < size-1; j++){
				std::cin>>u_arr[j];
				/* printf("d[%d]: %.2f \n", j, d_arr[j]); */
			}
		}
		if(i == 2){
			std::cout<<"Please enter lower array values seperated by space: ";
			for(int j = 0; j < size-1; j++){
				std::cin>>l_arr[j];
				/* printf("d[%d]: %.2f \n", j, d_arr[j]); */
			}
		}	
		if(i == 3){
			std::cout<<"Please enter b array values seperated by space: ";
			for(int j = 0; j < size; j++){
				std::cin>>b_arr[j];
				/* printf("d[%d]: %.2f \n", j, d_arr[j]); */
			}
		}
	}

	double x_arr[] = {0.0, 0.0, 0.0, 0.0};
// Forward Elimination for Tri-diagnal System
	int zero = 0;
	for(int i = 0; i < size-1; i++){
		double m = l_arr[i] / d_arr[i];
		/* std::cout<<"m: "<<m<<"\n"; */
		l_arr[i] = l_arr[i] - (d_arr[i] * m);
		d_arr[i+1] = d_arr[i+1] - (u_arr[i] * m);
		b_arr[i+1] = b_arr[i+1] - (b_arr[i] * m);
		/* for(int i = 0; i <= size-1; i++){ */
		/* 	printf("d[%d]: %.2f \n", i, d_arr[i]); */
		/* 	printf("b[%d]: %.2f \n", i, b_arr[i]); */
		/* } */
		/* std::cout<<"\n"; */
	}
	// Print the matrix after the forward elimination phase
	for(int i = 0; i < size; i++){
		if(i == 0)
			printf(" | %.2f %.2f %d %d   | %.2f |\n", d_arr[i], u_arr[i], zero, zero, b_arr[i]);
		if(i == 1)
			printf(" | %d %.2f %.2f %d | %.2f |\n", zero, d_arr[i], u_arr[i], zero, b_arr[i]);
		if(i == 2)
			printf(" | %d %d %.2f %.2f | %.2f |\n", zero, zero, d_arr[i], u_arr[i], b_arr[i]);
		if(i == 3)
			printf(" | %d %d %d %.2f   | %.2f |\n", zero, zero, zero, d_arr[i], b_arr[i]);
	}

	std::cout<<"\n";
	// Back Substitution for Tri-diagnal System
	for(int i = size-1; i >= 0; i--){
		printf("x[%d]= %.2f / %.2f \n", i+1, b_arr[i], d_arr[i]);
		if(i == size-1){
			x_arr[i] = b_arr[i] / d_arr[i];
			printf("x[%d]: %.2f \n", i+1, x_arr[i]);
		}else{
			x_arr[i] = (b_arr[i] - x_arr[i+1] * u_arr[i]) / d_arr[i];
			printf("x[%d]: %.2f \n", i+1, x_arr[i]);
		}
	}

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
