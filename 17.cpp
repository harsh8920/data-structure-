#include <iostream>
using namespace std;

// Define a struct for a linked list node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete the last node from the linked list
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "The list is empty. Deletion is not possible." << endl;
        return;
    }
    
    if (head->next == nullptr) {
        // If there's only one node, delete it.
        delete head;
        head = nullptr;
    } else {
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << std::endl;
}

int main() {
    Node* head = nullptr; // Initialize an empty linked list

    // Insert elements at the end
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);

    cout << "Linked List after insertions:" << endl;
    printList(head);

    // Delete the last element
    deleteAtEnd(head);

    cout << "Linked List after deletion:" << endl;
    printList(head);

    return 0;
}
