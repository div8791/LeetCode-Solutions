class Solution {
public:
  int lcs(string s, string t, int i, int j){
   vector<vector<int>> dp(i+1,vector<int> (j+1,0));
    for(int x=0; x<=i; x++) dp[x][0] = 0;
    for(int y=0; y<=j; y++) dp[0][y] = 0;
    
    for(int x=1; x<=i; x++){
      for(int y=1; y<=j; y++){
        if(s[x-1]==t[y-1]){
          dp[x][y] = 1 + dp[x-1][y-1];
        }
        else dp[x][y] = max(dp[x-1][y],dp[x][y-1]);
      }
    }
    return dp[i][j];
  }
  int helper(string s, string t){
    int i=s.length();
    int j=t.length();
    return i+j-2*lcs(s,t,i,j);
  }
    int minDistance(string word1, string word2) {
        return helper(word1,word2);
    }
};