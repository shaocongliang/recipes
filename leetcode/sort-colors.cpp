class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0) return;
        int start = 0; 
        int end = nums.size()-1;
        int pivot = 0;
        while(start <= end) {
            if(nums[start] == 0){
                swap(nums[start], nums[pivot]);
                start++;
                pivot++;
            }
            else if(nums[start] == 1) {
                start++;
                continue;
            }
            else{
                swap(nums[end], nums[start]);
                end--;
            }
        }
    }
};
