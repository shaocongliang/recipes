#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
namespace scliang {
template <class BidirIt>
bool next_permutation(BidirIt first, BidirIt last) {
  if (first == last) return false;
  BidirIt i = last;
  if (first == --i) return false;

  while (true) {
    BidirIt i1, i2;

    i1 = i;
    if (*--i < *i1) {
      i2 = last;
      assert(std::distance(i, i1) == 1);
      while (!(*i < *--i2))
        ;
      if (*i2 == *i1) {
        //        std::cout << "i2 equal i1" << std::endl;
      }
      std::iter_swap(i, i2);
      std::reverse(i1, last);
      return true;
    }
    if (i == first) {
      std::reverse(first, last);
      return false;
    }
  }
}
}  // namespace scliang
int main(int argc, char **argv) {
  std::string s("123456");
  std::cout << s << std::endl;
  while (scliang::next_permutation(s.begin(), s.end())) {
    std::cout << s << std::endl;
  }
  return 0;
}