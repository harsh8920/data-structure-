#include <iostream>
#include <vector>
using namespace std;

int trapRainwater(const std::vector<int>& height) {
    int n = height.size();
    if (n <= 2) {
        return 0;  // Not enough walls to trap water.
    }

    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);

    leftMax[0] = height[0];
    rightMax[n - 1] = height[n - 1];

    // Calculate the left maximum heights for each position.
    for (int i = 1; i < n; ++i) {
        leftMax[i] = std::max(leftMax[i - 1], height[i]);
    }

    // Calculate the right maximum heights for each position.
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = std::max(rightMax[i + 1], height[i]);
    }

    int trappedWater = 0;
    for (int i = 1; i < n - 1; ++i) {
        int minHeight = std::min(leftMax[i], rightMax[i]);
        trappedWater += (minHeight - height[i]);
    }

    return trappedWater;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int trappedWater = trapRainwater(height);

    cout << "The amount of trapped rainwater is: " << trappedWater << " units." << endl;

    return 0;
}
