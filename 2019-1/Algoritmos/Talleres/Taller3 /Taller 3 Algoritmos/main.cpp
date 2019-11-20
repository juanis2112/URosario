//
//  main.cpp
//  Taller 3 Algoritmos
//
//  Created by Juanita Gomez on 2/5/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
// Punto 1

int linear_search(int A[], int n, int x)
{
    for (int i=1; i<n; i++){
        if (A[i] == x)
            return i;
    }
    return -1;
}

int binary_search(int A[], int n, int x){
    int lh = 1;
    int rh = n;
    while(lh <= rh){
        int mid = (lh+rh)/2;
        if (x==A[mid])
            return mid;
        else if(x > A[mid])
            lh = mid + 1;
        else
            rh = mid -1;
    }
    return -1;
}

// Punto 2

int find_missing(int A[], int n){
    int lh = 1;
    int rh = n;
    while(lh <= rh){
        int mid = (lh+rh)/2;
        if (A[mid]-A[mid-1]>1)
            return A[mid-1]+1;
        if (A[mid+1]-A[mid]>1)
            return A[mid+1]-1;
        if(mid==A[mid-1])
            lh = mid + 1;
        else
            rh = mid -1;
    }
    return rh+1;
}


// Punto 3

int findMaximum(int A[], int low, int high){
    int max = 0;
    int idx = low;
    while(idx <= high){
        if (max<A[idx])
            max = A[idx];
        idx++;
    }
    return max;
}

// Punto 4

int identity(int A[], int n){
    int i= 0;
    while(i<=n){
        if (A[i] ==i)
            return i;
        i++;
    }
    return -1;
}

// Punto 5

//BOGOSORT
bool is_sorted(int A[], int n){
    int prev=A[0];
    for(int i=1; i<n; i++){
        if(A[i]<prev){
            return false;
        }
        prev=A[i];
    }
    return true;
}

void bogoSort(int A[], int n){
    while(!is_sorted(A, n)){
        for(int i=0; i<n; i++){
            swap(A[i], A[rand()%n]);
        }
    }
}

//SELECTION SORT
void selectionSort(int A[], int n){
    for(int i=0; i<n; i++){
       int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(A[j]<A[minIndex])
                minIndex=j;
        }
        swap(A[i],A[minIndex]);
    }
}
//BUBBLE SORT
void bubbleSort(int A[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(A[j]> A[j+1])
                swap(A[j],A[j+1]);
        }
    }
}

//INSERTION SORT
void insertionSort(int A[], int n) {
	for(int i = 1; i < n; ++i) {
		int b = A[i];
		int j = i-1;
		while ((j >= 0) && (A[j] > b)) {
			A[j+1] = A[j];
			j -= 1;
		}
		A[j+1] = b;
	}
}



//PRINT ARRAY
void print(int A[], int n){
    for(int i=0; i<n; i++){
        cout << A[i] << endl;
    }
}


/*************************************************************************************/


int main(int argc, const char * argv[]) {
    int array1[] = {9,7,6,3,2,1,6,2};
    int array2[] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    int array3[] ={1,2,3,4,5,6,7,8,10,12,8,6,5,3,1};
    int array4[] ={1,2,2,5,6,7,8,10,12,8,6,5,3,1,14};
    int array5[] ={0,4,2,5};
    cout << linear_search(array1,8,6) <<endl;
    cout << binary_search(array1,8,6) <<endl;
    cout << find_missing(array2,16) <<endl;
    cout << findMaximum(array3,0,14) <<endl;
    cout << identity(array4,15) <<endl;
    bogoSort(array5, 4);
    selectionSort(array4, 15);
    bubbleSort(array3, 15);
    insertionSort(array1, 8);

    clock_t start;
    start = clock();
    bogoSort(array1, 8);
    double duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"printf: "<< duration <<'\n';

}
