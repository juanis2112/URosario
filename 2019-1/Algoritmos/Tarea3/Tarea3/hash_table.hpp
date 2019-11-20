// Santiago Lopez
// Juanita Gomez

#ifndef _hash_table_hpp_
#define _hash_table_hpp_

#include<iostream>
#include<vector>

using namespace std;

template <typename dataType > class hashFunction;

template <typename data_type>
class hash_table{
    
private:
    
    enum bucket_type {Active=0, Empty=1, Deleted=2};
    
    struct bucket{
        data_type elem; // actual key
        bucket_type info; // bucket status
        bucket (const data_type &e, bucket_type i = Empty){
            info = i;
            elem = e;
        }
    };
    
    unsigned n_buckets; // table size
    vector<bucket> array; // size: n_buckets
    unsigned count; // number of Active elements
    
    void rehash();
    unsigned hashing (const data_type &x) const;
    void checkrep() const;
    
public:
    
    hash_table();  // creates table w/101 elements
    ~hash_table(); // frees allocated resources
    void empty(); // clears content of table
    
    int insert (const data_type &x);
    int search (const data_type &x) const;
    int remove (const data_type &x);
    
    void display();
    
};



#include "hash_table.cpp"
#endif // _hash_table_hpp_


