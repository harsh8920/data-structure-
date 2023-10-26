#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    std::vector<int> arr;
    int top;

public:
    Stack(int size) {
        arr.resize(size);
        top = -1;
    }

    // Function to check if the stack is empty.
    bool isEmpty() {
        return top == -1;
    }

    // Function to push an element onto the stack.
    void push(int value) {
        if (top == arr.size() - 1) {
            cout << "Stack overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << "Pushed " << value << " onto the stack." << endl;
        }
    }

    // Function to pop an element from the stack.
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Stack is empty." << endl;
        } else {
            cout << "Popped " << arr[top--] << " from the stack." << endl;
        }
    }

    // Function to get the top element of the stack.
    int topElement() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; // You can choose to return a default value or throw an exception.
        } else {
            return arr[top];
        }
    }
};

int main() {
    Stack stack(5);

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
