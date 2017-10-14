#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(unsigned long long p);

int main(){
    while (true){
        cout << "enter number: " ; unsigned long long input; cin >> input;
        
        bool primality = isPrime(input);
        
        if (primality == true)
            cout << "prime" << '\n';
        else if (primality == false)
            cout << "not prime" << '\n';
    }
    return 0;
    
}

    // Simple trial division
    // bool isPrime(unsigned long long p){
    //     if (p <= 3){
    //         return true;
    //     }
    //     else if (p > 3){
    //         for (unsigned long long i = 2; i < sqrt(p); i++){
    //             if (p % i == 0)
    //                 return false;
    //         }
    //     }
    //     return true;
    // }


bool isPrime(unsigned long long p)
{
    // Testing with 6k +/- 1. Runs * much * faster.
    // All prime follow the pattern of 6k +/- 1.
    // k = 1: 6k - 1 = 5    6k + 1 = 7
    // k = 2; 6k - 1 = 11   6k + 1 = 13
    // k = 3; 6k - 1 = 17   6k + 1 = 19
    if (p <= 1)  return false;
    else if (p <= 3)  return true;
    

    if (p % 2 == 0) return false;
    else if (p < 9) return true;
    else if (p % 3 == 0) return false;
    
    unsigned long long j = sqrt(p);
    for (unsigned long long i = 5; i <= j; i = i + 6)
        if (p % i == 0 || p % (i + 2) == 0)
            return false;
    
    return true;
}
