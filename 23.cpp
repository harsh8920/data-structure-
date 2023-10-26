#include<iostream>
using namespace std;



struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return false; // No cycle if there are 0 or 1 nodes.
    }
    
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;      // Move one step at a time.
        fast = fast->next->next; // Move two steps at a time.

        if (slow == fast) {
            // Cycle detected.
            return true;
        }
    }

    // No cycle found.
    return false;
}
void removeCycle(ListNode* head) {
    if (!head || !head->next) {
        return; // No cycle if there are 0 or 1 nodes.
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* start = head;

    // Detect the cycle using Floyd's algorithm.
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected. Find the starting point of the cycle.
            while (start != slow) {
                start = start->next;
                slow = slow->next;
            }

            // Remove the cycle by setting the 'next' pointer of the node
            // before the cycle start to nullptr.
            ListNode* prev = head;
            while (prev->next != start) {
                prev = prev->next;
            }
            prev->next = nullptr;
            break;
        }
    }
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
    node5->next = node2; // Create a cycle

    if (hasCycle(head)) {
        cout << "Cycle detected." << endl;
        removeCycle(head);
        cout << "Cycle removed." << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
