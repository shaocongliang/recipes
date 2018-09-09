class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        multiset<char> chs;
        for(auto ch : s) { chs.insert(ch); }
        for(auto ch : t) {
            auto pos = chs.find(ch);
            if(pos == chs.end()) return false;
            else chs.erase(pos);
        }
        return chs.empty()? true : false;
    }
};