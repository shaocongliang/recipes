class Solution {
public:
    int strStr(string haystack, string needle) {
         if(needle.empty()) {
             return 0;
         }
        int index1 = 0, index2 =0;
        bool inpattern = false;
        for(std::size_t i = 0; i < haystack.size(); ++i) {
            if(inpattern == false) {
                if(haystack[i] != needle[index2]) {
                    continue;
                }
                else if(haystack[i] == needle[index2]) {
                    inpattern = true; index1 = i; index2++;
                }
            }
            else{
                if(haystack[i] == needle[index2]) {
                    index2++;
                }
                else {
                    index2 = 0;
                    i = index1;
                    inpattern = false;
                }
            }
            if(index2 == needle.size()) {
                return index1;
            }
         }
        return -1;
    }
};