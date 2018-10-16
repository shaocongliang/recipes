class Solution {
    public boolean isMonotonic(int[] A) {
        if(A.length == 0)
            return false;
        boolean incr = false;
        int prev = A[0];
        int pos = 0;
        for(int i = 1; i < A.length; ++i){
            pos = i;
            if(A[i] > prev){
                incr = true;
                break;
            }
            if(A[i] == prev){
                continue;
            }
            if(A[i] < prev){
                break;
            }
        }
        if(pos == A.length-1) return true;
        if(incr){
            for(int i = pos+1; i < A.length; ++i){
                if(A[i] < A[i-1])
                    return false;
            }
        }
        else{
            for(int i = pos+1; i < A.length; ++i){
                if(A[i] > A[i-1])
                    return false;
            }
        }
        return true;
    }
}
