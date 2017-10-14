#include <iostream>
#include <cstdint>
using namespace std;

int main(){
    double n;
    cin >> n;
    double factorial = 1;

    for (double i = 1; i <= n; i++){
        factorial *= i;
    }

    cout << factorial << endl;
}