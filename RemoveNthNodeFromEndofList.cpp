* struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer n steps ahead
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches end
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        // Remove nth node from end
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        
        return dummy->next;
    }
};
