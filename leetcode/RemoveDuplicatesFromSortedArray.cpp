class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) {
            return nums.size();
        }
      int val = 0;
      int cur = 0;
      int next = 1;
      bool holeFilled = false;
      int prev = nums[0];
      for(int i = 1; i < nums.size(); ++i) {
         val = nums[i];
         if(prev != nums[i]) {
             prev = val;
             nums[next] = nums[i];
             next = next+1;
             continue;
         }
         else {
             cur = i+1;
             while(cur <= nums.size()-1 && val == nums[cur]) {
                 cur++;
             }
             if(cur == nums.size()) {
                 return next;
             }
             nums[next] = nums[cur];
             prev = nums[next];
             next++;
             i = cur;
         }
      }
        return next;
    }
};