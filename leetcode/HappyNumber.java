class Solution {
    public boolean isHappy(int n) {
        ArrayList<Integer> digits = new ArrayList<>();
        int sum = 0;
        Set<Integer> qs = new HashSet<>();
        while(sum != 1 && qs.contains(sum) == false) {
            qs.add(sum);
            sum = 0;
            while (n != 0) {
                int t = n % 10;
                n /= 10;
                digits.add(t);
            }
            for(Integer i : digits){
                sum += i*i;
            }
            digits = new ArrayList<Integer>();
            n = sum;
        }
        if(sum == 1) return true;
        return false;
    }
}
