class Solution {
    public int findDuplicate(int[] nums) {
        int target = 0;
        int slow = 0;
        int fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        while(target != slow){
            target = nums[target];
            slow = nums[slow];
        }
        return target;
    }
}
