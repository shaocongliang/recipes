class Solution {
public:
    inline int findValid2(int pos, int end, const string &s) {
        for(;pos >= end; pos--){
            if(isalpha(s[pos]) || isdigit(s[pos])){
                return pos;
            }
        }
        return -1;
    }
    inline int findValid1(int pos, int end, const string &s) {
        for(;pos <= end; pos++) {
            if(isalpha(s[pos]) || isdigit(s[pos])){
                return pos;
            }
        }
        return -1;
    }
    bool isPalindrome(string s) {
       int start = 0, end = s.size()-1;
       while(start <= end && start != -1) {
           int lhs = findValid1(start, end, s);
           int rhs = findValid2(end, start, s);
           if(lhs != -1 && rhs != -1){
               if(toupper(s[lhs]) != toupper(s[rhs])) {
                   std::cout << lhs << " " << rhs << endl;
                   return false;
               }
           }
           else if(lhs == -1 && rhs == -1) {
               return true;
           }
           else {
               return false;
           }
           start = lhs+1;
           end = rhs-1;
       }
        return true;
    }
};
