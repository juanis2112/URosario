//
//  CVector.cpp
//  CVector
//
//  Created by Juanita Gomez on 4/24/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#ifdef CVector_hpp


// ----------------- Constructors ------------------

// Empty
template <typename numberType>
Cvector<numberType>::Cvector(){
    capacity = Initial_Capacity;
    array = new numberType[capacity];
    length = 0;
}

// Parametric Constructor
template <typename numberType>
Cvector<numberType>::Cvector(const Cvector &rhs){
    capacity = rhs.capacity + Initial_Capacity;
    array = new numberType[capacity];
    for (size_t i = 0; i < rhs.length; i++){
        array[i] = rhs.array[i];
    }
    length = rhs.length;
}

// Fill Constructor
template <typename numberType>
Cvector<numberType>::Cvector(size_t size, numberType value){
    capacity = Initial_Capacity;
    array = new numberType[capacity];
    length = size;
    for (size_t i = 0; i < size; i++) array[i] = value;
}

// Destructor
template <typename numberType>
Cvector<numberType>::~Cvector(){
    delete[] array;
}

// Operators
template <typename numberType>
Cvector<numberType>  Cvector<numberType>::operator=(const Cvector &rhs){
    numberType *Oldarray = this -> array;
    this -> array = new numberType[rhs.capacity + Initial_Capacity];
    for (int i = 0; i < rhs.length; i++){
        array[i] = rhs.array[i];
    }
    this -> length = rhs.length;
    this -> capacity = rhs.capacity + Initial_Capacity;
    delete[] Oldarray;
    return *this;
}

template <typename numberType>
numberType Cvector<numberType>::operator [] (size_t idx){

    return array[idx];
}


template <typename numberType>
Cvector<bool> operator == (const Cvector<numberType> &x , const Cvector<numberType> &y){
    Cvector<bool> result;
    if(x.length == y.length){
    for (size_t i = 0; i < x.length; i++){
            result.array[i] = (x.array[i] == y.array[i]);
        }
    }

    return result;
}


//template <typename numberType>
//ostream & operator<< (ostream &os, const Cvector<numberType> &rhs) {
//    os << "(  ";
//    for(int i = 0; i < rhs.length; i++){
//        cout << rhs.array[i] << "  ";
//    }
//    os << ")";
//    
//    return os;


template <typename numberType>
Cvector<bool> operator != (const Cvector<numberType> &x , const Cvector<numberType> &y){
    Cvector<bool> result;
    for (size_t i = 0; i < x.length; i++){
        result.array[i] = (x.array[i] != y.array[i]);
    }
    return result;
}

template <typename numberType>
Cvector<bool> operator <= (const Cvector<numberType> &x , const Cvector<numberType> &y){
    Cvector<bool> result;
    for (size_t i = 0; i < x.length; i++){
        result.array[i] = (x.array[i] <= y.array[i]);
    }
    return result;
}

template <typename numberType>
Cvector<bool> operator >= (const Cvector<numberType> &x , const Cvector<numberType> &y){
    Cvector<bool> result;
    for (size_t i = 0; i < x.length; i++){
        result.array[i] = (x.array[i] >= y.array[i]);
    }
    return result;
}

template <typename numberType>
Cvector<bool> operator < (const Cvector<numberType> &x , const Cvector<numberType> &y){
    Cvector<bool> result;
    for (size_t i = 0; i < x.length; i++){
        result.array[i] = (x.array[i] < y.array[i]);
    }
    return result;
}

template <typename numberType>
Cvector<bool> operator > (const Cvector<numberType> &x , const Cvector<numberType> &y){
    Cvector<bool> result;
    for (size_t i = 0; i < x.length; i++){
        result.array[i] = (x.array[i] > y.array[i]);
    }
    return result;
}


// Binary operators

template <typename numberType>
Cvector<numberType>& operator +(const Cvector<numberType> &x, const Cvector<numberType> &y){
    Cvector<numberType> result;
    size_t len = max(x.length, y.length);
    for (size_t i = 0; i < len; i++){
        result.array[i] = x.array[i] + y.array[i];
    }

    return result;
}

template <typename numberType>
Cvector<numberType>& operator -(const Cvector<numberType> &x, const Cvector<numberType> &y){
    Cvector<numberType> result;
    size_t len = max(x.length, y.length);
    for (size_t i = 0; i < len; i++){
        result.array[i] = x.array[i] - y.array[i];
    }
    
    return result;
}

template <typename numberType>
Cvector<numberType>& operator *(const Cvector<numberType> &x, numberType &y){
    Cvector<numberType> result;
    size_t len = max(x.length, y.length);
    for (size_t i = 0; i < len; i++){
        result.array[i] = x.array[i] * y;
    }
    
    return result;
}

template <typename numberType>
Cvector<numberType>& operator /(const Cvector<numberType> &x, numberType &y){
    Cvector<numberType> result;
    
    // if y= 0 EXPLOTA
    size_t len = max(x.length, y.length);
    for (size_t i = 0; i < len; i++){
        result.array[i] = x.array[i] / y;
    }
    
    return result;
}

template <typename numberType>
Cvector<numberType>& operator ^(const Cvector<numberType> &x, numberType &y){
    Cvector<numberType> result(x);
    for (size_t i = 0; i < y; i++){
        result.array = x.array * result.array;
    }
    
    return result;
}

//template <typename numberType>
//void Cvector<numberType>::push(double value){
//    if(length == capacity){
//        expandCapacity();
//    }
//    array[length++] = value;
//}
//
//template <typename numberType>
//void Cvector<numberType>::erase(int index){
//    if(index == length - 1){
//        --length;
//    }
//    else if(index < 0 || index > length){
//        cout << "Error, este index no esta en su vector" << endl;
//    }
//    else{
//        double *Oldarray = array;
//        array = new double[capacity];
//        for(int i = 0; i < index; i++){
//            array[i] = Oldarray[i];
//        }
//        for(int i = index + 1; i < length; i++){
//            array[i-1] = Oldarray[i];
//        }
//        delete[]Oldarray;
//        --length;
//    }
//}
//
//template <typename numberType>
//void Cvector<numberType>::insert (int index, double value){
//    if(index == length) {
//        push(value);
//    }
//    else{
//        if(length == capacity) {
//            expandCapacity();
//        }
//        double *Oldarray = array;
//        array = new double[capacity];
//        if(index == 0){
//            array[0] = value;
//            for (int i = 1; i <= length; i++){
//                array[i] = Oldarray[i-1];
//            }
//        }
//        else{
//            for (int i = 0; i < index; i++) array[i] = Oldarray[i];
//            array[index] = value;
//            for (int i = index + 1; i <= length; i++) array[i] = Oldarray[i-1];
//        }
//        delete[]Oldarray;
//        length++;
//    }
//}
//
//
//template <typename numberType>
//void Cvector<numberType>::clear(){
//    double *Oldarray = array;
//    array = new double[capacity];
//    length = 0;
//    delete[]Oldarray;
//}
//
//template <typename numberType>
//bool Cvector<numberType>::empty() const{
//    if(length == 0){
//        return true;
//    }
//    else{
//        return false;
//    }
//}
//
//template <typename numberType>
//int Cvector<numberType>::size() const{
//    return length;
//}

//////////////////////////////////////////// Funciones Extra
//
//template <typename numberType>
//void Cvector<numberType>::expandCapacity(){

//    double *Oldarray = array;
//    capacity *= 2;
//    array = new double[capacity];
//    for(int i = 0; i < length; i++){
//        array[i] = Oldarray[i];
//    }
//    delete[] Oldarray;

//}




//
//template <typename numberType>
//void Cvector<numberType>::checkrep() const{
//    assert (length >= 0);
//    assert (length <= capacity);
//}




#endif //CVector_hpp
