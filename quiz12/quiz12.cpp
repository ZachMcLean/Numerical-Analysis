// Zach McLean
// Numerical Analysis
// 4/12/2022
// Quiz 12
// Construct the divided differences for a Newton Interpolant using a 
// SINGLE dimensional array
//
// data points: {(2,7),(4,11),(5,28),(6,59)}
//
// a will be initialized to the x values of the data points
// and will be replaced by the divided differences 
//
// step -1:
//	create and set up x, y, and a arrays
//
// step 0: 
//	copy initial divided differences from y[] to a[]
//
// step 1-3:
//	calculate divided differences
//

#include <iostream>
#include <stdio.h> // printf

int main(){
	// hardcoded data points
	//			 a0, a1, a2, a3
	double x[] = {2, 4, 5, 6}; // x values
	double y[] = {7, 11, 28, 59}; // y values
	int n = sizeof(y)/sizeof(y[0]); // length of array
	double a[n]; // divided differences

	for(int i = 0; i<=n-1; i++){
	  printf("Iteration: %d \n", i);
	  if(i == 0){ // step 0
		for(int p = 0; p<n; p++){ 
			a[p] = y[p]; // copy y[] to a[]
			printf("     a[%d]= %.1f \n", p, a[p]);
		}
		std::cout<<"\n";
	  }else{
		for(int j = 3-i; j>=0; j--){ // step 1-n
			a[j+i] = (a[j+i] - a[(j+i)-1]) / (x[j+i] - x[(j+i)-i]);
		}
		for(int p = 0; p<n; p++){
			printf("     a[%d]= %.1f \n", p, a[p]); // print total array for each step
		}
		std::cout<<"\n";
	  }
   }
}

