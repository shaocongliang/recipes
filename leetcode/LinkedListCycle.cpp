/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) {
            return head;
        }
        ListNode *quick = head;
        ListNode *slow = head;
        while(slow && quick) {
            slow = slow->next;
            quick = quick->next;
            if(quick) {
                quick = quick->next;
            }
            else {
                return false;
            }
            if(slow == quick) {
                return true;
            }
        }
        return false;
    }
};