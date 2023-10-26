#include <iostream>
using namespace std;
// Define a struct for a linked list node
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Function to delete the first node from the linked list
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "The list is empty. Deletion is not possible." << std::endl;
        return;
    }
    
    Node* temp = head;
    head = head->next;
    delete temp;
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

    // Insert elements at the beginning
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);

    std::cout << "Linked List after insertions:" << std::endl;
    printList(head);

    // Delete the first element
    deleteAtBeginning(head);

    cout << "Linked List after deletion:" << std::endl;
    printList(head);

    return 0;
}
