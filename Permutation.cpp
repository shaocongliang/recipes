#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string getPermutation(int n, int k) {
    count_ = 0;
    createSeq(n, nums_);
    selected_.resize(n);
    std::fill(selected_.begin(), selected_.end(), 0);
    permutation(nums_, selected_, 0, n, k);
    std::cout << "count " << count_ << std::endl;
    return permu_;
  }

 private:
  std::vector<int> nums_;
  std::vector<int> selected_;
  int count_;
  std::string permu_;
  void createSeq(const int N, std::vector<int> &nums) {
    for (int i = 0; i < N; ++i) {
      nums.push_back(i + 1);
    }
  }
  void permutation(std::vector<int> &nums, std::vector<int> selected, int pos,
                   const int N, const int k) {
    if (pos == nums.size()) {
      count_++;
      if (k == count_) {
        toString(selected);
      }
      return;
    }
    for (int i = 1; i <= nums.size(); ++i) {
      if (true == inUsed(selected, i)) {
        continue;
      }
      selected[pos] = i;
      permutation(nums, selected, pos + 1, N, k);
      if (count_ == k) {
        return;
      }
    }
  }
  bool inUsed(std::vector<int> selected, const int num) {
    auto iter = std::find(selected.begin(), selected.end(), num);
    if (iter == selected.end()) {
      return false;
    }
    return true;
  }
  void toString(const std::vector<int> &nums) {
    for (auto it : nums) {
      permu_ += std::to_string(it);
    }
  }
};

int main(int argc, char **argv) {
  const int N = 4;
  Solution s;
  std::cout << s.getPermutation(9, 37098) << std::endl;
  return 0;
}