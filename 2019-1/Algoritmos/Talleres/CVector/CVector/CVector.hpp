//
//  CVector.hpp
//  CVector
//
//  Created by Juanita Gomez on 4/24/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#ifndef CVector_hpp
#define CVector_hpp

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int Initial_Capacity = 10;


// Definitions
template <typename numberType> class Cvector;

template <typename numberType> Cvector<bool> operator == (const Cvector<numberType> &x , const Cvector<numberType> &y);

template <typename numberType> Cvector<bool>  operator != (const Cvector<numberType> &x , const Cvector<numberType> &y);

template <typename numberType> Cvector<bool>  operator > (const Cvector<numberType> &x , const Cvector<numberType> &y);

template <typename numberType> Cvector<bool>  operator < (const Cvector<numberType> &x , const Cvector<numberType> &y);

template <typename numberType> Cvector<bool>  operator >= (const Cvector<numberType> &x , const Cvector<numberType> &y);

template <typename numberType> Cvector<bool>  operator <= (const Cvector<numberType> &x , const Cvector<numberType> &y);

template <typename numberType> Cvector<numberType> & operator+ (const Cvector<numberType> & x, Cvector<numberType> & y);

template <typename numberType> Cvector<numberType> & operator- (const Cvector<numberType> & x, Cvector<numberType> & y);

template <typename numberType> Cvector<numberType> & operator* (const Cvector<numberType> & x, Cvector<numberType> & y);

template <typename numberType> Cvector<numberType> & operator/ (const Cvector<numberType> & x, Cvector<numberType> & y);

template <typename numberType> Cvector<numberType> & operator^ (const Cvector<numberType> & x, Cvector<numberType> & y);


//template <typename numberType> ostream & operator<< (ostream &os, const Cvector<numberType> &rhs);

template <typename numberType>
class Cvector{
public:

// Constructors
    // Empty
    Cvector();
    // Fill
    Cvector(size_t size, numberType value);
    // Parametric
    Cvector(const Cvector &rhs);
    
// Destructor
    ~Cvector();
    
// Operators
    
    // Class member operators
    
    Cvector<numberType> operator =(const Cvector &rhs);
    numberType operator [] (size_t idx);
    
    // Friend operatorss
    
    friend Cvector<bool> operator == <>(const Cvector<numberType> &x , const Cvector<numberType> &y);
    friend Cvector<bool>  operator != <>(const Cvector<numberType> &x , const Cvector<numberType> &y);
    friend Cvector<bool>  operator > <>(const Cvector<numberType> &x , const Cvector<numberType> &y);
    friend Cvector<bool>  operator < <>(const Cvector<numberType> &x , const Cvector<numberType> &y);
    friend Cvector<bool>  operator >= <>(const Cvector<numberType> &x , const Cvector<numberType> &y);
    friend Cvector<bool>  operator <= <>(const Cvector<numberType> &x , const Cvector<numberType> &y);
    
    //friend ostream & operator << <> (ostream &os, const Cvector<numberType> &rhs);
    //friend istream & operator>>(istream &os, const vector &rhs);
    
// Binary operators
    
    friend Cvector<numberType> & operator+ <>(const Cvector<numberType> & x, Cvector<numberType> & y);
    friend Cvector<numberType> & operator- <>(const Cvector<numberType> & x, Cvector<numberType> & y);
    friend Cvector<numberType> & operator*<>(const Cvector<numberType> & x, Cvector<numberType> & y);
    friend Cvector<numberType> & operator/<>(const Cvector<numberType> & x, Cvector<numberType> & y);
    friend Cvector<numberType> & operator^ <>(const Cvector<numberType> & x, Cvector<numberType> & y);

// Operations
//    numberType dot(Cvector w);
//    Cvector cross(Cvector w);
//
//// Methods
//    float angle(Cvector w);
//    float norm();
//    Cvector project(Cvector w);
//    Cvector normalize(Cvector w);
//
//    void push(numberType value);
//    void erase(size_t index);
//    void insert (size_t index, numberType value);
//
//    void clear();
//    bool empty() const;
//    size_t size() const;
    
private:
    size_t capacity = 10 , length = 0;
    numberType *array;
    void expandCapacity();
    //void checkrep() const;
};

#include "CVector.cpp"
#endif /* CVector_hpp */
