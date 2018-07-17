#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;
int MaxBase(const string &lhs, const string &rhs){
    return lhs.size()-1 < rhs.size() -1? lhs.size()-1:rhs.size()-1;
}

string BigIntegerSum(const string &lhs, const string &rhs){

}

pair<int, int> Split(string num1, int base){

}

string Karastuba(const string &lhs, const string &rhs){
    int base = MaxBase(lhs, rhs);
    int m2 = std::floor(base/2);
}

int main(int argc, char **argv){
    return 0;
}