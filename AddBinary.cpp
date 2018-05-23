class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length()) {
            std::swap(a, b);
        }
        std::string padding(a.length()-b.length(), '0');
        b = padding + b;
        int sum = 0;
        int val = 0;
        int carrybit = 0;
        for(int i = a.size() -1; i >= 0; --i) {
            sum = a[i] + b[i] - '0' - '0' + carrybit;
            val = sum % 2;
            carrybit = sum/2;
            a[i] = val + '0';
        }
        if(carrybit) {
            a = std::to_string(carrybit) + a;
        }
        return a;
    }
};