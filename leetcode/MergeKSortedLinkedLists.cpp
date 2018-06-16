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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        bool confirmFirstNode = false;
        ListNode *newhead = nullptr, *head;
        ListNode *entry = nullptr;
        while(isListsEmpty(lists) == false) {
            insertMaxNode(lists, entry);
            if(confirmFirstNode == false) {
                newhead = entry;
                confirmFirstNode = true;
                head = entry;
            }
            else{
                newhead->next = entry;
                newhead = newhead->next;
            }
        }
        return head;
    }
private:
    void insertMaxNode(std::vector<ListNode*> &lists, ListNode *&entry) {
        int maxval = INT_MAX;
        int index = 0;
        ListNode *maxNode = nullptr;
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i]) {
                if(lists[i]->val < maxval) {
                    index = i;
                    maxval = lists[i]->val;
                }
            }
        }
        std::cout << index << std::endl;
        entry = lists[index];
        lists[index] = lists[index]->next;
    }
    bool isListsEmpty(const std::vector<ListNode*> &lists) {
        for(auto it : lists) {
            if(it) {
                return false;
            }
        }
        return true;
    }
};