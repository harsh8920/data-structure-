#include <iostream>
using namespace std;

// Define a struct for a linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

// Function to find the length of a linked list
int getLength(ListNode* head) {
    int length = 0;
    while (head != nullptr) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the merge point of two linked lists
ListNode* findMergePoint(ListNode* headA, ListNode* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    // Move the pointer of the longer list ahead by the difference in lengths
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    // Traverse both lists in parallel until a common node (merge point) is found
    while (headA != nullptr && headB != nullptr) {
        if (headA == headB) {
            return headA; // Merge point found
        }
        headA = headA->next;
        headB = headB->next;
    }

    return nullptr; // No merge point found
}

int main() {
    // Create two linked lists
    ListNode* listA = new ListNode(1);
    listA->next = new ListNode(2);
    listA->next->next = new ListNode(3);
    listA->next->next->next = new ListNode(4);
    listA->next->next->next->next = new ListNode(5);

    ListNode* listB = new ListNode(6);
    listB->next = listA->next->next; // Merge point

    cout << "Linked List A: 1 -> 2 -> 3 -> 4 -> 5" << endl;
    cout << "Linked List B: 6 -> 3" << endl;

    // Find the merge point
    ListNode* mergePoint = findMergePoint(listA, listB);

    if (mergePoint != nullptr) {
        cout << "Merge Point Value: " << mergePoint->val << endl;
    } else {
        cout << "No merge point found." << endl;
    }

    return 0;
}
