class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Define a priority queue to store the smallest element
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        // Add all the elements to the heap
        for (auto l : lists) {
            while (l) {
                min_heap.push(l->val);
                l = l->next;
            }
        }
        
        // Create the merged linked list
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while (!min_heap.empty()) {
            tail->next = new ListNode(min_heap.top());
            tail = tail->next;
            min_heap.pop();
        }
        
        return head->next;
    }
};
