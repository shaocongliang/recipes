class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> hints;
        vector<pair<string, string>> ps;
        for(auto it : strs){
            string s = it;
            sort(s.begin(), s.end());
            ps.push_back(make_pair(it, s));
        }
 
        sort(ps.begin(), ps.end(), [](pair<string, string> lhs, pair<string, string> rhs)->bool{ return lhs.second < rhs.second; });
        vector<string> hint;
        string src = ps[0].second;
        hint.push_back(ps[0].first);
        for(int i = 1; i < ps.size(); ++i) {
            if(ps[i].second == src){
                hint.push_back(ps[i].first);
            }
            else {
                hints.push_back(hint);
                hint.clear();
                vector<string> temp;
                hint.swap(temp);
                src = ps[i].second;
                hint.push_back(ps[i].first);
            }
        }
        hints.push_back(hint);
        return hints;
    }
};
