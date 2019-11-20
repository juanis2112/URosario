//
//  main.cpp
//  Taller10
//
//  Created by Juanita Gomez on 3/31/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#include <iostream>
using namespace std;


template <typename dataType >
class Stack {
private:
    struct Cell {
        /* Type for linked list cell */
        dataType data;
        Cell *link;
        };

    Cell *stack;
    int count;

    void deepCopy(const Stack <dataType > & src);
    
public:
    Stack();
    ~Stack();
    int size();
    bool empty();
    void clear();
    void push(dataType & ch);
    dataType pop();
    dataType peek();
    };

//...........//

template <typename dataType >
void Stack<dataType>::deepCopy(const Stack <dataType> & src){
    Cell *aux = src;
    this = new Cell;
    Cell *aux2 = this;
    while (aux != nullptr){
        aux2 -> data =  aux-> data;
        aux = aux->link;
        aux2 -> link = new Cell;
        aux2 = aux2->link;
        
    }
    *aux2 = nullptr;
}

template <typename dataType >
Stack<dataType>::Stack(){
    count=0;
    stack= nullptr;
}
template <typename dataType >
Stack<dataType>::~Stack(){
    clear();
    delete stack;
};
template <typename dataType >
int Stack<dataType>::size(){
    return count;
    
}
template <typename dataType >
bool Stack<dataType>::empty(){
    return(count==0);
    
}
template <typename dataType >
void Stack<dataType>::clear(){
    while (count>0) pop();
}

template <typename dataType >
void Stack<dataType>::push(dataType & ch){

    Cell *aux= stack;
    stack = new Cell;
    stack-> data = ch;
    stack-> link = aux;
    count++;
    
}

template <typename dataType >
dataType Stack<dataType>::pop(){
    
    Cell *erase = stack;
    stack = erase->link;
    dataType result = erase->data;
    delete erase;
    count--;
    return result;
}

template <typename dataType >
dataType Stack<dataType>::peek(){
    dataType r  = stack -> data;
    return r;
}


int main(){
    Stack<int>p;
    cout << p.size();
    cout << p.size();
    return 0;
    
}


