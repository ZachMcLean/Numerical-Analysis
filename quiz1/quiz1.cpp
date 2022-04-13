#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double x; // radians
	double n, approx, error;
	double h = 1;
	double answer = cos(x);
	
	cout << "enter the number of radians: ";
	cin >> x;
	cout << "enter number of iterations: ";
	cin >> n;

	cout << "=====================================================" << endl;
	cout << "i           h             Approximation         Error" << endl;
 	cout << "=====================================================" << endl;
 	for(int i = 1; i <= n; i++){
    		h = (0.25 * h);
		approx = ((sin(x+h) - sin(x)) / h);
		error = answer - approx;
		error = fabs(error);
		cout.precision(10);
		cout << i << "  " << fixed << h << "        " << approx << "      " << error << endl;
  }
  cout << "=====================================================" << endl;
  return 0;
}
