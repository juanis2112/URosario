//
//  queue.cpp
//  Queue
//
//  Created by Juanita Gomez on 4/10/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#ifdef _queue_hpp_


template<typename dataType>
Queue<dataType>::Queue(){
    capacity = INITIAL_CAPACITY;
    array = new dataType[INITIAL_CAPACITY];
    head = 0;
    tail = 0;
}

template<typename dataType>
Queue<dataType>::~Queue(){
    head = 0;
    tail = 0;
    delete[]array;
}

template<typename dataType>
int Queue<dataType>::size(){
    if (head<=tail) return tail-head;
    else return capacity-(head-tail);
}

template<typename dataType>
bool Queue<dataType>::empty(){
    return(head==tail);

}

template<typename dataType>
void Queue<dataType>::clear(){
    while(head!=tail) dequeue();
}
    
    
template<typename dataType>
void Queue<dataType>::enqueue(dataType &ch){
    if((head==0 && tail==capacity) || (head-tail==1)) expandCapacity();
    if(head!=0 && tail== capacity) tail = tail%capacity;
    array[tail]=ch;
    tail++;
}

template<typename dataType>
dataType Queue<dataType>::dequeue(){
    dataType result = array[head];
    head++;
    return result;
}

template<typename dataType>
dataType Queue<dataType>::back(){
    return array[tail-1];
}


template<typename dataType>
dataType Queue<dataType>::front(){
    return array[head];
}

template<typename dataType>
void Queue<dataType>::expandCapacity(){
    dataType *oldArray = array;
    capacity = 2*capacity;
    array = new dataType[capacity];
    if (head<tail){
        for (int i=0; i<=tail; i++) array[i] = oldArray[i];
    }
    else {
        for (int i=head; i<capacity/2; i++) array[i-head] = oldArray[i];
        for (int i=0; i<tail; i++ ) array[i+(capacity/2)-head] = oldArray[i];
        
    }
    delete[]oldArray;
}

template<typename dataType>
void Queue<dataType>::deepCopy(const Queue<dataType> & src){
    array = new dataType[src.capacity];
    if (head<tail){
        for (int i=0; i<=tail; i++) array[i] = src.array[i];
    }
    else {
        for (int i=head; i<src.capacity; i++) array[i-head] = src.array[i];
        for (int i=0; i<tail; i++ ) array[i+(src.capacity)-head] = src.array[i];
    }
}

template<typename dataType>
Queue<dataType>::Queue(const Queue<dataType> & src){
    capacity = src.capacity;
    head = src.head;
    tail = src.tail;
    array = new dataType[capacity];
    deepCopy(src);
}
template<typename dataType>
Queue<dataType> Queue<dataType>::operator=(const Queue<dataType> & src){
    dataType *oldArray = this -> array;
    this->capacity = src.capacity;
    this->head = src.head;
    this->tail = src.tail;
    this->array = new dataType[capacity];
    deepCopy(src);
    delete[]oldArray;
    return *this;
}


#endif
