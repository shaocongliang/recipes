class Solution {
    public int rob(int[] nums) {
        if(nums.length==0) return 0;
        int n = nums.length;
        int[] money = new int[n+1];
        money[1] = nums[0];
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                int i1 = 0; int i2 = 0;
                if(i-2 >= 0){
                    i1 = money[i-2];
                }
                if(i+2 <= n)
                    i2 = money[i+2];
                int i3 = i-1 >=0? money[i-1] : 0;
                int i4 = i+1 <=n? money[i+1] : 0;
                money[i] = Math.max(i1+i2+nums[i-1], i3+i4);
            }
        }
        int max = -1;
        for(int i : money){
            if(i > max) max = i;
        }
        return max;
    }
}
