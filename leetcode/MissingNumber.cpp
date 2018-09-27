class Solution {
    public int missingNumber(int[] nums) {
        int max = 0;
        boolean findzero = false;
        for(int i = 0; i < nums.length; ++i) {
            if(nums[i] > max){
                max = nums[i];
            }
            if(nums[i] == 0){
                findzero = true;
            }
        }
        int sum = IntStream.of(nums).sum();
        int nsum = 0;
        for(int i = 0; i <= max; ++i){
            nsum += i;
        }
        if(nsum - sum ==0){
            if(findzero){
                return max+1;
            }
            else {
                return 0;
            }
        }
        return nsum - sum;
    }
}
