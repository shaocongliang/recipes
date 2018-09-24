class Solution {
    public String[] findRelativeRanks(int[] nums) {
        Map<Integer, Integer> posrank = new HashMap<>();
        Map<Integer, Integer> scorank = new HashMap<>();
        int index = 0;
        for(int i : nums) {
            posrank.put(i, index);
            index++;
        }
        Arrays.sort(nums);
        int curpos = nums.length;
        for(int i : nums) {
            scorank.put(i, curpos);
            curpos--;
        }
        int pos = -1;
        String[] rankS = new String[nums.length];
        for(Integer o : scorank.keySet()){
            pos = posrank.get(o);
            Integer nth = scorank.get(o);
            if(nth == 3) {
                rankS[pos] = "Bronze Medal";
            }
            else if(nth == 2){
                rankS[pos] = "Silver Medal";
            }
            else if(nth == 1) {
                rankS[pos] = "Gold Medal";
            }
            else
                rankS[pos] = nth.toString();
        }
        return rankS;
    }
}