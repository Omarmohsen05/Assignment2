#ifndef ASSIGNMENT2_Q1_H
#define ASSIGNMENT2_Q1_H

#include <iostream>

// Single Linked List Class Definition
class Single_Linked_List {
private:
    // Node structure for each element
    struct Node {
        int data;      // data part of the node
        Node* next;    // pointer to the next node
        Node(int val) : data(val), next(nullptr) {}  // constructor
    };

    Node* head;  // points to the first node
    Node* tail;  // points to the last node
    size_t num_items;  // keeps track of the number of nodes

public:
    // Constructor and Destructor
    Single_Linked_List();
    ~Single_Linked_List();

    // List operations
    void push_front(int item);    // Add to the front
    void push_back(int item);     // Add to the back
    bool pop_front();             // Remove from the front
    bool pop_back();              // Remove from the back
    int front() const;            // Access the first element
    int back() const;             // Access the last element
    bool empty() const;           // Check if list is empty
    void insert(size_t index, int item); // Insert at a specific index
    bool remove(size_t index);           // Remove from a specific index
    size_t find(int item) const;   // Find an item in the list
    size_t size() const;           // Return the number of items
};

#endif
