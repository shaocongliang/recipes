class Solution {
 public:
  vector<string> reorderLogFiles(vector<string> &logs) {
    vector<string> digits;
    vector<string> letters;
    const char *tok(" ");
    for (auto it : logs) {
      vector<string> toks;
      SplitString(it, toks, tok);
      if (isdigit(toks[1][0])) {
        digits.push_back(it);
      } else {
        int i;
        for (i = 0; i < letters.size(); ++i) {
          int pos1 = letters[i].find_first_of(" ");
          string sub1 = letters[i].substr(pos1 + 1);
          int pos2 = it.find_first_of(" ");
          string sub2 = it.substr(pos2 + 1);
          if (sub2 < sub1) {
            letters.insert(letters.begin() + i, it);
            break;
          }
        }
        if(i == letters.size())
          letters.push_back(it);
      }
    }
    for (int i = 0; i < digits.size(); ++i)
      letters.push_back(digits[i]);
    return letters;
  }
 private:
  void SplitString(const std::string &s, std::vector<std::string> &v, const std::string &c) {
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2) {
      v.push_back(s.substr(pos1, pos2 - pos1));

      pos1 = pos2 + c.size();
      pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
      v.push_back(s.substr(pos1));

  }
};
