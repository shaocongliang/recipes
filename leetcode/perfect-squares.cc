class Solution {
 public:
  int numSquares(int n) {
    if(n==0) return 1;
    vector<int> v1;
    vector<int> v2;
    v1.resize(n+1);
    for(int i = 0; i <= n; ++i){
      v1[i] = i;
    }
    int k = sqrt(n);
    v2.resize(k+1);
    for(int i = 1; i <=k; ++i){
      v2[i] = i*i;
    }
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= k && j < i && v2[j]<=i; ++j){
        v1[i] = min(v1[i], 1 + v1[i-v2[j]]);
      }
    }
    return v1[n];
  }
};
