class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int val = 0;
        int ori = x;
        while(x) {
            val = val*10 + x%10;
            x /= 10;
        }
        return val == ori? true: false;
    }
};