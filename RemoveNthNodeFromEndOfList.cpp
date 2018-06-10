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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::map<int, ListNode**> loc2node;
        ListNode **indirect = &head;
        int index = 0;
        while(*indirect) {
            loc2node[index++] = indirect;
            indirect = &(*indirect)->next;
        }
        *loc2node[loc2node.size()-n] = (*loc2node[loc2node.size()-n])->next;
        return head;
    }
};