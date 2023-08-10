class Solution {
public:
  int helper(int i, int j, string &s1, string &s2,  vector<vector<int>> &dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return dp[i][j]= (1 + helper(i-1,j-1,s1,s2,dp));
    
    else return dp[i][j]= max(helper(i-1,j,s1,s2,dp),helper(i,j-1,s1,s2,dp));
  }
    int longestCommonSubsequence(string text1, string text2) {
      int l1 = text1.length(), l2 = text2.length();
      vector<vector<int>> dp(l1,vector<int> (l2,-1));
        return helper(l1-1,l2-1,text1,text2,dp);
    }
};