class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] ans = new int[nums.length];
        int[] backward = new int[nums.length];
        int[] forward = new int[nums.length];
        forward[0] = 1;
        for(int i = 1; i < nums.length; ++i){
            forward[i] = nums[i-1]*forward[i-1];
        }
        backward[nums.length-1] = 1;
        for(int i = nums.length-2; i >= 0; i--){
            backward[i] = backward[i+1]*nums[i+1];
        }
        for(int i = 0; i < nums.length; ++i){
            ans[i] = backward[i]*forward[i];
        }
        return ans;
    }
}
