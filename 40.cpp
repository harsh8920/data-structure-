#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find the next greater element to the right for each element.
std::vector<int> nextGreaterRight(const std::vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize with -1.
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && arr[i] > arr[stack.top()]) {
            result[stack.top()] = arr[i];
            stack.pop();
        }
        stack.push(i);
    }

    return result;
}

// Function to find the next greater element to the left for each element.
std::vector<int> nextGreaterLeft(const std::vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize with -1.
    stack<int> stack;

    for (int i = n - 1; i >= 0; --i) {
        while (!stack.empty() && arr[i] > arr[stack.top()]) {
            result[stack.top()] = arr[i];
            stack.pop();
        }
        stack.push(i);
    }

    return result;
}

// Function to find the nearest smaller element to the left for each element.
vector<int> nearestSmallerLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize with -1.
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && arr[i] < arr[stack.top()]) {
            stack.pop();
        }
        if (!stack.empty()) {
            result[i] = arr[stack.top()];
        }
        stack.push(i);
    }

    return result;
}

// Function to find the next smaller element to the right for each element.
std::vector<int> nextSmallerRight(const std::vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize with -1.
    stack<int> stack;

    for (int i = n - 1; i >= 0; --i) {
        while (!stack.empty() && arr[i] < arr[stack.top()]) {
            result[stack.top()] = arr[i];
            stack.pop();
        }
        stack.push(i);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> nextGreaterRightArr = nextGreaterRight(arr);
    vector<int> nextGreaterLeftArr = nextGreaterLeft(arr);
    vector<int> nearestSmallerLeftArr = nearestSmallerLeft(arr);
    vector<int> nextSmallerRightArr = nextSmallerRight(arr);

    cout << "Next Greater to Right: ";
    for (int num : nextGreaterRightArr) {
        cout << num << " ";
    }
    cout << std::endl;

    cout << "Next Greater to Left: ";
    for (int num : nextGreaterLeftArr) {
        std::cout << num << " ";
    }
cout << endl;

cout << "Nearest Smaller to Left: ";
    for (int num : nearestSmallerLeftArr) {
    cout << num << " ";
    }
cout <<endl;

cout << "Next Smaller to Right: ";
    for (int num : nextSmallerRightArr) {
    cout << num << " ";
    }
cout <<endl;

    return 0;
}
