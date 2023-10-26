#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to perform a postorder traversal of a binary tree.
void postorderTraversal(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    postorderTraversal(node->left);   // Traverse the left subtree.
    postorderTraversal(node->right);  // Traverse the right subtree.
    cout << node->value << " "; // Process the current node (root).
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

    cout << "Postorder traversal of the binary tree: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
