class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> results;
        do{
            results.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return results;
    }
};