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
    ListNode* reverseList(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *next;
        ListNode *prev = nullptr;
        ListNode *current = head;
        while(current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    int listLen(ListNode *head) {
        ListNode **indirect = &head;
        int count = 0;
        while(*indirect) {
            count++;
            indirect = &(*indirect)->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(listLen(head) == 0) {
            return head;
        }
        int nstep = k % listLen(head);
        if(nstep == 0) {
            return head;
        }
        ListNode **indirect = &head;
        ListNode *prev = nullptr;
        for(int i = 0; i < listLen(head)-nstep; ++i) {
            prev = *indirect;
            indirect = &(*indirect)->next;
        }
        prev->next =reverseList(*indirect);
        ListNode* node = reverseList(head);
        indirect = &node;
        for(int i = 0; i < nstep; ++i) {
            prev = *indirect;
            indirect = &(*indirect)->next;
        }
        prev->next = reverseList(*indirect);
        return node;

    
    }
};
