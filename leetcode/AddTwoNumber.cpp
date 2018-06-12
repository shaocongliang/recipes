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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode *b = nullptr;
        ListNode *head = b;
        int val = 0;
        while(l1 != nullptr || l2 != nullptr) {
            ListNode *p = new ListNode(0);
            if(l1 == nullptr) {
                val = c + l2->val;
                l2 = l2->next;
            }
            else if(l2 == nullptr) {
                val = c + l1->val;
                l1 = l1->next;
            }
            else {
                val = c + l1->val + l2->val;
                l1 = l1->next; l2 = l2->next;
            }
            
            if(val >= 10) {
                    p->val = val%10;
                    c = 1;
            }
            else {
                    p->val = val;
                    c = 0;
            }
            if(head == nullptr) {
                head = p;
                b = p;
            }
            else {
                b->next = p;
                b = b->next;
            }
        }
        if(c) {
            ListNode *node = new ListNode(1);
            b->next = node;
        }
        return head;
    }
};