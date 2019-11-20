//
//  main.cpp
//  Taller8 Algoritmos
//
//  Created by Juanita Gomez on 3/15/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#include <iostream>
using namespace std;
class Racional{
// Frac
public:
    //Default constructor
    Racional(){
        p=0;
        q=1;
    }
    //Param. constructor
    Racional(int pc, int qc){
        p=pc;
        q=qc;
    }
    // Accessor
    int getP() {return p;}
    int getQ() {return q;}
    
    // Mutator
    void setP(int p1) {p=p1;}
    void setQ(int q1) {q=q1;}
    
    //Operators
    friend ostream & operator <<(ostream & os, Racional r);
    Racional operator=(Racional r);
    
//        friend ostream & operator +={ostream & os, Racional r);
//        friend ostream & operator -={ostream & os, Racional r);
//        friend ostream & operator *={ostream & os, Racional r);
//        friend ostream & operator /={ostream & os, Racional r);
    
    //Arithmetic Operators
    friend Racional operator+(Racional r1, Racional r2);
    friend Racional operator-(Racional r1, Racional r2);
    friend Racional operator*(Racional r1, Racional r2);
    friend Racional operator/(Racional r1, Racional r2);

private:
    // Declaration
    int p, q;
};

// ---------------------------------------------------------------//--------------------------------------------------------------

//Methods definition

//Insertion
ostream & operator<<(ostream & os, Racional r){
    return os << r.p << "/" << r.q ;
}


//Asignación
Racional Racional ::operator=(Racional r){
    p=r.p;
    q=r.q;
    return *this;
}

//Suma
Racional operator+(Racional r1, Racional r2){
    int den= r1.q*r2.q;
    int num= r1.p*r2.q + r2.p*r1.q;
    Racional result= Racional(num, den);
    return result;
    
}

//Resta
Racional operator-(Racional r1, Racional r2){
    int den= r1.q*r2.q;
    int num= r1.p*r2.q - r2.p*r1.q;
    Racional result= Racional(num, den);
    return result;
    
}

//Producto
Racional operator*(Racional r1, Racional r2){
    int den= r1.q*r2.q;
    int num= r1.p*r2.p;
    Racional result= Racional(num, den);
    return result;
    
}

//División
Racional operator/(Racional r1, Racional r2){
    int den= r1.q*r2.p;
    int num= r1.p*r2.q;
    Racional result= Racional(num, den);
    return result;
}
    

// ---------------------------------------------------------------//--------------------------------------------------------------

int main(){
    
    Racional a= Racional(1,2);
    Racional b= Racional(1,3);
    a+b;
    cout <<a+b <<endl ;
}


        
    
    

