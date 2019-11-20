//  simple_vector.cpp

#include "simple_vector.hpp"

const int initial_Capacity = 10;

// Copy Constructor
simple_vector::simple_vector(const simple_vector &rhs) : array(nullptr) {
    length = rhs.length;
    capacity = rhs.capacity + initial_Capacity;
    array = new double[capacity];
    for(int i=0; i<length; i++){
        array[i] = rhs.array[i];
    checkrep();
    }
}

// Destructor
simple_vector::~simple_vector(){
    delete[] array;
    array = nullptr;
    length = 0;
}

// Assignment operator overload

simple_vector& simple_vector::operator=(const simple_vector &rhs){
    simple_vector* otherVec = new simple_vector(rhs);
    double* old = this->array;
    this->capacity = otherVec->capacity;
    
    //COPY ELEMENT BY ELEMENT
    this->array = otherVec->array;
    this->length = otherVec->length;
    delete[] old;
    return *this;
}

// Insertion operator overload
ostream & operator<<(ostream &os, const simple_vector &rhs) {
    os << "(  ";
    for (int i = 0; i < rhs.length; i++) cout << rhs.array[i] << "  ";
    os << "), len = " << rhs.length << ", cap = " << rhs.capacity;
    
    return os;
}


// Class methods

void simple_vector::checkrep(){
    // Checks the representation invariant of the class
    assert (length >= 0 && length <= capacity);
}

void simple_vector::expandCapacity(){
    //Expands the capacity of the vector doubling it
    double *oldArray = array;
    capacity *=2;
    array = new double[capacity];
    for(int i=0; i<length; i++){
        array[i] = oldArray[i];
    }
    delete[] oldArray;
    checkrep();
}

void simple_vector::push(double value){
    // Adds the value "value" at the end of the array
    if(length == capacity) expandCapacity();
    array[length] = value;
    length++;
    checkrep();
}

void simple_vector::erase(int index){
    // Erases the value in array[index]
    if (length!=0 && index< length){
        for (int i = index; i <length-1 ; ++i)
            array[i] = array[i + 1];
        length--;
    }
    else {
        cout<<"ERROR, simple_vector::erase";
    }
    checkrep();
}

void simple_vector::insert(int index , double value){
    // Inserts the value in array[index] and shifts the elements to the right
    if(length+1>capacity)
        expandCapacity();
    length++;
    for (int i = length-1; i>=index ; --i)
        array[i] = array[i - 1];
    array[index] = value;
    checkrep();
}

void simple_vector::modify(int index , double value){
    // Modifies the element in array[index] for value
    if(index< length){
        array[index] = value;
    }
    checkrep();
}

double simple_vector::retrieve(int index) const{
    // Returns the value in array[index]
    if(index< length)
        return array[index];
    else
        return NAN;
}

void simple_vector::clear(){
    // Removes all the elements from a vector and makes its length 0
    length = 0;
    checkrep();
}

bool simple_vector::empty() const{
    // Returns True if the vector is empty
    return (length==0);
}

int simple_vector::size() const{
    // Returns the vector length
    return length;
}
