//
//  bst.cpp
//  BST
//
//  Created by Juanita Gomez on 5/23/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#ifdef _bst_hpp_

// Emtpy Constuctor
template <typename data_type>
bst<data_type>::bst(){
    count = 0;
    tree = nullptr; // Pointer??
    
}

// Copy Constructor
template <typename data_type>
bst<data_type>::bst(const bst &rhs){
    count = rhs->count;
    tree = copy(tree);
    
}

// Destructor
template <typename data_type>
bst<data_type>::~bst(){
    clear();
    delete tree;
    
}

// ---------------------------------------------------------------
template <typename data_type>
typename bst<data_type>::bstNode * bst<data_type> min(bst<data_type> bstNode *root) const{
    if(root == nullptr ) return nullptr;
    else if (root->left == nullptr) return root;
    else{
        return min(roor->left);
    }
}

template <typename data_type>
typename bst<data_type>::bstNode * bst<data_type> max(bst<data_type> bstNode *root) const{
    if(root == nullptr ) return nullptr;
    else if (root->right == nullptr) return root;
    else{
        return min(root->right);
    }
}

template <typename data_type>
bst<data_type>::bstNode * successor(bstNode *root) const{
    if(root == nullptr ) return nullptr;
    else if (root->right == nullptr) return nullptr;
    else{
        return min(root->right)
    }
    
    
}
template <typename data_type>
bst<data_type>::bstNode * predecessor(bstNode *root) const{
    if(root == nullptr ) return nullptr;
    else if (root->left == nullptr) return nullptr;
    else{
        return min(root->left)
    }
}

// ----------------------------------------------------------------

template <typename data_type>
bst<data_type>::remove(bstNode * &root, keyType key){
    
}

template <typename data_type>
void bst<data_type>::bstNode * copy(bstNode *root){
    
}

template <typename data_type>
void bst<data_type>::clear(bstNode * &root){
    
}

void display(bstNode *root, ostream &out) const;
void insert(bstNode * &root, keyType key);
bstNode * find(bstNode *root, keyType key) const;


#endif
