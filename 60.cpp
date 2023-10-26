#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Definition for a binary tree node representing an operator or operand.
struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const std::string& val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to check if a given string is an operator (+, -, *, /).
bool isOperator(const std::string& str) {
    return str == "+" || str == "-" || str == "*" || str == "/";
}

// Function to evaluate a binary expression tree.
int evaluateExpression(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    if (!isOperator(root->value)) {
        return std::stoi(root->value);
    }

    int leftValue = evaluateExpression(root->left);
    int rightValue = evaluateExpression(root->right);

    if (root->value == "+") {
        return leftValue + rightValue;
    } else if (root->value == "-") {
        return leftValue - rightValue;
    } else if (root->value == "*") {
        return leftValue * rightValue;
    } else if (root->value == "/") {
        if (rightValue == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            return 0;
        }
        return leftValue / rightValue;
    }

    return 0;
}

// Function to create a binary expression tree from a postfix expression.
TreeNode* buildExpressionTree(const std::string& postfix) {
    std::stack<TreeNode*> stack;

    for (const char& c : postfix) {
        if (isdigit(c)) {
            string operand(1, c);
            stack.push(new TreeNode(operand));
        } else if (isOperator(std::string(1, c))) {
            TreeNode* rightOperand = stack.top();
            stack.pop();
            TreeNode* leftOperand = stack.top();
            stack.pop();
            TreeNode* operatorNode = new TreeNode(std::string(1, c));
            operatorNode->left = leftOperand;
            operatorNode->right = rightOperand;
            stack.push(operatorNode);
        }
    }

    return stack.top();
}

int main() {
    // Example postfix expression: "34*5+"
    string postfixExpression = "34*5+";

    TreeNode* root = buildExpressionTree(postfixExpression);

    cout << "Expression tree evaluated result: " << evaluateExpression(root) << endl;

    return 0;
}
