class Solution {
public:
  int lis(vector<vector<int>> &pairs, int curr, int prev, int n, vector<vector<int>> &dp){
    if(curr==n) return 0;
    if(prev!=-1 &&  dp[curr][prev+1]!=-1) return dp[curr][prev+1];
    int take = -1e9;
    if(prev==-1 || pairs[curr][0]>pairs[prev][1]) {
      take = 1 + lis(pairs,curr+1,curr,n,dp);
    }
    
    int nottake = lis(pairs,curr+1,prev,n,dp);
    
    return dp[curr][prev+1] = max(take,nottake);
  }
    int findLongestChain(vector<vector<int>>& pairs) {
        
      int n = pairs.size();
      vector<vector<int>> dp(n,vector<int> (n+1,-1));
      sort(pairs.begin(),pairs.end());
      return lis(pairs,0,-1,n,dp);
    }
};