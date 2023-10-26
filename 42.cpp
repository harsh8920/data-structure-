#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    // Function to insert a new node into the binary tree.
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Function to insert a new node recursively.
    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->value) {
            node->left = insertNode(node->left, value);
        } else if (value > node->value) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // Function to print the binary tree in-order (left, root, right).
    void inOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->value << " ";
            inOrderTraversal(node->right);
        }
    }

    void printInOrder() {
        inOrderTraversal(root);
    }
};

int main() {
    BinaryTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    cout << "In-order traversal of the binary tree: ";
    tree.printInOrder();
    cout << endl;

    return 0;
}
