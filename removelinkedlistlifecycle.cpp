#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) {
        return NULL;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return slow;
        }
    }
    return NULL;
}

void deleteCycle(ListNode *head) {
    ListNode *nodeInsideCycle = detectCycle(head);
    if (!nodeInsideCycle) {
        return;
    }
    ListNode *p1 = nodeInsideCycle;
    ListNode *p2 = nodeInsideCycle;
    // Count the length of the cycle
    int count = 1;
    while (p1->next != p2) {
        p1 = p1->next;
        count++;
    }
    // Move p1 count steps ahead of p2
    p1 = head;
    p2 = head;
    for (int i = 0; i < count; i++) {
        p2 = p2->next;
    }
    // Move both pointers at the same speed until they meet
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    // Move p2 to the last node in the cycle
    while (p2->next != p1) {
        p2 = p2->next;
    }
    // Delete the cycle
    p2->next = NULL;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next;
    deleteCycle(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
