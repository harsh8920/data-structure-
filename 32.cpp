#include <iostream>
using namespace std;

// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Queue {
private:
    ListNode* front; // Front of the queue
    ListNode* rear;  // Rear of the queue

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty.
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to enqueue an element to the queue.
    void enqueue(int value) {
        ListNode* newNode = new ListNode(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    // Function to dequeue an element from the queue.
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            int value = front->val;
            ListNode* temp = front;
            front = front->next;
            delete temp;
            cout << "Dequeued " << value << " from the queue." << endl;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
    }

    // Function to get the front element of the queue.
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // You can choose to return a default value or throw an exception.
        } else {
            return front->val;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    cout << "Front element: " << queue.getFront() << endl;

    queue.dequeue();
    queue.dequeue();

    cout << "Front element: " << queue.getFront() << endl;

    queue.dequeue();
    queue.dequeue(); // Trying to dequeue from an empty queue.

    return 0;
}
