//
//  hashTable.hpp
//  Taller12
//
//  Created by Juanita Gomez on 4/18/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#ifndef _hashTable_hpp_
#define _hashTable_hpp_

#include <iostream>
#include<typeinfo>
#include<string>
#include <list>
#include <algorithm>
using namespace std;

const  size_t PRIME_INITIAL_DIMENSION = 11;
template <typename dataType > class hashFunction;
template <typename dataType >
class hashTable {
     // maximum value before invoking rehashing
    static float max_load_factor;
    
    //size_t count; // elements in table
    size_t nBuckets; // size of the table
    list <dataType> *table; // dynamic array of lists
    size_t count; // elements in table
    
    size_t hashing(const dataType & data);

public:

    hashTable();
    ~hashTable();
    
    bool find(const dataType & data);
    bool insert(const dataType & data);
    bool remove(const dataType & data);

    void clear();
    void rehash();
    
    float load_factor() const;
    float ret_max_load_factor() const;
    
    void display();
    
     };

#include "hashTable.cpp"
#endif /* hashTable_hpp */
