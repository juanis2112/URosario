// Tarea 1 Algoritmos y Estructuras de Datos
// Juanita Gómez y David Santiago Moreno

#include <iostream>
#include "simple_vector.hpp"
using namespace std;

int main()
{
    simple_vector vec;

    for (int i = -10; i < +10; i += 2) vec.push(static_cast<double>(i));
    cout << vec << endl;
    
    auto iter = vec.size() / 2;
    
    for (int i = 0; i < iter; i++) vec.erase(i);
    cout << vec << endl;
    
    for (int i = 0; i < 2 * iter; i++) vec.insert(2 * i, i);
    cout << vec << endl;
    
    for (int i = 0; i < vec.size(); i += 2) {
        auto data = vec.retrieve(i);
        vec.modify(i, data + 0.1);
    }
    cout << vec << endl;
    
    simple_vector vac(vec), vic;
    cout << vac << endl;
    
    vic = vac;
    cout << vic << endl;
    
    vec = vac;
    cout << vec << endl;
    
    vac.clear();
    cout << vac << endl;
    
    return 0;
}
