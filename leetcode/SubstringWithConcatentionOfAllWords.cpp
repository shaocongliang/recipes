ass Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> hints;
        if(words.size() == 0) return hints;
        int dstlen = words.size()*words[0].size();
        int pos = 0;
        std::multiset<string> s1;
        for(auto it : words)
            s1.insert(it);
        std::sort(words.begin(), words.end());
        auto last = std::unique(words.begin(), words.end());
        words.erase(last, words.end());
        int start = 0;
        for(int i = 0; i < words.size(); ++i) {
            while(true){
                pos = s.find(words[i],start);
                start = pos+1;
                if(pos == std::string::npos) break;
                int end = pos + dstlen;
                if(end > s.size()) break;
                vector<string> diff;
                multiset<string> s2;
                for(int index = pos; index < end; index+=words[0].size()){
                    s2.insert(s.substr(index, words[0].size()));
                }
                set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(diff, diff.begin()));
                if(diff.empty()) hints.push_back(pos);
            }
            start = 0;
        }
        return hints;
    }
};
