class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> numCount = new HashMap<>();
        for(int n : nums){
            if(numCount.containsKey(n)){
                numCount.put(n, numCount.get(n)+1);
            }
            else{
                numCount.put(n, 1);
            }
        }
        for(int k : numCount.keySet()){
            if(numCount.get(k)>(nums.length/2)){
                return k;
            }
        }
        return 0;
    }
}
