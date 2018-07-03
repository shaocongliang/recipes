class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v = {0};
        if(0 == n) {
            return v;
        }
        int val = pow(2, n);
        for(int i = 1; i < val; ++i) {
            v.push_back(i^(i>>1));
        }
        return v;
    }
};
