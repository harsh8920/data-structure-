#include <iostream>
using namespace std;
// Define a struct for a linked list node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to search for a value in the linked list
bool searchValue(const Node* head, int value) {
    const Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true; // Value found
        }
        current = current->next;
    }
    return false; // Value not found
}

// Function to print the linked list
void printList(const Node* head) {
    const Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr; // Initialize an empty linked list

    // Insert elements into the linked
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Linked List:" <<endl;
    printList(head);

    // Search for a value in the linked list
    int Value = 3;
    if (searchValue(head, Value)) {
    cout << "Value " << searchValue << " found in the linked list." <<endl;
    } else {
    cout << "Value " << searchValue << " not found in the linked list." <<endl;
    }

    return 0;
}
