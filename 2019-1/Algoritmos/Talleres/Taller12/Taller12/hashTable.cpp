
//  hashTable.cpp
//  Taller12
//
//  Created by Juanita Gomez on 4/18/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//





// Hash function

//template <typename dataType>
//class hashFunction{
//public:
//    size_t operator()(dataType & data){
//        size_t code = 0;
//        for(const auto &ch : data) code += ch;
//        return code;
//    }
//
//};

//template <typename dataType>
//class hashFunction{
//public:
//    size_t operator()(dataType & data){
//        size_t code = 0;
//        code = (int)data;
//        return code;
//};


// Hashing






#ifdef _hashTable_hpp_


 // Hash function


template <typename dataType>
size_t hashTable<dataType>::hashing(const dataType &data){
    hashFunction<dataType> hashFunctor;
    return hashFunctor(data) % nBuckets;
    }


template <typename dataType>
hashTable<dataType>::hashTable(){
    nBuckets = PRIME_INITIAL_DIMENSION;
    count = 0;
    table = new list<dataType> [nBuckets];
    }

template <typename dataType>
hashTable<dataType>::~hashTable(){
    clear();
    // DELETE????
    delete[] table;
}
    
template <typename dataType>
bool hashTable<dataType>::find(const dataType & data) {
    
    size_t bucket = hashing(data) % nBuckets;
    if (table[bucket].size() == 0) return false;
    for (auto it = table[bucket].begin(); it != table[bucket].end(); it ++){
            if (*it == data) return true;
    }
    return false;
}

template <typename dataType>
bool hashTable<dataType>::insert (const dataType & data) {
    if(find(data)) return false;
    if(load_factor() >= 0.7) rehash();
    size_t bucket = hashing(data) % nBuckets;
    table[bucket].push_front(data);
    count ++;
    return true;
}

template <typename dataType>
bool hashTable<dataType>::remove (const dataType & data) {
    size_t bucket = hashing(data) % nBuckets;
    for (auto it = table[bucket].begin(); it != table[bucket].end(); it ++){
            if (*it == data) {
                table[bucket].erase(it);
                count--;
                return true;
            }
        }
    return false;
}
template <typename dataType>
void hashTable<dataType>::clear() {
    for (int i=0; i< nBuckets; i++){
        table[i].clear();
        }
    count = 0;

}
template <typename dataType>
float hashTable<dataType>::load_factor() const{
    return float(float(count)/float(nBuckets));
}

template <typename dataType>
float hashTable<dataType>:: ret_max_load_factor() const{
    return max_load_factor;
}

template <typename dataType>
void hashTable<dataType>::rehash(){
    list<dataType> *old = table;
    nBuckets*=2;
    count = 0;
    table = new list<dataType>[nBuckets];
    for(int i=0; i<nBuckets/2; i++){
        while (old[i].size() > 0) {
            this -> insert(*(old[i].begin()));
            old[i].pop_front();
        }
    }
    delete [] old;
}


template <typename dataType>
void hashTable<dataType>::display(){
    for (size_t i = 0; i < nBuckets; i++){
        cout << "Elements of " << i << " position in the table: " << endl;
        if (table[i].size() == 0){
            cout << "None" << endl;
            continue;
            }
        for (auto it = table[i].begin(); it != table[i].end(); it++){
            cout << *it << endl;
            }
        }
    }

#endif
