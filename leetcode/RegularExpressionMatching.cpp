#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
bool isMatch(const string &s, const string &p){
    if(p.size() > 1 && p[1] == '*') {
        if(s[0] == p[0] || p[0] == '.')   return isMatch(s.substr(1), p);
        if(s[0] != p[0])   return isMatch(s, p.substr(2));
    } 
    else if(p.size() > 1 && p[1] != '*'){
        if(p[0] == '.' || p[0] == s[0]) return isMatch(s.substr(1), p.substr(1));
        else return false;
    }
    else{
        return s.size() == 1 && p.size() == 1 && (p[0] == '.' || s[0] == p[0]);
    }
}
*/
bool isMatch(const string &s, const string &p){
    cout << "p " << p << " s " << s << endl;
    if(p.empty()) return s.empty();
    if(p.size() > 1 && p[1] == '*') {
        return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
    } 
    else{
        return s.empty() == false && (p[0] == '.' || p[0] == s[0]) && isMatch(s.substr(1), p.substr(1));
    }
}

int main(int argc, char **argv){
    cout << isMatch("aabc", "aa*.*b*.c*a*") << endl;
    return 0;
}