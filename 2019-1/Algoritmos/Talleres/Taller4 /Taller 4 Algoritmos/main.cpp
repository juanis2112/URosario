//
//  main.cpp
//  Taller 4 Algoritmos
//
//  Created by Juanita Gomez on 2/15/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#include <iostream>
using namespace std;

int FindMin(int A[], int n){
    int min =A[0];
    for(int i=0; i<n; i++){
        if(A[i]<min)
            min = A[i];
    }
    return min;
}

int FindMax(int A[], int n){
    int max =A[0];
    for(int i=0; i<n; i++){
        if(A[i]>max)
            max = A[i];
    }
    return max;
}

int main(int argc, const char * argv[]) {

    int array1[] = {9,7,6,3,2,1,6,2};
    cout << FindMin(array1,8) <<endl;
    cout << FindMax(array1,8) <<endl;
}



