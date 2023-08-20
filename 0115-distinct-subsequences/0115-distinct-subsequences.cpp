class Solution {
public:
  int helper(string s, string t, int i, int j,  vector<vector<int>> &dp){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) return dp[i][j]= helper(s,t,i-1,j-1,dp) + helper(s,t,i-1,j,dp);
    else return dp[i][j]= helper(s,t,i-1,j,dp);
  }
    int numDistinct(string s, string t) {
      int i=s.length();
      int j = t.length();
      vector<vector<int>> dp(i,vector<int> (j,-1));
        return helper(s,t,i-1,j-1,dp);
    }
};