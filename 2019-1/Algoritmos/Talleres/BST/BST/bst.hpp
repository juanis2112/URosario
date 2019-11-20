//
//  bst.hpp
//  BST
//
//  Created by Juanita Gomez on 5/23/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#ifndef bst_hpp
#define bst_hpp
#include <iostream>
#include<typeinfo>
#include<string>
#include <list>
#include <algorithm>
using namespace std;

template <typename keyType >
class bst {
    struct bstNode {
        keyType key;
        bstNode *left;
        bstNode *right;
        bstNode *parent;
        };

    size_t count;
    bstNode *tree;
    
    bstNode * min(bstNode *root) const;
    bstNode * max(bstNode *root) const;
    bstNode * successor(bstNode *root) const;
    bstNode * predecessor(bstNode *root) const;
    
    void remove(bstNode * &root, keyType key);
    bstNode * copy(bstNode *root) const;
    void clear(bstNode * &root);
    void display(bstNode *root, ostream &out) const;
    void insert(bstNode * &root, keyType key);
    bstNode * find(bstNode *root, keyType key) const;
    
    public:
    bst();
    bst(const bst &rhs);
    ~bst();
    
    void remove(keyType key);
    bool empty(void) const;
    void clear(void);
    bool find(keyType key) const;
    void insert(keyType key);
    void display(ostream &out = cout) const;
    };


#include <stdio.h>
#include "bst.cpp"

#endif /* bst_hpp */
