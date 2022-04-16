// Zach McLean
// 4/14/2022
// 

#include <iostream>
/* #include <stdlib> */
#include <cmath>

int main() {
	// declare four single dimensional arrays
	// size will equal the amount of columns-1 in the array(number of diagnal entries)
	int size;
	std::cout<<"Enter num of rows: ";
	std::cin>>size;
	
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
	std::cout<<"\n";
	/* double d_arr[] = {1.0, 1.0, 2.0, 7.0}; */
	/* double u_arr[] = {3.0, -1.0, -1.0}; */
	/* double l_arr[] = {2.0, 4.0, 5.0}; */
	/* double b_arr[] = {7.0, 3.0, 8.0, 19.0}; */
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
	return 0;
}
