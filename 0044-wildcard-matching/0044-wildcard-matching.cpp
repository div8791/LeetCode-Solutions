class Solution {
public:
  bool helper(string &s, string &p, int i, int j, vector<vector<int>> &dp){
    if(i<0 && j<0) return true;
    
    if(i<0 && j>=0) return false;
    
    if(i>=0 && j<0){
      for(int k=0; k<=i; k++){
        if(p[k]!='*') return false;
      }
      return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(p[i]==s[j] || p[i]=='?') return dp[i][j]= helper(s,p,i-1,j-1,dp);
    
    if(p[i]=='*') {
      return dp[i][j] = (helper(s,p,i-1,j,dp) || helper(s,p,i,j-1,dp));
    }
    return false;
  }
    bool isMatch(string s, string p) {
      int i = p.length()-1;
      int j = s.length()-1;
      vector<vector<int>> dp(i+1,vector<int> (j+1,-1));
        return helper(s,p,i,j,dp);
    }
};