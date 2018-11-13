class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
       maxarea = 0;
       int max =0; 
       ans.resize(grid.size());
       for(int i = 0; i < grid.size(); ++i)
            ans[i].resize(grid[0].size());
        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[i].size(); ++j){
                ans[i][j] = false;
            }
       for(int i = 0; i < grid.size(); ++i){
           for(int j = 0; j < grid[i].size(); ++j){
               if(grid[i][j] == 1 && ans[i][j] == false){
                   dfs(i, j, grid, max);
               }
               if(max > maxarea)
                    maxarea = max;
               max = 0;
           }
       }
       return maxarea;
    }
private:
    void dfs(int i, int j, const vector<vector<int>> &grid, int &max){
        ans[i][j] = true;
        max += 1;
        if(i-1 >=0 && grid[i-1][j] == 1 && ans[i-1][j] == false)
            dfs(i-1, j, grid, max);
        if(i+1 < grid.size() && grid[i+1][j] == 1 && ans[i+1][j] == false)
            dfs(i+1, j, grid, max);
        if(j-1 >= 0 && grid[i][j-1] == 1 && ans[i][j-1] == false)
            dfs(i, j-1, grid, max);
        if(j+1 < grid[i].size() && grid[i][j+1] == 1 && ans[i][j+1] == false)
            dfs(i, j+1, grid, max);
    }
    vector<vector<bool>> ans;
    int maxarea;
};
