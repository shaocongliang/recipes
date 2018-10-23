class Solution {
    public int maxChunksToSorted(int[] arr) {
        int nchunk = 0;
        boolean inpattern = false;
        int last = 0;
        for(int i = 0; i < arr.length; ++i){
            if(arr[i] > i){
                inpattern = true;
                last = arr[i] > last? arr[i] : last;
            }
            else if(arr[i] == i && inpattern == false){
                nchunk++;
            }
            else if(arr[i] < i){
                if(i == last){
                    inpattern = false;
                    nchunk++;
                }
            }
        }
        return nchunk;
    }
}
