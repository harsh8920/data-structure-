#include <iostream>
using namespace std;
class Queue {
private:
    int front; // Index of the front of the queue
    int rear;  // Index of the rear of the queue
    int capacity; // Maximum capacity of the queue
    int* array; // Array to store queue elements

public:
    Queue(int size) {
        capacity = size;
        front = rear = -1;
        array = new int[capacity];
    }

    // Function to check if the queue is empty.
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full.
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // Function to get the size of the queue.
    int size() {
        if (isEmpty()) {
            return 0;
        }
        if (front <= rear) {
            return rear - front + 1;
        } else {
            return capacity - front + rear + 1;
        }
    }

    // Function to enqueue an element to the queue.
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
        } else {
            if (isEmpty()) {
                front = 0;
            }
            rear = (rear + 1) % capacity;
            array[rear] = value;
            cout << "Enqueued " << value << " into the queue." << endl;
        }
    }

    // Function to dequeue an element from the queue.
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            int value = array[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % capacity;
            }
            cout << "Dequeued " << value << " from the queue." << endl;
        }
    }

    // Function to get the front element of the queue.
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // You can choose to return a default value or throw an exception.
        } else {
            return array[front];
        }
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    cout << "Front element: " << queue.getFront() << endl;

    queue.dequeue();
    queue.dequeue();
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7); // Trying to enqueue into a full queue.

    cout << "Front element: " << queue.getFront() << endl;

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue(); // Trying to dequeue from an empty queue.

    return 0;
}
