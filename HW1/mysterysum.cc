#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float s1 = 0.0f;
    float s2 = 0.0f;
    float n = 4091.0f*1040.0f;  

    for (float i = 1.0f; i<n; i++){
        s1 += 1/(i*i);
    }

    for (float i = n; i >= 1; i--){
        s2 += 1/(i*i);
    }

    cout.precision(8);
    cout << sqrt(6*s1) << endl;
    cout << sqrt(6*s2) << endl;
}