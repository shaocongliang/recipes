class Solution {
public:
    string countAndSay(int n) {
        std::string in("1");
        if(n == 1) {
            return in;
        }

        for(int i = 1; i < n; i++) {
            std::string out;
            for(int j = 0; j < in.size(); ++j) {
                int len = 0;
                if(string::npos == in.find_first_not_of(in[j], j)) {
                    len = in.size() - j;
                    out += std::to_string(len) + in[j];
                    j = in.size();

                }
                else {
                    int tail = in.find_first_not_of(in[j], j);
                    len = tail - j;
                    out += std::to_string(len) + in[j];
                    j = tail-1;
                }
               
            }
            in = out;
        }
        return in;
    }
};