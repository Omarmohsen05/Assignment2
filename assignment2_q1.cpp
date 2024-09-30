#include "assignment2_q1.h"

// Constructor for the linked list
Single_Linked_List::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor to free memory
Single_Linked_List::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

// Add an item to the front of the list
void Single_Linked_List::push_front(int item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    num_items++;
}

// Add an item to the back of the list
void Single_Linked_List::push_back(int item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

// Remove the first item
bool Single_Linked_List::pop_front() {
    if (empty()) return false;
    Node* temp = head;
    head = head->next;
    delete temp;
    num_items--;
    if (num_items == 0) {
        tail = nullptr;
    }
    return true;
}

// Remove the last item
bool Single_Linked_List::pop_back() {
    if (empty()) return false;
    if (num_items == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
    return true;
}

// Get the first item
int Single_Linked_List::front() const {
    return head ? head->data : -1;  // return -1 if empty
}

// Get the last item
int Single_Linked_List::back() const {
    return tail ? tail->data : -1;  // return -1 if empty
}

// Check if the list is empty
bool Single_Linked_List::empty() const {
    return num_items == 0;
}

// Insert an item at a specific index
void Single_Linked_List::insert(size_t index, int item) {
    if (index >= num_items) {
        push_back(item);
    } else if (index == 0) {
        push_front(item);
    } else {
        Node* new_node = new Node(item);
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        num_items++;
    }
}

// Remove an item at a specific index
bool Single_Linked_List::remove(size_t index) {
    if (index >= num_items) return false;
    if (index == 0) return pop_front();
    Node* current = head;
    for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    num_items--;
    if (index == num_items - 1) {
        tail = current;
    }
    return true;
}

// Find the position of an item
size_t Single_Linked_List::find(int item) const {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;  // return size if not found
}

// Get the size of the list
size_t Single_Linked_List::size() const {
    return num_items;
}

// Main function to test the implementation
int main() {
    Single_Linked_List list;
    int option, value, index;

    do {
        std::cout << "\n1. Push to front of list\n2. Push to back of list\n3. Pop from front\n4. Pop from back\n5. Display front\n6. Display back\n7. Insert at index\n8. Remove at index\n9. Find element\n10. Exit\nChoose an option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "Enter value to push to front: ";
                std::cin >> value;
                list.push_front(value);
                std::cout << "Pushed " << value << " to the front of the list.\n";
                break;
            case 2:
                std::cout << "Enter value to push to back: ";
                std::cin >> value;
                list.push_back(value);
                std::cout << "Pushed " << value << " to the back of the list.\n";
                break;
            case 3:
                if (list.pop_front()) {
                    std::cout << "Popped from the front of the list.\n";
                } else {
                    std::cout << "List is empty!\n";
                }
                break;
            case 4:
                if (list.pop_back()) {
                    std::cout << "Popped from the back of the list.\n";
                } else {
                    std::cout << "List is empty!\n";
                }
                break;
            case 5:
                std::cout << "Front of list: " << list.front() << "\n";
                break;
            case 6:
                std::cout << "Back of list: " << list.back() << "\n";
                break;
            case 7:
                std::cout << "Enter index to insert at: ";
                std::cin >> index;
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                list.insert(index, value);
                std::cout << "Inserted " << value << " at index " << index << ".\n";
                break;
            case 8:
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                if (list.remove(index)) {
                    std::cout << "Removed element at index " << index << ".\n";
                } else {
                    std::cout << "Invalid index!\n";
                }
                break;
            case 9:
                std::cout << "Enter value to find: ";
                std::cin >> value;
                index = list.find(value);
                if (index != list.size()) {
                    std::cout << "Found " << value << " at index " << index << ".\n";
                } else {
                    std::cout << "Value not found!\n";
                }
                break;
            case 10:
                std::cout << "Exiting\n";
                break;
            default:
                std::cout << "Invalid option!\n";
        }
    } while (option != 10);

    return 0;
}
