#include<iostream>
using namespace std;

int main(){
    //insertion at beginning
    int arr[100]; // Declare an array (adjust the size as needed)
    int n;        // Number of elements in the array
    int value;    // Value to insert

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input the array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    cout << "Enter the value to insert at the beginning: ";
    cin >> value;

    // Shift elements to make room for insertion
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the value at the beginning
    arr[0] = value;
    n++; // Increase the array size

    // Display the updated array
    cout << "Updated array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
// deletion at beginning

    int arr[100]; // Declare an array (adjust the size as needed)
    int n;        // Number of elements in the array

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input the array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Shift elements to fill the gap after deletion
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--; // Decrease the array size

    // Display the updated array
    cout << "Updated array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

