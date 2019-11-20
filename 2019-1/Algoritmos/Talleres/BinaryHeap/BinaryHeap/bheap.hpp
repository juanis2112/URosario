#ifndef _bheap_hpp_
#define _bheap_hpp_
#include <vector>
#include <iostream>
#include <cassert>


using namespace std;

template <typename dataType>
class BinaryHeap{
public:
    BinaryHeap (int capacity = 100);
    BinaryHeap (const vector <dataType> &vec);
    
    const dataType & findMin () const;
    void insert (const dataType &elem);
    void deleteMin ();
    
    bool isEmpty () const;
    void clear ();
    void display () const;
    
private:
    unsigned int count;
    vector<dataType> array;
    void percolateDown (int hole);
    void percolateUp (int hole);
    void checkrep() const;
    
};

#include "bheap.cpp"
#endif // _bheap_hpp_
