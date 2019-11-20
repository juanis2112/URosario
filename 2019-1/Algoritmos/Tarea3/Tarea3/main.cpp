#include <iostream>
#include <random>
#include "hash_table.hpp"
using namespace std;

template <>
class hashFunction<int> {
    public:
        size_t operator()(const int & key) {
        return static_cast <size_t>(key);
        }
    };


int main(){
    
    const int min = -15, max = +15;
    random_device rd;
    default_random_engine generator{rd()};
    uniform_int_distribution<int> distribution(min, max);
    
    hash_table<int> ht;
    
    for(int i = 0; i < max; i++){
        int key = distribution(generator);
        ht.insert(key);
        cout << "Insert: " << key << endl;
    }
    ht.display();
    cout << endl;
    
    for(int key = min; key < max; key++){
        cout << "Find: " << key << " " << ht.search(key) << endl;
    }
    cout << endl;
    for(int i = min; i < max; i++){
        int key = distribution(generator);
        cout << "Remove: " << key << " " << ht.remove(key) << endl;
    }
    cout << endl;
    for(int key = min; key < max; key++){
        cout << "Find: " << key << " " << ht.search(key) << endl;
    }
    
    ht.display();
    
    return 0;
    
}
