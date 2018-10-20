class Solution {
    public int searchInsert(int[] nums, int target) {
        int start = 0;
        int end = nums.length-1;
        while(start <= end){
            int mid = (start+end)/2;
            if(nums[mid] > target){
                end = mid-1;
            }
            else if(nums[mid] < target){
                start = mid+1;
            }
            else{
                return mid;
            }
        }
        System.out.println(start+" "+end);
        if(end<=0) return nums[0] < target? 1 : 0;
        else if(start==nums.length) return nums.length;
        else return nums[start-1] < target? start : start-1;
    }
}
