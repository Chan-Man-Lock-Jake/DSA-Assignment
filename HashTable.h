    #pragma once
#include <iostream>
using namespace std;

const int TABLE_SIZE = 100; // Define hash table size

// Templated linked list node for storing pointers to T (Actor/Movie)
template <typename T>
struct ListNode {
    T* itemPtr;     // Pointer to an Actor or Movie object
    ListNode* next; // Pointer to the next node
	//ListNode<T>* next; TODO: Uncomment this line and comment the line above

    ListNode(T* item) : itemPtr(item), next(nullptr) {}
};

// Templated Hash Table
template <typename T>
class HashTable {
private:
    ListNode<T>** table;  // Array of linked list pointers
    int hashFunction(int key); // Hash function
	int TABLE_SIZE; // Size of the hash table

public:
    HashTable();   // Constructor
    HashTable(int size);
    ~HashTable();  // Destructor

    void insert(T* item, int key);  // Insert an item pointer
    ListNode<T>* search(int key);   // Search by key (year)
    void remove(int key, T* item);  // Remove a specific item
    void display();                 // Display all items
};
