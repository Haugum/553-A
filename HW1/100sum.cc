#include <iostream>
using namespace std;

int main(){
    int sum1 = 0;
    int sum2 = 0;
    
    // Using Gauss formula n(n+1)/2
    sum1 = 100*(100+1)/2;
    cout << sum1 << '\n';

    // Using loop
    for (int i = 0; i <= 100; i++){
        sum2 += i;
    }
    cout << sum2 << '\n';
}