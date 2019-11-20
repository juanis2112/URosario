#ifndef _queue_hpp_
#define _queue_hpp_

#include<iostream>
using namespace std;

template<typename dataType>
class Queue{
private:
    static const int INITIAL_CAPACITY = 10;
    dataType *array;
    int capacity, head, tail;
    void expandCapacity();
    void deepCopy (const Queue<dataType> & src);
    
public:
    Queue();
    Queue(const Queue<dataType> & src);
    ~Queue();
    int size();
    bool empty();
    void clear();
    void enqueue (dataType &ch);
    dataType dequeue ();
    dataType back();
    dataType front();
    Queue<dataType> operator=(const Queue<dataType> &src);
};

#include "queue.cpp"
#endif //_queue_hpp_

