//
//  main.cpp
//  Taller9
//
//  Created by Juanita Gomez on 4/11/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#include <iostream>
using namespace std;

// ARRAY
int *createIndexArray(int k){
    int *array = new int[k];
    for(int i=0; i<k; i++)
        array[i] = i;
    return array;
}


struct Cell{
    int data;
    Cell *link;
};

// LINKED LIST
int *createIndexLinked(int k){
    Cell *arr = new Cell;
    Cell *temp = arr;
    for(int i=0; i<k; i++){
        temp->data = i;
        temp->link = new Cell;
        temp = temp->link;
    }
    temp->link = nullptr;
    
    int *result = &arr -> data;
    return result;
    
}

void destroy(int *p){
    int *temp = p;
    delete[] temp;
    
    
    
}



int main() {
    string word;
    cout<<"Palabra:";
    getline(cin,word);
    char *arr = new char[1];
    for(int i =0; i<word.length(); i++) arr[i] = word[i];
    
    
    return 0;
    
}
