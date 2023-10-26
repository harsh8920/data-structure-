#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to find the bottom view of a binary tree.
void bottomView(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<std::pair<TreeNode*, int>> q;
    map<int, int> bottomViewMap; // Maps horizontal distance to node value

    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int hd = q.front().second;
        q.pop();

        // Replace the previous node at the same horizontal distance
        bottomViewMap[hd] = node->value;

        if (node->left) {
            q.push({node->left, hd - 1});
        }

        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    // Print the bottom view in order of horizontal distance.
    for (const auto& pair : bottomViewMap) {
        cout << pair.second << " ";
    }
    cout << endl;
}

int main() {
    // Create a sample binary tree.
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    cout << "Bottom view of the binary tree: ";
    bottomView(root);

    return 0;
}
