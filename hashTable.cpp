#include "HashTable.h"
#include "Actor.h"
#include "Movie.h"

// Constructor: Initialize hash table
template <typename T>
HashTable<T>::HashTable() {
    table = new ListNode<T>*[TABLE_SIZE]();  // Initialize array with nullptr
}

template <typename T>
HashTable<T>::HashTable(int size) {
    TABLE_SIZE = size;  // Set table size dynamically
    table = new ListNode<T>*[TABLE_SIZE]();  // Initialize array with nullptr
}

// Hash function: Maps year to an index
template <typename T>
int HashTable<T>::hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert an item pointer into the hash table
template <typename T>
void HashTable<T>::insert(T* item, int key) {
    int index = hashFunction(key);
    ListNode<T>* newNode = new ListNode<T>(item);

    // Insert at the beginning of the linked list (Chaining)
    if (table[index] == nullptr) {
        table[index] = newNode;
    }
    else {
        newNode->next = table[index];
        table[index] = newNode;
    }
}

// Search for items by key (year)
template <typename T>
ListNode<T>* HashTable<T>::search(int key) {
    int index = hashFunction(key);
    return table[index];  // Return head of linked list (if exists)
}

// Remove a specific item from the hash table
template <typename T>
void HashTable<T>::remove(int key, T* item) {
    int index = hashFunction(key);
    ListNode<T>* current = table[index];
    ListNode<T>* prev = nullptr;

    while (current) {
        if (current->itemPtr == item) {
            if (prev) {
                prev->next = current->next;
            }
            else {
                table[index] = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Display all items in the hash table
template <typename T>
void HashTable<T>::display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i]) {
            cout << "Year " << i << ": ";
            ListNode<T>* current = table[i];
            while (current) {
                cout << "[" << current->itemPtr->name << " (ID: " << current->itemPtr->id << ")] -> ";
                current = current->next;
            }
            cout << "nullptr\n";
        }
    }
}

// Destructor: Clean up memory
template <typename T>
HashTable<T>::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ListNode<T>* current = table[i];
        while (current) {
            ListNode<T>* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
    delete[] table;
}
template class HashTable<Actor>;
template class HashTable<Movie>;
