class Solution {
    public int minFallingPathSum(int[][] A) {
        int val = Integer.MAX_VALUE;
        int[][] sum = new int[A.length][A[0].length];
        for(int i = 0; i < A[0].length; ++i){
            sum[0][i] = A[0][i];
        }
        for(int i = 1; i < A.length; ++i){
            for(int j = 0; j < A[i].length; ++j){
                if(j == 0){
                    sum[i][j] = Math.min(sum[i-1][0], sum[i-1][1]) + A[i][j];
                }
                else if(j == A[i].length-1){
                    sum[i][j] = Math.min(sum[i-1][j-1], sum[i-1][j]) + A[i][j];
                }
                else{
                    sum[i][j] = Math.min(Math.min(sum[i-1][j], sum[i-1][j-1]), sum[i-1][j+1]) + A[i][j];
                }
            }
        }
        for(int i = 0; i < sum.length; ++i)
        System.out.println(Arrays.toString(sum[i]));
        for(int i = 0; i < sum[sum.length-1].length; ++i){
            if(sum[sum.length-1][i] < val)
                val = sum[sum.length-1][i];
        }
        return val;
    }
}
