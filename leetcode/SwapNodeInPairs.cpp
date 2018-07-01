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
    ListNode* swapPairs(ListNode* head) {
        if(head && nullptr == head->next) {
            return head;
        }
        else if(nullptr == head) {
            return head;
        }
        ListNode *first = head;
        ListNode *second = nullptr;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        ListNode *entry = nullptr;
        while(first && first->next) {
            second = first->next;
            next = second->next;
            second->next = first;
            first->next = next;
            if(nullptr == entry) {
                entry = second;
            }
            if(nullptr == prev){
                prev = first;
            }
            else {
                prev->next = second;
                prev = first;
            }
            first = first->next;
        }
        return entry;
    }
};
