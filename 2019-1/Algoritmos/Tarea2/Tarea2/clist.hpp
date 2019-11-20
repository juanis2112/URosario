// clist.hpp
// Tarea2
// Por Juanita Gomez y David Santiago Lopez


#ifndef _clist_hpp_
#define _clist_hpp_

#include <iostream>
#include <cassert>

using namespace std;

template <typename dataType >
class Clist {
public:
    Clist();
    ~Clist();
    
    dataType & back() const;
    dataType & front() const;
    
    void insert(dataType item);
    void remove();
    void advance();
    
    unsigned size() const;
    bool empty() const;
    void clear();

private:
    void checkrep() const;
    struct Node {
        dataType data;
        Node *link;
        Node(dataType & d, Node *next = nullptr){
            data = d;
            link = next;
            }
    };
    
    Node *cursor;
    unsigned count;
    
};
#include "clist.cpp"
#endif /* _clist_hpp */
