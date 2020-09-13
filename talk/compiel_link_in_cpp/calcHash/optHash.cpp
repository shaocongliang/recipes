#include <iostream>
#include <string>
int calc_hash(const char *s) {
  static const int N = 100;
  int ret = 1;
  while (*s) {
    ret = ret * 131 + *s;
    ++s;
  }
  std::cout << ret << std::endl;
  ret %= N;
  if (ret < 0) ret += N;  //注意这句
  return ret;
}
#include <stdio.h>
int main(void) {
  std::cout << calc_hash(std::string(2147483646, 'h').c_str()) << std::endl;
  return 0;
}