class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int none = 0;
        int max = 0;
        boolean isInPattern = false;
        for(int i = 0; i < nums.length; ++i) {
            if(nums[i] == 1) {
                if(isInPattern == false){
                    isInPattern = true;
                }
                none++;
            }
            else{
                if(none > max){
                    max = none;
                }
                isInPattern = false;
                none = 0;
            }
        }
        return 0;
    }
}
