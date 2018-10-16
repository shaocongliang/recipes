class Pair{
    int num;
    public int getNum() {
        return num;
    }
    public int getVal() {
        return val;
    }
    public void setNum(int num) {
        this.num = num;
    }
    public void setVal(int val) {
        this.val = val;
    }
    public int val;
}
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> topk = new LinkedList<>();
        List<Pair> list=new ArrayList<>();
        Arrays.sort(nums);;
        Map<Integer, Pair> mp = new HashMap<>();
        for(int i = 0; i < nums.length; ++i){
            Pair p = new Pair();
            if(mp.containsKey(nums[i])){
                mp.get(nums[i]).val++;
            }
            else{
                p.num = nums[i];
                p.val = 1;
                mp.put(nums[i], p);
            }
        }
        for(Pair p : mp.values()){
            list.add(p);
        }
        list.sort(Comparator.comparingInt(Pair::getVal).reversed());
        for(int i = 0; i <k; ++i){
            topk.add(list.get(i).num);
        }
        return topk;
    }
}
