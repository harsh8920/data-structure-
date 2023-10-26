#include <iostream>
using namespace std;

// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Stack {
private:
    ListNode* top; // The top element of the stack

public:
    Stack() : top(nullptr) {}

    // Function to check if the stack is empty.
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to push an element onto the stack.
    void push(int value) {
        ListNode* newNode = new ListNode(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    // Function to pop an element from the stack.
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Stack is empty." << endl;
        } else {
            int value = top->val;
            ListNode* temp = top;
            top = top->next;
            delete temp;
        cout << "Popped " << value << " from the stack." << endl;
        }
    }

    // Function to get the top element of the stack.
    int topElement() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; // You can choose to return a default value or throw an exception.
        } else {
            return top->val;
        }
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.topElement() << endl;

    stack.pop();
    stack.pop();

    cout << "Top element: " << stack.topElement() << endl;

    stack.pop();
    stack.pop(); // Trying to pop from an empty stack.

    return 0;
}
