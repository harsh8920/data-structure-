#include<iostream>
using namespace std;

int main(){
  
    int arr[100];  // Declare an array (adjust the size as needed)
    int n;         // Number of elements in the array
    int value;     // Value to insert

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input the array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value to insert at the end: ";
    cin >> value;

    // Insert the value at the end
    arr[n] = value;
    n++; // Increase the array size

    // Display the updated array
    cout << "Updated array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
//deletion at end

    int arr[100];  // Declare an array (adjust the size as needed)
    int n;         // Number of elements in the array

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input the array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n > 0) {
        // Decrease the array size to delete the last element
        n--;

        // Display the updated array
        cout << "Updated array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "The array is empty. Nothing to delete." << std::endl;
    }

    return 0;
}


