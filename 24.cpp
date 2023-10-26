#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a new node at the end of the doubly linked list
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            // If the list is empty, make the new node the head and tail.
            head = tail = newNode;
        } else {
            // Append the new node to the end of the list.
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to display the doubly linked list forward
    void displayForward() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to display the doubly linked list backward
    void displayBackward() {
        Node* current = tail;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dlist;
    dlist.append(1);
    dlist.append(2);
    dlist.append(3);
    dlist.append(4);
    dlist.append(5);

    cout << "Doubly Linked List Forward: ";
    dlist.displayForward();

    cout << "Doubly Linked List Backward: ";
    dlist.displayBackward();

    return 0;
}
