#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to find the height of a binary tree.
int findTreeHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = findTreeHeight(root->left);
    int rightHeight = findTreeHeight(root->right);

    // The height of the tree is the maximum of the left and right subtree heights, plus 1 for the current node.
    return max(leftHeight, rightHeight) + 1;
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

    int height = findTreeHeight(root);

    cout << "Height of the binary tree: " << height << endl;

    return 0;
}
