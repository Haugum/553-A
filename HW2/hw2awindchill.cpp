//  EE 553
//  main.cpp
//
//  Created by Jo Haugum on 9/5/17.
//  Copyright © 2017 Jo Haugum. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

void printmatrix(int matrix[13][19]);

int main(){
    // 18c by 13r matrix
    
    // initialize matrix, row and column headers
    int noaa [13][19] = {0};
    
    for (int c = 40, i = 1; c >= -45; c -= 5, i++){
        noaa[0][i] = c;
    }
    for (int r = 5, i = 1; r <= 60; r += 5, i++){
        noaa[i][0] = r;
    }
    
    // fill matrix
    for (int c = 40, i = 1; c >= -45; c -= 5, i++){
        for (int r = 5, j = 1; r<= 60; r += 5, j++){
            int sum = round(35.74 + 0.6215 * c - 35.75 * (pow(r, 0.16)) + 0.4275 * c * (pow(r, 0.16)));
            noaa[j][i] = sum;
        }
    }
    
    printmatrix(noaa);
    
    
    // for (int c = 40; c >= -45; c--){
    // 	for (int r = )
    // }
    
    
}
void printmatrix(int matrix[13][19]){
    for (int i = 0; i < 13; i++){
        for (int j = 0; j < 19; j++){
            cout << matrix[i][j] << '\t';
        }
        cout << '\n';
    }
}