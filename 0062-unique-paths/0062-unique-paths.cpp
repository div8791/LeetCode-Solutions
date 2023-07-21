class Solution {
public:
  // int helper(int m, int n, int i, int j, vector<vector<int>> &dp){
//     if(i==0 && j==0){
//       return 1;
//     }
//     if(i<0 || j<0) return 0;
    
//     if(dp[i][j]!=-1) return dp[i][j];
    
//     int up = helper(m,n,i-1,j,dp);
//     int down = helper(m,n,i,j-1,dp);
//     return dp[i][j] =  up + down;
//   }
    int uniquePaths(int m, int n) {
      vector<vector<int>> dp(m,vector<int> (n,0));
      // dp[0][0] = 1;
      for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
          if(i==0 && j==0){
            dp[0][0] = 1;
            continue;
          }
          int u=0, d=0;
          if(i>0){
            u = dp[i-1][j];
          }
          if(j>0){
            d = dp[i][j-1];
          }
          dp[i][j] = u+d;
        }
      }
        return dp[m-1][n-1];
    }
};