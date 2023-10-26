#include <iostream>
using namespace std;

// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse a linked list.
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head != nullptr) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// Function to check if a linked list is a palindrome.
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) {
        return true; // An empty list or a single-node list is a palindrome.
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Find the middle of the linked list using the slow and fast pointers.
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list.
    ListNode* reversedSecondHalf = reverseList(slow);

    // Compare the first half and the reversed second half.
    while (reversedSecondHalf != nullptr) {
        if (head->val != reversedSecondHalf->val) {
            return false; // Not a palindrome.
        }
        head = head->next;
        reversedSecondHalf = reversedSecondHalf->next;
    }

    return true; // Palindrome.
}

int main() {
    // Create a sample linked list.
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
