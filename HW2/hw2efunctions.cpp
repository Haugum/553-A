#include <iostream>
#include <iomanip>
using namespace std;


double fibo(int n);
double fibo2(int n);
double fact(double n);
double fact2(double n);
double choose(int n, int r);

int main(){
	cout << setprecision(15);
	cout << fibo(30) << '\n';
	cout << fibo2(30) << endl;
	cout << fact(30) << endl;
	cout << fact2(30) << endl;
	cout << choose(52, 6) << endl;

	return 0;
}

double fibo(int n){
	int nums [n]; nums[0] = 1; nums[1] = 1;
	for (int i = 2; i < n + 2; i++){
		nums[i] = nums[i - 2] + nums[i - 1];
	}
	return nums[n - 1];
}

double fibo2(int n){
	if (n < 1) {return 0;}
	if (n == 1) {return 1;}
	if (n == 2) {return 1;}
	return fibo2(n - 1) + fibo2(n - 2);
}

double fact(double n){  
    double factorial = 1;

    for (double i = 1; i <= n; i++){
        factorial *= i;
	}
	return factorial;
}
double fact2(double n){
	if (n > 1){
		return n * fact2(n-1);
	}
	return 1;
}

double choose(int n, int r){
	double sum = 0;

	sum = fact(n) / ( (fact(r) * fact(n - r)) );

	return sum;
}