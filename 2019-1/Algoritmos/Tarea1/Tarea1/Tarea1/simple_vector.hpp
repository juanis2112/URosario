//  simple_vector.hpp


#ifndef simple_vector_h
#define simple_vector_h
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cassert>
using namespace std;


class simple_vector {
    

public:
    simple_vector()=default;
    simple_vector(const simple_vector &rhs);
    simple_vector(int h)= delete;
    ~simple_vector();
    
    simple_vector & operator=(const simple_vector &rhs);
    friend ostream & operator<<(ostream &os, const simple_vector &rhs);
    
    void push(double value);
    void erase(int index);
    void insert(int index , double value);
    void modify(int index , double value);
    double retrieve(int index) const;
    
    void clear();
    bool empty() const;
    int size() const;
    

private:
    double *array = new double[10];
    int capacity = 10 , length = 0;
    void expandCapacity();
    void checkrep();
};
#endif /* simple_vector_h */
