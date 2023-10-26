#include<iostream>
using namespace std;



int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid; // Key found, return the index
        }

        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Key not found
}

int main() {
    int arr[] = {12, 24, 35, 47, 58, 69, 73, 86, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the element to search for: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
    }
