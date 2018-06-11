class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        int another = 0;
        for(auto it = nums.begin(); it != nums.end(); ++it) {
            another = target - *it;
            auto iter = std::find(it+1, nums.end(), another);
            if(iter != nums.end()) {
                result.push_back(std::distance(nums.begin(), it));
                result.push_back(std::distance(nums.begin(), iter));
            }
        }
        return result;
    }
};