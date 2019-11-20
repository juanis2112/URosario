//
//  main.cpp
//  Taller12
//
//  Created by Juanita Gomez on 4/18/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//
#include <random>
#include <iostream>
#include "hashTable.hpp"
using namespace std;

template <>
class hashFunction <int> {
    public:
    size_t operator()(const int & key) {
        return static_cast <size_t >(key);
        }
     };

int main() {
    const int min = -15, max = +15;
    random_device rd;
    default_random_engine generator{rd()};
    uniform_int_distribution <int> distribution(min, max);
    
    hashTable<int> ht;
    // insert keys
    for (int i = 0; i < max; ++i) {
        int key = distribution(generator);
        ht.insert(key);
        cout << "Insert: " << key << endl;
        }
    // invoke <<
    cout << endl;
    cout << endl;
    
    ht.display();
    
    cout << endl;
    cout << endl;
    
    // find keys
    for(int key = min; key < max; key++)
        cout<< "Find: " <<key << "    "<< ht.find(key) << endl;
    
    cout << endl;
    cout << endl;
    
    for(int i = min; i<max; i++){
        int key = distribution(generator);
        cout << "Remove: " << key << "    " <<ht.remove(key) << endl;
    }
    cout << endl;
    cout << endl;
    
    for(int key = min; key <max ; ++key)
        cout << "Find: " << key << "    " << ht.find(key) <<endl;
    
    cout << endl;
    cout << endl;
    return 0;
}

