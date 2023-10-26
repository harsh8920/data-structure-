#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* findMiddle(ListNode* head) {
    if (!head) {
        return nullptr; // The list is empty.
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;       // Move one step at a time.
        fast = fast->next->next; // Move two steps at a time.
    }

    return slow;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    ListNode* middle = findMiddle(head);
    if (middle != nullptr) {
        cout << "The middle element is: " << middle->val << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}
