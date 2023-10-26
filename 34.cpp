#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
stack<int> mainStack;
stack<int> minStack;

public:
    // Push an element onto the stack.
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    // Pop the top element from the stack.
    void pop() {
        if (!mainStack.empty()) {
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    // Get the top element of the stack.
    int top() {
        return mainStack.top();
    }

    // Get the minimum element in the stack.
    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(3);
    minStack.push(1);
    minStack.push(5);
    minStack.push(2);

    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 1

    minStack.pop();
    minStack.pop();

    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 3

    return 0;
}
