class Solution {
public:
    std::map<char, int> createNew(std::string &s, int lhs, int rhs) {
        std::map<char, int> out;
        for(lhs+=1;lhs <=rhs; lhs++) {
            out[s[lhs]] = lhs;
        }
        return out;
    }
    int lengthOfLongestSubstring(string s) {
        std::map<char, int> in;
        int maxlen = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(in.find(s[i]) == in.end()) {
                in.insert(std::make_pair(s[i],i));
            }
            else {
                if(in.size() > maxlen) {
                    maxlen = in.size();
                }
                in = createNew(s, in[s[i]], i);
            }
        }
        return maxlen > in.size()? maxlen : in.size();
    }
};