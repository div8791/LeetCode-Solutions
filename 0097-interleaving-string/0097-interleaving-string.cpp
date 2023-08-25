class Solution {
public:
  bool helper(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<vector<int>>> &dp){
    int n = s1.length();
    int m = s2.length();
    int N = s3.length();
    if(n+m!=N) return false;
    if(i==n && j==m && k==N) return true;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(k>=N) return false;
    bool res = false;
    if(s1[i]==s3[k]) res = helper(i+1,j,k+1,s1,s2,s3,dp);
    if(res==true) return dp[i][j][k]= true;
    if(s2[j]==s3[k]) res = helper(i,j+1,k+1,s1,s2,s3,dp);
    
    return dp[i][j][k]= res;
  }
    bool isInterleave(string s1, string s2, string s3) {
      vector<vector<vector<int>>> dp(101,vector<vector<int>> (101, vector<int> (201,-1)));
        return helper(0,0,0,s1,s2,s3,dp);
    }
};