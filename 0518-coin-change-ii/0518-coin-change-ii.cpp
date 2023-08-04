class Solution {
public:
  int helper(vector<int>& coins, int amt, int i,   vector<vector<int>> &dp){
    if(i==0){
      return amt%coins[0]==0;
    }
    if(dp[i][amt]!=-1) return dp[i][amt];
    int skip = helper(coins,amt,i-1,dp);
    int take = 0;
    if(coins[i]<=amt){
      take = helper(coins,amt-coins[i],i,dp);
    }
    return dp[i][amt]= skip+take;
  }
    int change(int amount, vector<int>& coins) {
      int n = coins.size();
         vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return helper(coins,amount,n-1,dp);
    }
};