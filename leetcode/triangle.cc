class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
   vector<vector<int>> sums;
   sums.resize(triangle.size());
   for(int i = 0; i < triangle.size(); ++i){
     sums[i].resize(triangle[i].size());
   }
   for(int i = 0; i < triangle.size(); ++i){
     for(int j = 0; j < triangle[i].size(); ++j){
        sums[i][j] = triangle[i][j];
     }
   }
   sums[0][0] = triangle[0][0];
   for(int i = 1; i < triangle.size(); ++i){
     int m = triangle[i].size()-1;
     for(int j = 0; j <= m; ++j){
       if(j == 0) sums[i][j] += sums[i-1][j];
       else if(j == m) sums[i][j] += sums[i-1][j-1];
       else {
          sums[i][j] += min(sums[i-1][j-1], sums[i-1][j]);
       }
     }
   }
   int ans = INT_MAX;
   for(auto it : sums[sums.size()-1]){
      if(it < ans) ans = it;
   }
   return ans;
  }
};
