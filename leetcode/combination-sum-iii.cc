class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    for(int i = 1; i <= 9-k+1; i++){
      std::vector<int> v;
      v.push_back(i);
      dfs(1, i, i+1, v, k, n);
      v.pop_back();
    }
    return ans;
  }
 private:
  void dfs(int count, int sum, int val, vector<int> v, const int k, const int n){
    if(count == k) {
      if(sum == n) ans.push_back(v);
      return;
    }
    for(;val <=9; val++){
        v.push_back(val);
        dfs(count+1, sum+val, val+1, v, k, n);
        v.pop_back();
    }
  }
  vector<vector<int>> ans;
};
