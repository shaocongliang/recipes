class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) { return std::string(); }
        std::string res;
        int n = 0;
        bool end = false;
        string s1 = strs[0];
        for(std::size_t i = 0; i < s1.size(); ++i) {
            for(std::size_t j = 1; j < strs.size(); ++j) {
                if(i > (strs[j].size()-1) || s1[i] != strs[j][i]) {
                    end = true;
                    break;
                }
            }
            if(end) {
                break;
            }
            res += s1[i];
        }
        return res;
    }
};