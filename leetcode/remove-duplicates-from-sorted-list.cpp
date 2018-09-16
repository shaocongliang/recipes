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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        int target = head->val;
        ListNode *node = head->next;
        ListNode *prev = head;
        while(node){
            if(node->val == target){
                prev->next = node->next;
            }
            else {
                target = node->val;
                prev = node;
            }
            node = node->next;
        }
        return head;
    }
};
