#include <iostream>
using namespace std;

int main(){
    float sum1 = 0.0f;
    float sum2 = 0.0f;

    for (float i = 1.0f; i <= 100; i++){
        sum1 += 1/(i);
    }

    for (float i = 100.0f; i >= 1; i--){
        sum2 += 1/(i);
    }

    cout << "as float: " << endl;
    cout << sum1 << endl;
    cout << sum2 << endl;
    cout << sum1 - sum2 << endl << endl;

    double sum3 = 0.0;
    double sum4 = 0.0f;

    for (double i = 1.0; i <= 100; i++){
        sum3 += 1/(i);
    }

    for (double i = 100.0; i >= 1; i--){
        sum4 += 1/(i);
    }

    cout << "as double: " << endl;
    cout << sum3 << endl;
    cout << sum4 << endl;
    cout << sum3 - sum4 << endl;
}