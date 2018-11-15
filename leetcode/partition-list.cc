class Solution {
 public:
  ListNode *partition(ListNode *head, int x) {
    ListNode **pphead = &head;
    ListNode **ppnode = &head;
    ListNode **pivot = nullptr;
    while(*ppnode != nullptr){
      if((*ppnode)->val >= x) {
        if(pivot== nullptr)
          pivot = ppnode;
        ppnode = &(*ppnode)->next;
      }
      else {
        if(pivot){
          ListNode *pnext = (*ppnode)->next;
          (*ppnode)->next = *pivot;
          ppnode = &pnext;
        }
        else{
          ppnode = &(*ppnode)->next;
        }
      }
    }
    return *pphead;
  }
};
