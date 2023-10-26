#include <iostream>
using namespace std;
// Define a struct for a linked list node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a new node at a specified position in the linked list
void insertAtPosition(Node*& head, int data, int position) {
    if (position < 0) {
        std::cerr << "Invalid position for insertion." << std::endl;
        return;
    }
    
    Node* newNode = new Node(data);
    
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            std::cerr << "Invalid position for insertion." << std::endl;
            delete newNode;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to delete a node at a specified position in the linked list
void deleteAtPosition(Node*& head, int position) {
    if (position < 0) {
        std::cerr << "Invalid position for deletion." << std::endl;
        return;
    }

    if (position == 0) {
        if (head == nullptr) {
            std::cerr << "List is empty. Deletion is not possible." << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) {
            std::cerr << "Invalid position for deletion." << std::endl;
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
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

    // Insert elements at various positions
    insertAtPosition(head, 1, 0); // Insert 1 at the beginning
    insertAtPosition(head, 3, 1); // Insert 3 after 1
    insertAtPosition(head, 2, 1); // Insert 2 between 1 and 3

    cout << "Linked List after insertions:" << endl;
    printList(head);

    // Delete a node at a specific position
    deleteAtPosition(head, 1); // Delete the node at position 1

    cout << "Linked List after deletion:" << endl;
    printList(head);

    return 0;
}
