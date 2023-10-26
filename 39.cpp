#include <iostream>
#include <vector>
#include <deque>
using namespace std;

std::vector<int> findFirstNegatives(const std::vector<int>& arr, int k) {
    vector<int> result;
    deque<int> dq; // Store indices of negative elements

    int n = arr.size();
    int i;

    // Process the first window of size 'k'
    for (i = 0; i < k; ++i) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

    // Process remaining windows
    for (; i < n; ++i) {
        // If there are negative elements in the current window, add the leftmost one to the result
        if (!dq.empty()) {
            result.push_back(arr[dq.front()]);
        } else {
            result.push_back(0); // No negative element found
        }

        // Remove elements that are out of the current window
        while (!dq.empty() && dq.front() <= (i - k)) {
            dq.pop_front();
        }

        // Add the current element to the deque if it's negative
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

    // Process the last window
    if (!dq.empty()) {
        result.push_back(arr[dq.front()]);
    } else {
        result.push_back(0); // No negative element found
    }

    return result;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> result = findFirstNegatives(arr, k);

    cout << "First negative integers in every window of size " << k << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
