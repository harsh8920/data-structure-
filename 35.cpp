#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

// Function to evaluate a mathematical expression in prefix notation.
int evaluatePrefixExpression(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            // If the token is a number (including negative numbers), push it onto the stack.
            stack.push(stoi(token));
        } else {
            // If the token is an operator, pop two operands from the stack, perform the operation, and push the result back.
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            if (token == "+") {
                stack.push(operand1 + operand2);
            } else if (token == "-") {
                stack.push(operand1 - operand2);
            } else if (token == "*") {
                stack.push(operand1 * operand2);
            } else if (token == "/") {
                stack.push(operand1 / operand2);
            }
        }
    }

    // The final result will be on top of the stack.
    return stack.top();
}

int main() {
    string expression = "+ 2 3"; // Example: 2 + 3
    int result = evaluatePrefixExpression(expression);

    cout << "Result: " << result << endl;

    return 0;
}
