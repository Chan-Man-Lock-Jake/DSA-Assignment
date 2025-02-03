#include <iostream>
#include "AVLBST.h"
#include "Actor.h"
#include "Movie.h"

template <typename T>
AVLBST<T>::AVLBST()
{
    root = nullptr;
}

template <typename T>
BinaryNode<T>* AVLBST<T>::search(ItemType key)
{
    return search(root, key);
}
template <typename T>
BinaryNode<T>* AVLBST<T>::search(BinaryNode<T>* root, ItemType key)
{
    if (root == nullptr || root->key == key) return root == nullptr ? nullptr : root;
    // DOES NOT ACCOUNT FOR DUPLICATE VALUE
    return search(key < root->key ? root->left : root->right, key); // If target is less than root, left subtree, else right subtree
}

template <typename T>
void AVLBST<T>::insert(ItemType key, T value)
{
    insert(root, key, value);
}
template <typename T>
void AVLBST<T>::insert(BinaryNode<T>*& root, ItemType key, T value)
{
    if (root == nullptr) {
        root = new BinaryNode<T>(key, value);
        return;
    }
    // DOES NOT ACCOUNT FOR DUPLICATE VALUE
    insert(key < root->key ? root->left : root->right, key, value); // If target is less than root, left subtree, else right subtree
    root->height = 1 + std::max(getheight(root->left), getheight(root->right)); // Update the height attribute of each node that was traversed

    int balance = getbalance(root);


    if (balance < -1) { // Tree is right heavy
        if (getbalance(root->right) >= 1) { // Right sub-tree is left heavy
            rightRotate(root->right);
        }
        leftRotate(root);
    }
    if (balance > 1) { // Tree is left heavy
        if (getbalance(root->left) <= -1) { // Left sub-tree is right heavy
            leftRotate(root->left);
        }
        rightRotate(root);
    }
}

template <typename T>
void AVLBST<T>::remove(ItemType key)
{
    remove(root, key);
}
template <typename T>
void AVLBST<T>::remove(BinaryNode<T>*& root, ItemType key)
{
    if (root == nullptr) return; // Cannot find target
    if (root->key == key) {
        if (root->left == nullptr && root->right == nullptr) { // Root has no children
            BinaryNode<T>* deleteRoot = root;
            root = nullptr;
            delete deleteRoot;
            return;
        }
        else if (!(root->left != nullptr && root->right != nullptr)) { // Root has one child
            BinaryNode<T>* deleteRoot = root;
            root = root->left == nullptr ? root->right : root->left; // If left is null, root is right, else root is left
            delete deleteRoot;
            return;
        }
        else {
            BinaryNode<T>* predecessor = root->left;
            while (predecessor->right != nullptr) { // Find next smaller value
                predecessor = predecessor->right;
            }
            ItemType tempKey = predecessor->key;
            T tempValue = predecessor->value;
            remove(root->left, tempKey);
            root->key = tempKey;
            root->value = tempValue;
        }
    }
    // DOES NOT ACCOUNT FOR DUPLICATE VALUE
    remove(key < root->key ? root->left : root->right, key); // If target is less than root, left subtree, else right subtree   
    root->height = 1 + std::max(getheight(root->left), getheight(root->right)); // Update the height attribute of each node that was traversed

    int balance = getbalance(root);


    if (balance < -1) { // Tree is right heavy
        if (getbalance(root->right) >= 1) { // Right sub-tree is left heavy
            rightRotate(root->right);
        }
        leftRotate(root);
    }
    if (balance > 1) { // Tree is left heavy
        if (getbalance(root->left) <= -1) { // Left sub-tree is right heavy
            leftRotate(root->left);
        }
        rightRotate(root);
    }
}

template <typename T>
void AVLBST<T>::inorder()
{
    inorder(root);
}
template <typename T>
void AVLBST<T>::inorder(BinaryNode<T>* root)
{
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->height << " ";
    inorder(root->right);
}

template <typename T>
int AVLBST<T>::getheight(BinaryNode<T>* root)
{
    return root == nullptr ? 0 : root->height;
}

template <typename T>
int AVLBST<T>::getbalance(BinaryNode<T>* root)
{
    return root == nullptr ? 0 : getheight(root->left) - getheight(root->right);
}

template <typename T>
BinaryNode<T>* AVLBST<T>::leftRotate(BinaryNode<T>*& root)
{
    BinaryNode<T>* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = temp;

    root->left->height = 1 + std::max(getheight(root->left->left), getheight(root->left->right));
    root->height = 1 + std::max(getheight(root->left), getheight(root->right));

    return root;
}
template <typename T>
BinaryNode<T>* AVLBST<T>::rightRotate(BinaryNode<T>*& root)
{
    BinaryNode<T>* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = temp;

    root->right->height = 1 + std::max(getheight(root->right->left), getheight(root->right->right));
    root->height = 1 + std::max(getheight(root->left), getheight(root->right));

    return root;
}

unsigned long hashString(const std::string& str) {
    unsigned long hash = 5381; // Initial hash value
    for (char c : str) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}
template class AVLBST<Actor>;
template class AVLBST<Movie>;