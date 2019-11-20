//
//  main.cpp
//  Algoritmos y Estructuras 1
//
//  Created by Juanita Gomez on 1/27/19.
//

#include <iostream>
#include <string>
#include "add.h"
using namespace std;

int main(int argc, const char * argv[]) {

// Punto 2 --------------------------------------------------------------------------------------------------------------------
    
    string testString;
    
    cout << "This are separated by spaces" << endl;
    for (int i = 0; i < 5; i ++) {
        getline(cin, testString, ' ');
        cout << testString;
    }
    
    testString = "";
    cout << "This are separated by endl" << endl;
    for (int i = 0; i < 5; i ++) {
        getline(cin, testString, '\n');
        cout << testString;
    }
// Punto 3 --------------------------------------------------------------------------------------------------------------------
    
    cout << "char is: " << sizeof(char) << " bytes" << endl;
    cout << "int is: " << sizeof(int) << " bytes"  << endl;
    cout << "long is: " <<  sizeof(long) << " bytes"  << endl;
    cout << "float is: " <<  sizeof(float) << " bytes"  << endl;
    cout << "double is: " <<  sizeof(double) << " bytes"  << endl;
    cout << "bool is: " <<  sizeof(bool) << " bytes"  << endl;
    cout << "a Pointer is: " <<  sizeof(void*) << " bytes"  << endl;
    
// Punto 4 --------------------------------------------------------------------------------------------------------------------
    
    string myString = "Hello, World!";
    
    cout <<"Vowels: "<< countVowels(myString) << endl;
    cout <<"Digits: "<< countDigits(myString) << endl;
    cout <<"LowerCaseCopy: "<< lowerCaseCopyString(myString) << myString << endl;
    cout <<"LowerCase: "<< lowerCaseString(myString) << myString << endl;
    cout <<"NoSpaces: "<< noSpaceString(myString) << endl;
    cout <<"Acronym: "<< acronymizer(myString) << endl;
    
    return 0;
}
