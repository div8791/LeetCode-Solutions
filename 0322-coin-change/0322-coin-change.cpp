class Solution {
public:
  int helper(vector<int> &coins, int amt, int i, vector<vector<int>> &dp){
    if(i==0){
      if(amt%coins[0]==0){
        return amt/coins[0];
      }
      return 1e8;
    }
    if(dp[i][amt]!=-1) return dp[i][amt];
    int skip = helper(coins,amt,i-1,dp);
    int take = 1e8;
    if(coins[i]<=amt){
      take = 1+helper(coins,amt-coins[i],i,dp);
    }
    return dp[i][amt]= min(skip,take);
  }
    int coinChange(vector<int>& coins, int amount) {
      int n = coins.size();
      vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans = helper(coins,amount,n-1,dp);
      if(ans>=1e8) return -1;
      return ans;
    }
};