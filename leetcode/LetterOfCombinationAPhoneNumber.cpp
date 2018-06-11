class Solution {
public:
    void dfs(const string &in, string &res, int pos) {
             static map<int, string> tab ={
           {2, "abc"},{3, "def"},{4, "ghi"},
           {5, "jkl"},{6, "mno"},{7,"pqrs"},{8, "tuv"},
           {9, "wxyz"}
       };
        if(pos == in.size()) {
            v.push_back(res);
            return;
        }
        
        for(auto it : tab[in[pos]-48]) {
            res[pos] = it;
            dfs(in, res, pos+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return std::vector<std::string>();
        }
        static string res;res.resize(digits.size());
        dfs(digits, res, 0);
        return v;
    }
private:
    std::vector<string> v;
};