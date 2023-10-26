#include<iostream>
using namespace std;

int main(){
    
    int arr[100];  // Declare an array (adjust the size as needed)
    int n;         // Number of elements in the array
    int pos;       // User-defined position for insertion
    int value;     // Value to insert

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input the array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the position for insertion: ";
    cin >> pos;

    if (pos < 0 || pos > n) {
        cout << "Invalid position for insertion." << std::endl;
    } else {
        cout << "Enter the value to insert: ";
        cin >> value;

        // Shift elements to make room for insertion
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        // Insert the value
        arr[pos] = value;
        n++;  // Increase the array size

        // Display the updated array
        cout << "Updated array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

   


    int arr[100];  // Declare an array (adjust the size as needed)
    int n;         // Number of elements in the array
    int pos;       // User-defined position for deletion

cout << "Enter the number of elements in the array: ";
cin >> n;

    // Input the array elements
cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
    cin >> arr[i];
    }

cout << "Enter the position for deletion: ";
cin >> pos;

    if (pos < 0 || pos >= n) {
        cout << "Invalid position for deletion." << std::endl;
    } else {
        // Shift elements to fill the gap
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;  // Decrease the array size

        // Display the updated array
        cout << "Updated array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

