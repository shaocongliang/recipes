/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;
        ListNode *first = nullptr;
        ListNode *second = nullptr;
        int index = 1;
        while (cur)
        {
            if (index < m || index > n)
            {
                if (index == (m - 1) && m != 1)
                {
                    first = cur;
                }
                cur = cur->next;
            }
            if (index >= m && index <= n)
            {
                if (index == m)
                {
                    second = cur;
                }
                next = cur->next;
                cur->next = prev;
                prev = cur;
                if (index == n)
                {
                    if (first)
                    {
                        first->next = cur;
                    }
                    second->next = next;
                }
                cur = next;
            }
            index++;
        }
        if (m != 1)
        {
            return head;
        }
        else
        {
            return prev;
        }
    }
};