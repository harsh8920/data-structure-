#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to find the diameter of a binary tree.
int findDiameter(TreeNode* root, int& maxHeight) {
    if (root == nullptr) {
        maxHeight = 0;
        return 0;
    }

    int leftHeight, rightHeight;
    int leftDiameter = findDiameter(root->left, leftHeight);
    int rightDiameter = findDiameter(root->right, rightHeight);

    // The diameter can either pass through the root or not.
    int diameterPassingRoot = leftHeight + rightHeight + 1;
    int diameterNotPassingRoot = std::max(leftDiameter, rightDiameter);

    maxHeight = 1 + std::max(leftHeight, rightHeight);

    // Return the maximum of the two possible diameters.
    return std::max(diameterPassingRoot, diameterNotPassingRoot);
}

int diameterOfBinaryTree(TreeNode* root) {
    int maxHeight = 0;
    return findDiameter(root, maxHeight);
}

int main() {
    // Create a sample binary tree.
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int diameter = diameterOfBinaryTree(root);

    cout << "Diameter of the binary tree: " << diameter << endl;

    return 0;
}
