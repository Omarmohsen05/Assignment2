#include "assignment2_q2.h"

// Push a value onto the stack
void Stack::push(int value) {
    stack_data.push_back(value);
}

// Pop a value from the stack
void Stack::pop() {
    if (!stack_data.empty()) {
        stack_data.pop_back();
    } else {
        std::cout << "Stack is empty, nothing to pop.\n";
    }
}

// Get the top element of the stack
int Stack::top() const {
    if (!stack_data.empty()) {
        return stack_data.back();
    }
    return -1;  // return -1 if the stack is empty
}

// Check if the stack is empty
bool Stack::is_empty() const {
    return stack_data.empty();
}

// Calculate the average of stack elements
double Stack::average() const {
    if (stack_data.empty()) return 0.0;
    int sum = 0;
    for (int val : stack_data) {
        sum += val;
    }
    return static_cast<double>(sum) / stack_data.size();
}

// Main function to test the stack implementation
int main() {
    Stack stack;
    int option, value;

    do {
        std::cout << "\n1. Push to stack\n2. Pop from stack\n3. Display top element\n4. Calculate average\n5. Exit\nChoose an option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                stack.push(value);
                std::cout << "Pushed " << value << " onto the stack.\n";
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                std::cout << "Top of stack: " << stack.top() << "\n";
                break;
            case 4:
                std::cout << "Average of stack: " << stack.average() << "\n";
                break;
            case 5:
                std::cout << "Exiting\n";
                break;
            default:
                std::cout << "Invalid option!\n";
        }
    } while (option != 5);

    return 0;
}
