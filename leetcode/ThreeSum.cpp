/*
if nums is empty or nums.size() less than 3
    return
sort the nums
for i from 0 to N-1
    p = nums[i]
    start = i
    end = len-1
    while start < end
        sum = p + nums[start] + nums[end]
        if sum == 0
            dis = start - i
            if ((dis is not equal to 1 And 
                A[start] not equal to A[start-1]) or dis is equal to 1)
            push [nums[i], nums[start], nums[end]] to vector

            start++, end--
        else if p + A[start] + A[end] < 0
            start++
        else 
            end--

*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<vector<int>> r;
        if(nums.empty() || nums.size() < 3) {
            return r;
        }
        std::sort(nums.begin(), nums.end());
        int p=0,start, end;
        for(std::size_t i = 0; i < nums.size()-2; ++i) {
            p = nums[i];
            start = i + 1;
            end = nums.size() -1;
            if(i>=1 && nums[i] == nums[i-1]) {
                continue;
            }
            while(start < end) {
                int sum = p + nums[start] + nums[end];
                if(sum == 0) {
                    int dis = start - i;
                    if((dis != 1 && nums[start] != nums[start-1]) || dis == 1) {
                        r.push_back(std::vector<int>{nums[i], nums[start], nums[end]});
                    }
                    start++, end--;
                }
                else if(sum > 0) {
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return r;
    }
};