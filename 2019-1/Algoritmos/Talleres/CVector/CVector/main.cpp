//
//  main.cpp
//  CVector
//
//  Created by Juanita Gomez on 4/24/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#include <iostream>
#include "CVector.hpp"
using namespace std;
int main(){
    Cvector<int> p(4,100);
    Cvector<int> q(5,100);
    Cvector<int> w;
    w=q;
    
    //cout << p == q << endl;
    //cout<< w[1];
    
    
  
    //cout<<p[2]+q[2];
    return 0;
}
