class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int> v;
        int c = 0;
        int cur = digits[digits.size()-1] + c +1;
        if(cur+c >= 10) {
            c = 1;
        }
        v.push_back(cur%10);
        cur = 0;
        for(int i = digits.size() - 2; i >= 0; i--) {
            cur = digits[i] + c;
            if(cur >= 10){
                c = 1;
            }
            else {
                c = 0;
            }
            v.push_back(cur%10);
            cur = 0;
        }
        if(c){
            v.push_back(c);
        }
        std::reverse(v.begin(), v.end());
        return v;
    }
};