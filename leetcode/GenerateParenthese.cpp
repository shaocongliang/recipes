class Solution {
public:
    void dfs(std::string str, int numl, int numr, int n) {
        if(numl == n && numr == n) {
            res.push_back(str);
        }
        if(numl < n) {
            dfs(str+"(", numl+1, numr, n);
        }
        if(numl > numr) {
                dfs(str + ")", numl, numr+1, n);
        }

    }
    vector<string> generateParenthesis(int n) {
        std::string str;
        dfs(str, 0, 0, n);
        return res;
    }
    std::vector<std::string> res;
};