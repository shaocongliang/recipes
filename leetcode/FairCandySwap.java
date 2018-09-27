class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int[] arr = new int[2];
        int suma = IntStream.of(A).sum();
        int sumb = IntStream.of(B).sum();
        int diff = suma - sumb;
        for(int i = 0; i < A.length; ++i){
            int target = A[i]-diff/2;
            for(int j = 0; j < B.length; ++j){
                if(B[j] == target){
                    arr[0] = A[i];
                    arr[1] = B[j];
                    break;
                }
            }
        }
        return arr;
    }
}
