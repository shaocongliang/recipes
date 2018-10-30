class Solution {
    public int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        int[] products = new int[n+1];
        Arrays.fill(products, 1);
        for(int i = 1; i <= n; ++i){
            int k = -100;
            for(int j = 1; j <=i; ++j){
                k = Math.max(k, Math.max(products[i], j*products[i-j]));
            }
            products[i] = k;
        }
        return products[n];
    }
}
