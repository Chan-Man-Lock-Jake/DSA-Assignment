#pragma once
#include "BinaryNode.h"

template <typename T> 
class AVLBST
{
private:
    BinaryNode<T>* root;
public:
    AVLBST();

    BinaryNode<T>* search(ItemType key);
    BinaryNode<T>* search(BinaryNode<T>* root, ItemType key);

    void insert(ItemType key, T value);
    void insert(BinaryNode<T>* &root, ItemType key, T value);

    void remove(ItemType key);
    void remove(BinaryNode<T>* &root, ItemType key);

    void inorder();
    void inorder(BinaryNode<T>* root);

    int getheight(BinaryNode<T>* root);

    int getbalance(BinaryNode<T>* root);

    BinaryNode<T>* leftRotate(BinaryNode<T>* &root);
    BinaryNode<T>* rightRotate(BinaryNode<T>* &root);
};

#include "AVLBST.tpp"
