#ifndef ASSIGNMENT2_Q2_H
#define ASSIGNMENT2_Q2_H

#include <iostream>
#include <vector>

// Stack implementation using a vector
class Stack {
private:
    std::vector<int> stack_data;

public:
    void push(int value);       // Push value onto the stack
    void pop();                 // Pop value from the stack
    int top() const;            // Get the top element
    bool is_empty() const;      // Check if the stack is empty
    double average() const;     // Calculate the average of the stack
};

#endif
