class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int nbits[32];
        memset(nbits, 0, sizeof(nbits));
        int64_t val = 0;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < 32; j++) {
                int bit = (nums[i]>>j) &1;
                if(bit){
                    nbits[j]++;
                }
            }
        }
        for(int i = 0; i < 32; ++i) {
            int n = nbits[i]%3;
            if(n) {
                val += pow(2, i);
            }
        } 
        return val;
    }
};