//  main.cpp
//  CMatrix
//
//  Created by Juanita Gomez on 4/30/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#include <iostream>
#include<vector>
#include "CMatrix.hpp"

using namespace std;

int main() {

    // Prueba de los métodos de la clase ///////////////////////////////////////

    // cout.precision(5);
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    // 1) Halle la matriz traspuesta de: m1 = {(5, 3, 6), (4, 10, 7), (1, 4, 2)}
    cout << "1) Halle la matriz traspuesta de: m1 = {(5, 3, 6), (4, 10, 7), (1, 4, 2)}. " << endl;
    cout << endl;
    vector<int> a1 = {5, 3, 6};
    vector<int> b1 = {4, 10, 7};
    vector<int> c1 = {1, 4, 2};
    Cmatrix<int> m1;
    Cvector<int> d1;
    Cvector<int> e1;
    Cvector<int> f1;
    for(unsigned i = 0; i < a1.size(); i++){
        d1.push(a1[i]);
        e1.push(b1[i]);
        f1.push(c1[i]);
    }
    m1.push(d1);
    m1.push(e1);
    m1.push(f1);
    cout << "m1.push: " << d1 << endl;
    cout << "m1.push: " << e1 << endl;
    cout << "m1.push: " << f1 << endl;
    cout << "m1: " << endl;
    cout << m1 << endl;
    cout << "m1.numberRows : " << m1.numberRows() << endl;
    cout << "m1.numberCols : " << m1.numberCols() << endl;
    cout << endl;
    cout << "Transpose of m1: " << endl;
    Cmatrix<int> m1t = m1.transpose();
    cout << m1t << endl;
    cout << "m1t.numberRows : " << m1t.numberRows() << endl;
    cout << "m1t.numberCols : " << m1t.numberCols() << endl;

    cout << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // 2) Transforme la matriz m1 a triangular inferior
    cout << "2) Transforme la matriz m1 a triangular inferior. " << endl;
    cout << endl;
    cout << "m1 to lower triangular: " << endl;
    Cmatrix<double> m1lt = m1.lowerTriangular();
    cout << m1lt << endl;
    cout << "m1lt.numberRows : " << m1lt.numberRows() << endl;
    cout << "m1lt.numberCols : " << m1lt.numberCols() << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // 3) Transforme la matriz m1 a triangular superior
    cout << "3) Transforme la matriz m1 a triangular superior. " << endl;
    cout << endl;
    cout << "m1 to upper triangular: " << endl;
    Cmatrix<double> m1ut = m1.upperTriangular();
    cout << m1ut << endl;
    cout << "m1ut.numberRows : " << m1ut.numberRows() << endl;
    cout << "m1ut.numberCols : " << m1ut.numberCols() << endl;

    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // 4) Cree la matriz identidad de orden 10
    cout << "4) Cree la matriz identidad de orden 10. " << endl;
    cout << endl;
    Cmatrix<double> m2;
    cout << "m2: " << endl;
    cout << m2 << endl;
    cout << "m2.numberRows : " << m2.numberRows() << endl;
    cout << "m2.numberCols : " << m2.numberCols() << endl;
    cout << endl;
    cout << "m2 to Identity: " << endl;
    Cmatrix<double> m2e = m2.eye(10);
    cout << m2e << endl;
    cout << "m2e.numberRows : " << m2e.numberRows() << endl;
    cout << "m2e.numberCols : " << m2e.numberCols() << endl;

    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // 5) Cree la matriz nula con 4 filas y 5 columnas
    cout << "5) Cree la matriz nula con 4 filas y 5 columnas. " << endl;
    cout << endl;
    cout << "m2: " << endl;
    cout << m2 << endl;
    cout << "m2 to Zeros: " << endl;
    Cmatrix<double> m2z = m2.zeros(4, 5);
    cout << m2z << endl;
    cout << "m2z.numberRows : " << m2z.numberRows() << endl;
    cout << "m2z.numberCols : " << m2z.numberCols() << endl;

    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // 6) Cree una matriz con 5 filas y 4 columnas, cuyos elementos sólo sean 1s
    cout << "6) Cree una matriz con 5 filas y 4 columnas, cuyos elementos solo sean 1s. " << endl;
    cout << endl;
    cout << "m2: " << endl;
    cout << m2 << endl;
    cout << "m2 to Ones: " << endl;
    Cmatrix<double> m2o = m2.ones(5, 4);
    cout << m2o << endl;
    cout << "m2o.numberRows: " << m2o.numberRows() << endl;
    cout << "m2o.numberCols: " << m2o.numberCols() << endl;

    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // 7) Cree una matriz con 3 filas y 5 columnas, cuyos valores sean random
    cout << "7) Cree una matriz con 3 filas y 5 columnas, cuyos valores sean random. " << endl;
    cout << endl;
    cout << "m2: " << endl;
    cout << m2 << endl;
    cout << "m2 to random: " << endl;
    Cmatrix<double> m2r = m2.random(3, 5);
    cout << m2r << endl;
    cout << "m2r.numberRows : " << m2r.numberRows() << endl;
    cout << "m2r.numberCols : " << m2r.numberCols() << endl;

    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // 8) Haga los siguientes swaps en la matriz m3 = {(9, 10, 5, 30), (5, 2, 6, 4), (7, 45, 1, 8)}
    // a) fila 1 - fila 3
    // b) columna 2 - columna 3
    cout << "8) Haga los siguientes swaps en la matriz m3 = {(9, -10, 5, -30), (5, 2, -6, 4), (-7, 45, 1, -8)}. " << endl;
    cout << "a) fila 1 - fila 3. " << endl;
    cout << "b) columna 2 - columna 3. " << endl;
    cout << endl;
    vector<int> a2 = {9, -10, 5, -30};
    vector<int> b2 = {5, 2, -6, 4};
    vector<int> c2 = {-7, 45, 1, -8};
    Cmatrix<int> m3;
    Cvector<int> d2;
    Cvector<int> e2;
    Cvector<int> f2;
    for(unsigned i = 0; i < a2.size(); i++){
        d2.push(a2[i]);
        e2.push(b2[i]);
        f2.push(c2[i]);
    }
    m3.push(d2);
    m3.push(e2);
    m3.push(f2);
    cout << "m3.push: " << d2 << endl;
    cout << "m3.push: " << e2 << endl;
    cout << "m3.push: " << f2 << endl;

    cout << "m3: " << endl;
    cout << m3 << endl;
    cout << endl;

    // a)
    m3.swap_r(0, 2);
    cout << "Changed Row 0 with Row 2 in m3: " << endl;
    cout << m3 << endl;

    // b)
    m3.swap_c(1, 2);
    cout << "Changed Column 1 with Column 3 in m3: " << endl;
    cout << m3 << endl;

    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // 9) Apliquele valor absoluto a todos los elementos de la matriz m3
    cout << "9) Apliquele valor absoluto a todos los elementos de la matriz m3. " << endl;
    cout << endl;
    cout << "m3: " << endl;
    cout << m3 << endl;
    cout << endl;
    Cmatrix<int> m3abs = m3.abs();
    cout << "m3 to abs: " << endl;
    cout << m3abs << endl;

    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // 10) Halle el determinante de la matriz r
    cout << "10) Halle el determinante de la matriz r. " << endl;
    cout << endl;
    Cvector<double> v;
    v.push(1);
    v.push(4);
    v.push(3);
    Cmatrix<double> r (3,v);
    r(1,1) = -1;
    r(0,1) = -3;
    r(2,2) = -2;
    cout << "r: " << endl;
    cout << r << endl;
    tuple<Cvector<double>, Cmatrix<double>, Cmatrix<double>> c = r.LUP(0.001);
    // cout << "P:" << get<0>(c) << endl;
    // cout << "L:" << get<1>(c) << endl;
    // cout << "U:" << get<2>(c) << endl;
    double det = r.determinant();
    cout << "The determinant of r is: " << det << endl;

    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // 11) Imprima:
    // a) Numero de filas de m3
    // b) Numero de columnas de m3
    // c) El elemento en la fila 2, columna 3

    cout << "11) Imprima: " << endl;
    cout << "a) Numero de filas de m3. " << endl;
    cout << "b) Numero de columnas de m3. " << endl;
    cout << "c) El elemento en la fila 2, columna 3. " << endl;

    cout << "m3: " << endl;
    cout << m3 << endl;
    cout << endl;

    // a)
    cout << "The Rows number of m3 is: " << m3.numberRows() << endl;
    cout << endl;

    // b)
    cout << "The Columns number of m3 is: " << m3.numberCols() << endl;
    cout << endl;

    // c)
    cout << "The element in row 2 and column 3 is: " << m3.access(2, 3) << endl;
    cout << endl;

    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    // Prueba de los operadores ////////////////////////////////////////////////
    cout << "======================================================================================================" << endl;
    cout << "OPERACIONES ENTRE MATRICES " << endl;
    cout << endl;

    vector<int> a3 = {9, -10, 5};
    vector<int> b3 = {5, 2, -6};
    vector<int> c3 = {-7, 45, 1};
    Cmatrix<int> m4;
    Cvector<int> d3;
    Cvector<int> e3;
    Cvector<int> f3;
    for(unsigned i = 0; i < a3.size(); i++){
        d3.push(a3[i]);
        e3.push(b3[i]);
        f3.push(c3[i]);
    }
    cout << "m4.push: "<< d3 << endl;
    m4.push(d3, 0);
    cout << "m4.push: "<< e3 << endl;
    m4.push(e3, 0);
    cout << "m4.push: "<< f3 << endl;
    m4.push(f3, 0);

    cout << "m4 : " << endl;
    cout << m4 << endl;
    cout << "m4.numberRows : " << m4.numberRows() << endl;
    cout << "m4.numberCols : " << m4.numberCols() << endl;

    cout << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    vector<int> a4 = {9, -10, 5};
    vector<int> b4 = {5, 2, -6};
    vector<int> c4 = {-7, 45, 1};
    Cmatrix<int> m5;
    Cvector<int> d4;
    Cvector<int> e4;
    Cvector<int> f4;
    for(unsigned i = 0; i < a4.size(); i++){
        d4.push(a4[i]);
        e4.push(b4[i]);
        f4.push(c4[i]);
    }


    m5.push(d4, 0);
    m5.push(e4, 0);
    m5.push(f4, 0);
    cout << "m5.push: " << d4 << endl;
    cout << "m5.push: " << e4 << endl;
    cout << "m5.push: " << f4 << endl;

    cout << "m5 : " << endl;
    cout << m5 << endl;
    cout << "m5.numberRows : " << m5.numberRows() << endl;
    cout << "m5.numberCols : " << m5.numberCols() << endl;

    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // Operator == and Operator !=
    cout << "m4 == m5: " << endl;
    Cmatrix<bool> m4igum5 = (m4 == m5);
    cout << m4igum5 << endl;

    cout << "m4 != m5: " << endl;
    Cmatrix<bool> m4dism5 = (m4 != m5);
    cout << m4dism5 << endl;

    m4.swap_r(0, 2);
    m5.swap_c(0, 2);

    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "m4.swap_r(0, 2). " << endl;
    cout << "m5.swap_c(0, 2). " << endl;
    cout << "DESPUES DE HACER SWAP EN M4 Y M5." << endl;
    cout << endl;

    cout << "m4 : " << endl;
    cout << m4 << endl;
    cout << "m4.numberRows : " << m4.numberRows() << endl;
    cout << "m4.numberCols : " << m4.numberCols() << endl;
    cout << endl;
    cout << "m5 : " << endl;
    cout << m5 << endl;
    cout << "m5.numberRows : " << m5.numberRows() << endl;
    cout << "m5.numberCols : " << m5.numberCols() << endl;

    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // Operator <= and Operator >=

    cout << "m4 <= m5: " << endl;
    Cmatrix<bool> m4meim5 = (m4 <= m5);
    cout << m4meim5 << endl;

    cout << "m4 >= m5: " << endl;
    Cmatrix<bool> m4maim5 = (m4 >= m5);
    cout << m4maim5 << endl;

    m5.swap_c(0, 2);
    cout << "m5.swap_c(0, 2). " << endl;
    cout << "DESPUES DE HACER SWAP EN M5." << endl;
    cout << endl;

    cout << "m5 : " << endl;
    cout << m5 << endl;

    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // Operator < and Operator >

    cout << "m4: " << endl;
    cout << m4 << endl;
    cout << "m4.numberRows: " << m4.numberRows() << endl;
    cout << "m4.numberCols: " << m4.numberCols() << endl;
    cout << endl;

    cout << "m5: " << endl;
    cout << m5 << endl;
    cout << "m5.numberRows: " << m5.numberRows() << endl;
    cout << "m5.numberCols: " << m5.numberCols() << endl;
    cout << endl;

    cout << "m4 < m5: " << endl;
    Cmatrix<bool> m4mem5 = (m4 < m5);
    cout << m4meim5 << endl;

    cout << "m4 > m5: " << endl;
    Cmatrix<bool> m4mam5 = (m4 > m5);
    cout << m4mam5 << endl;

    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // Operator + and Operator -

    cout << "m4: " << endl;
    cout << m4 << endl;
    cout << "m4.numberRows: " << m4.numberRows() << endl;
    cout << "m4.numberCols: " << m4.numberCols() << endl;
    cout << endl;

    cout << "m5: " << endl;
    cout << m5 << endl;
    cout << "m5.numberRows: " << m5.numberRows() << endl;
    cout << "m5.numberCols: " << m5.numberCols() << endl;
    cout << endl;

    Cmatrix<double> m4masm5 = m4 + m5;
    cout << "m4 + m5: " << endl;
    cout << m4masm5 << endl;

    Cmatrix<double> m4menm5 = m4 - m5;
    cout << "m4 - m5: " << endl;
    cout << m4menm5 << endl;

    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // Operator * scalar and Operator / scalar

    cout << "m4: " << endl;
    cout << m4 << endl;
    cout << "m4 * 3: " << endl;
    Cmatrix<double> m4x3 = m4 * 3;
    cout << m4x3 << endl;

    cout << "m4 / 2: " << endl;
    Cmatrix<double> m4d2 = m4 / 2;
    cout << m4d2 << endl;

    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // Operator Cmatrix ^ n

    cout << "m4: " << endl;
    cout << m4 << endl;
    Cmatrix<double> m4elev4 = m4 ^ size_t(4);
    cout << "m4 ^ 4: " << endl;
    cout <<  m4elev4 << endl;

    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


    // Operator Cmatrix * CVector, Operator Cvector * Cmatrix and Operator Cmatrix

    Cmatrix<double> o = r;
    cout << "o: " << endl;
    cout << o << endl;
    cout << "r: " << endl;
    cout << r << endl;
    Cvector<double> to;
    to.push(5);
    to.push(2);
    to.push(3);
    cout << "to: " << to << endl;
    cout << endl;

    Cmatrix<double> oXto = o * to;
    cout << "o * to: " << endl;
    cout << oXto << endl;

    Cmatrix<double> toXo = to * o;
    cout << "to * o: " << endl;
    cout << toXo << endl;

    Cmatrix<double> rXo = r * o;
    cout << "r * o: " << endl;
    cout << rXo << endl;

    Cmatrix<double> rele2 = r ^ 2;
    cout << "r ^ 2: " << endl;
    cout << rele2 << endl;

    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    // cout << "12) Halle la matriz inversa de m5. " << endl;
    // cout << "m5: " << endl;
    // cout << m5 << endl;
    // Cmatrix<double> m5inv = (m5.toDouble()).inverse();
    // cout << "Inverse of m5: " << endl;
    // cout << m5inv << endl;

    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "13) Halle la descomposicion QR de m5: " << endl;
    cout << "m5: " << endl;
    cout << m5 << endl;
    tuple<Cmatrix<double>, Cmatrix<double>> QRm5 = m5.QR();
    cout << "m5 = Q X R: " << endl;
    cout << "Q: " << endl;
    cout << get<0>(QRm5) << endl;
    cout << "R: " << endl;
    cout << get<1>(QRm5) << endl;

    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    // cout << "14) Halle la descomposicion LU de m5: " << endl;
    // cout << "m5: " << endl;
    // cout << m5 << endl;
    // tuple<Cvector<double>, Cmatrix<double>, Cmatrix<double>> LUm5 = m5.LUP(0.001);
    // cout << "m5 = P X L X U: " << endl;
    // cout << "P: " << get<0>(LUm5) << endl;
    // cout << "L: " << endl;
    // cout << get<1>(LUm5) << endl;
    // cout << "U: " << endl;
    // cout << get<2>(LUm5) << endl;

    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    // cout << "15) Halle los valores propios de m5: " << endl;
    // cout << "m5: " << endl;
    // cout << m5 << endl;
    // Cvector<double> vpm5 = m5.eigen_values(0.001);
    // cout << "Eigen Values of m5: " << vpm5 << endl;

    // Prueba de metodos basicos de Cmatrix ////////////////////////////////////
    cout << "======================================================================================================" << endl;
    cout << "METODOS DE LA CLASE MATRIZ" << endl;
    cout << endl;

    vector<int> a5 = {9, -10, 5, -30, 6};
    vector<int> b5 = {5, 2, -6, 4, 0};
    vector<int> c5 = {-7, 45, 1, -8, 4};
    vector<int> d5 = {5, 12, 3, 19, 22};
    Cmatrix<int> m6;
    Cvector<int> e5;
    Cvector<int> f5;
    Cvector<int> g5;
    Cvector<int> h5;
    for(unsigned i = 0; i < a5.size(); i++){
        e5.push(a5[i]);
        f5.push(b5[i]);
        g5.push(c5[i]);
        h5.push(d5[i]);
    }


    // push()
    m6.push(e5);
    m6.push(f5);
    m6.push(g5);
    m6.push(h5);
    cout << "m6.push: " << e5 << endl;
    cout << "m6.push: " << f5 << endl;
    cout << "m6.push: " << g5 << endl;
    cout << "m6.push: " << h5 << endl;


    cout << "m6: " << endl;
    cout << m6 << endl;
    cout << endl;


    // erase()
    cout << "m6.erase(3, row)" << endl;
    m6.erase(3, 0);
    cout << "m6: " << endl;
    cout << m6 << endl;
    cout << endl;

    cout << "m6.erase(3, col)" << endl;
    m6.erase(3, 1);
    cout << m6 << endl;


    // insert()
    cout << "m6.insert(3, [ 9 -10 6 ], col)" << endl;
    cout << "m6.numberRows: " << m6.numberRows() << endl;
    cout << "m6.numberCols: " << m6.numberCols() << endl;
    e5.erase(2);
    e5.erase(2);
    m6.insert(2, e5, 1);
    cout << endl;
    cout << "m6: " << endl;
    cout << m6 << endl;
    cout << endl;


    // clear()
    cout << "m6.clear()" << endl;
    m6.clear();
    cout << "m6: " << endl;
    cout << m6 << endl;


    // empty()
    cout << boolalpha << "m6 is empty?: " << m6.empty() << endl;
    cout << endl;

    m6.push(h5, 1);
    cout << "m6.push([ 5 12 3 19 22 ], col)" << endl;
    cout << "m6: " << endl;
    cout << m6 << endl;


    // empty()
    cout << boolalpha << "m6 is empty?: " << m6.empty() << endl;

    cout << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
}
