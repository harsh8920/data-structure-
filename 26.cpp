#include <iostream>
using namespace std;

// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists.
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Create a dummy node as the starting point for the merged list.
    ListNode dummy(0);
    ListNode* current = &dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // If one of the lists is not empty, link it to the merged list.
    if (l1 != nullptr) {
        current->next = l1;
    } else if (l2 != nullptr) {
        current->next = l2;
    }

    // Return the merged list, starting from the next of the dummy node.
    return dummy.next;
}

// Function to display a linked list.
void displayList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Create two sorted linked lists.
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // Merge the two lists and display the result.
    ListNode* mergedList = mergeTwoLists(l1, l2);
    cout << "Merged List: ";
    displayList(mergedList);

    return 0;
}
