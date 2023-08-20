class Solution {
public:
  int helper(string s, string t, int i, int j,  vector<vector<int>> &dp){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) return dp[i][j]= helper(s,t,i-1,j-1,dp);
    else{
      return dp[i][j]= min(min(1+helper(s,t,i,j-1,dp),1+helper(s,t,i-1,j,dp)),1+helper(s,t,i-1,j-1,dp));
    }
  }
    int minDistance(string word1, string word2) {
        int i=word1.length();
      int j = word2.length();
      vector<vector<int>> dp(i,vector<int> (j,-1));
      return helper(word1,word2,i-1,j-1,dp);
    }
};