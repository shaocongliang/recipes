class Solution {
public:
    int reverse(int x) {
        int64_t rev = 0;
        bool isnegative = x >= 0? false:true;
        int n = 0;
        while(x) {
            n = x%10;
            x = x/10;
            rev = rev*10 + (n < 0? -n:n);
        }
        int64_t max = pow(2,31)-1;
        int64_t min = -pow(2,31);
        if(isnegative) {
            rev = -rev;
        }
        return (rev>max || rev < min)? 0 : rev;
    }
    
};