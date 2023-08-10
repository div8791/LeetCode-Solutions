class Solution {
public:
//   int helper(int i, int j, string &s1, string &s2,  vector<vector<int>> &dp){
//     if(i<0 || j<0) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(s1[i]==s2[j]) return dp[i][j]= (1 + helper(i-1,j-1,s1,s2,dp));
    
//     else return dp[i][j]= max(helper(i-1,j,s1,s2,dp),helper(i,j-1,s1,s2,dp));
//   }
    int longestCommonSubsequence(string text1, string text2) {
      int l1 = text1.length(), l2 = text2.length();
      vector<vector<int>> dp(l1+1,vector<int> (l2+1,0));
      for(int i=0; i<=l1; i++) dp[i][0] = 0;
  
      for(int j=0; j<=l2; j++) dp[0][j] = 0;
      
      for(int i=1; i<=l1; i++){
        for(int j=1; j<=l2; j++){
          if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
          else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
      }
        return dp[l1][l2];
    }
};