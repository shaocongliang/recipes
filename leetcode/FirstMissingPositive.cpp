class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) {return 1;}
        int len = nums.size();int i = 0;
        int max = *max_element(nums.begin(), nums.end());
        nums.resize(max);
        for(i = 0; i < len; ++i) {
            if(nums[i] <=0 ) {
                continue;
            }
            else if(nums[i] == i+1) {
                continue;
            }
            else {
                swap(nums[nums[i]-1], nums[i]);
                if(nums[i] != i+1) {
                    if(nums[nums[i]-1] == nums[i]) {
                        continue;
                    }
                    else {
                        i--;
                    }
                }
            }
        }
        for(i = 0; i < len; ++i) {
            if(nums[i] != i+1) {
                return i+1;
            }
        }
        return i+1;
    }
};
