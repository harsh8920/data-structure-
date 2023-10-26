#include <iostream>
#include <vector>
using namespace std;

int findFloor(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int floor = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return nums[mid];
        else if (nums[mid] < target) {
            floor = nums[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return floor;
}

int findCeiling(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int ceiling = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return nums[mid];
        else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            ceiling = nums[mid];
            right = mid - 1;
        }
    }

    return ceiling;
}

int findPeak(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            return nums[mid];
        } else if (nums[mid] > nums[left]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

int findMinimum(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

int main() {
    vector<int> rotatedArray = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;

    int floor = findFloor(rotatedArray, target);
    int ceiling = findCeiling(rotatedArray, target);
    int peak = findPeak(rotatedArray);
    int minimum = findMinimum(rotatedArray);

    cout << "Ceiling of " << target << " is " << ceiling << endl;
    cout << "Peak element is " << peak << endl;
    cout << "Minimum element is " << minimum << endl;
    cout << "Floor of " << target << " is " << floor << endl;

    return 0;
}
