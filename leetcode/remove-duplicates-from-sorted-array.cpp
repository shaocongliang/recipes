class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 ) return 0;
        int cur,prev;
        prev = nums[0];
        int pos = 1;
        bool duplicate = false;
        for(int i = 1; i < nums.size(); ++i) {
            cur = nums[i];
            if(cur == prev) {
                if(duplicate)
                    continue;
                duplicate = true;
            }
            else {
                duplicate = false;
                nums[pos] = cur;
                prev = cur;
                pos++;
            }
        }
        return pos;
    }
};