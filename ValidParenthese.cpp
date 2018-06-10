class Solution {
public:
    bool isValid(string s) {
        stack<char> sa;
        for(auto &it : s) {
            if(it == '(' || it == '[' || it == '{') {
                sa.push(it);
            }
            if(it == ')' || it == ']' || it == '}') {
                if(sa.empty()) {
                    return false;
                }
                else {
                    char c = sa.top();
                    sa.pop();
                    if(it == ')' && c != '(') {
                        return false;
                    }
                    else if(it == '}' && c != '{') {
                        return false;
                    }
                    else if(it == ']' && c != '[') {
                        return false;
                    }
                }
            }
        }
        return sa.empty() ? true:false;
    }
};
