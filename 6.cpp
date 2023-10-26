#include<iostream>
using namespace std;


    

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Return the index where the key is found
        }
    }
    return -1;  // Return -1 if the key is not found
}

int main() {
    int arr[] = {12, 45, 78, 33, 67, 54, 90, 41};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the element to search for: ";
    cin >> key;

    int result = linearSearch(arr, n, key);

    switch (result) {
        case -1:
            cout << "Element not found in the array." << std::endl;
            break;
        default:
            cout << "Element found at index " << result << " in the array." << std::endl;
            break;
    }

    return 0;
}

