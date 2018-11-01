class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n==0) return 0;
        if(n==1) return nums[0];
        int[] money1 = new int[n+1];
        int[] money2 = new int[n+1];
        money1[1] = nums[0];
        for(int i = 1; i < n; ++i){
            for(int j = 1; j <= i; ++j){
                int i1 = i-2 >=1? money1[i-2] : 0;
                int i2 = i+2 <n? money1[i+2] : 0;
                int i3 = i-1 >=1? money1[i-1] : 0;
                int i4 = i+1 <n? money1[i+1] : 0;
                money1[i] = Math.max(i1+i2+nums[i-1], i3+i4);
            }
        }
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                int i1 = i-2 >= 1? money2[i-2] : 0;
                int i2 = i+2 <=n? money2[i+2] : 0;
                int i3 = i-1 >= 1? money2[i-1] : 0;
                int i4 = i+1 <=n? money2[i+1] : 0;
                money2[i] = Math.max(i1+i2+nums[i-1], i3+i4);
            }
        }
        return money1[n-1] > money2[n] ? money1[n-1] : money2[n];
    }
}
