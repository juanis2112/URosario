//
//  main.cpp
//  Taller1
//
//  Created by Juan David Sierra on 1/28/19.
//  Copyright © 2019 JuanSaudio. All rights reserved.
//

#include <iostream>


int countVowels(std::string someString) {
    int count = 0;
    for (int i = 0; i < someString.length(); i++) {
        char c = someString[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    return count;
}

int countDigits(std::string someString) {
    int count = 0;
    for (int i = 0; i < someString.length(); i++) {
        char c = someString[i];
        if (std::isdigit(c))
            count++;
    }
    return count;
}

std::string lowerCaseCopyString(std::string someString) {
    for (int i = 0; i < someString.length(); i++) {
        someString[i] = std::tolower(someString[i]);
    }
    return someString;
}

std::string lowerCaseString(std::string& someString) {
    for (int i = 0; i < someString.length(); i++) {
        someString[i] = std::tolower(someString[i]);
    }
    return someString;
}

std::string noSpaceString(std::string& someString) {
    std::string newString;
    for (int i = 0; i < someString.length(); i++) {
        if (someString[i] != ' ') {
            newString += someString[i];
        }
    }
    return newString;
}

std::string acronymizer(std::string someString) {
    std::string acronym;
    bool nextValueIsFirstLetter = true;
    for (int i = 0; i < someString.length(); i++) {
        if (nextValueIsFirstLetter && someString[i] != ' ') {
            acronym += someString[i];
            nextValueIsFirstLetter = false;
        }
        if (someString[i] == ' ') {
            nextValueIsFirstLetter = true;
        }
    }
    return acronym;
}

using namespace std;

int main(int argc, const char * argv[]) {

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

    cout << "char is: " << sizeof(char) << "bytes" << endl;
    cout << "int is: " << sizeof(int) << "bytes"  << endl;
    cout << "long is: " <<  sizeof(long) << "bytes"  << endl;
    cout << "float is: " <<  sizeof(float) << "bytes"  << endl;
    cout << "double is: " <<  sizeof(double) << "bytes"  << endl;
    cout << "bool is: " <<  sizeof(bool) << "bytes"  << endl;
    cout << "a Pointer is: " <<  sizeof(void*) << "bytes"  << endl;

    string myString = "Hello, World!";

    cout << countVowels(myString) << endl;
    cout << countDigits(myString) << endl;
    cout << lowerCaseCopyString(myString) << myString << endl;
    cout << lowerCaseString(myString) << myString << endl;
    cout << noSpaceString(myString) << endl;
    cout << acronymizer(myString) << endl;

    return 0;
}
