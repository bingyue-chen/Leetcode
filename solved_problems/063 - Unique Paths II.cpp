class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        dp[0][1] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!obstacleGrid[i][j]){
                    dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j];
                }
            }
        }
        
        return dp[m][n];
    }
};