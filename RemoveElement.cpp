/*
    bool diff = false
    cur = 0, tail = nums.size()-1
    while cur <= tail
        if nums[cur] == val
            swap(nums[cur], nums[tail])
            tail--
        else
            diff = true
            cur++;

    if (diff && tail == 0) || (tail != 0)
        return tail+1
    else
        return tail
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        bool diff = false;
        int tail = nums.size()-1;
        int cur = 0;
        while(cur <= tail) {
            if(nums[cur] == val) {
                swap(nums[cur], nums[tail]);
                tail--;
            }
            else {
                diff = true;
                cur++;
            }
        }
        if((tail == 0 && diff) || tail != 0) {
            return tail+1;
        }
        else
            return tail;
    }
};