#include <iostream>
 using namespace std;
 
// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to find the Nth node from the end of a linked list.
ListNode* findNthFromEnd(ListNode* head, int n) {
    if (!head || n <= 0) {
        return nullptr; // Invalid input or the list is empty.
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Move the fast pointer n nodes ahead.
    for (int i = 0; i < n; ++i) {
        if (fast == nullptr) {
            return nullptr; // List is shorter than n nodes.
        }
        fast = fast->next;
    }

    // Move both pointers until the fast pointer reaches the end.
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // The slow pointer is at the Nth node from the end.
}

int main() {
    // Create a sample linked list.
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Find the 2nd node from the end.

    ListNode* nthNode = findNthFromEnd(head, n);

    if (nthNode) {
        cout << "The " << n << "th node from the end is: " << nthNode->val << endl;
    } else {
        cout << "The list is too short, or the input is invalid." << endl;
    }

    return 0;
}
