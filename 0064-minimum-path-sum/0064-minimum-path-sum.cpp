class Solution {
public:
    // int solve(vector<vector<int>>& grid, int i, int j,vector<vector<int>> &dp){
    //   if(i==0 && j==0){
    //     return grid[0][0];
    //   }
    //   if(i<0 || j<0) return 1e9;
    //   if(dp[i][j]!=-1) return dp[i][j];
    //   int up = grid[i][j] + solve(grid,i-1,j,dp);
    //   int left = grid[i][j] + solve(grid,i,j-1,dp);
    //   return dp[i][j] = min(up,left);
    // }
    int minPathSum(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>> dp(m,vector<int> (n,-1));
      for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
          if(i==0 && j==0){
            dp[0][0] = grid[0][0];
            continue;
          }
          else{
            int u=0,d=0;
            if(i>0){
              u += grid[i][j] + dp[i-1][j];
            }
            else{
              u += 1e9;
            }
            if(j>0){
              d += grid[i][j] + dp[i][j-1];
            }
            else{
d += 1e9;}
            dp[i][j] = min(u,d);
          }
        }
      }
        return dp[m-1][n-1];
    }
};