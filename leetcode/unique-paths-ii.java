class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int ans = 0;
        int m = obstacleGrid.length+1;
        int n = obstacleGrid[0].length+1;
        int[][] paths = new int[m][n];
        boolean obs = false;
        for(int i = 1; i < n; ++i){
            if(obstacleGrid[0][i-1] == 1) obs = true;
            if(obs) paths[1][i] = 0;
            else paths[1][i] = 1;
        }
        obs = false;
        for(int i = 1; i < m; ++i){
            if(obstacleGrid[i-1][0] == 1) obs = true;
            if(obs) paths[i][1] = 0;
            else paths[i][1] = 1;
        }
        for(int i = 2; i < m; ++i){
            for(int j = 2; j < n; ++j){
                if(obstacleGrid[i-1][j-1] == 1)
                    paths[i][j] = 0;
                else{
                    paths[i][j] = paths[i-1][j] + paths[i][j-1];
                }
            }
        }
        return paths[m-1][n-1];
    }
}
