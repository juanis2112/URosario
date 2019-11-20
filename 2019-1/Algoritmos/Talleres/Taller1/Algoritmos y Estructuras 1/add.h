//
//  add.h
//  Algoritmos y Estructuras 1
//
//  Created by Juanita Gomez on 2/24/19.
//

#ifndef add_h
#define add_h
using namespace std;

// Punto 4


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



#endif /* add_h */
