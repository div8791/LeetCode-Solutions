class Solution {
public:
  int helper(vector<int> &prices, int n, int i, int buy, int limit,vector<vector<vector<int>>> &dp){
    if(i==n) return 0;
    if(limit==0) return 0;
    if(dp[i][buy][limit]!=-1) return dp[i][buy][limit];
    int profit;
    if(buy==1){
      profit = max(-prices[i]+helper(prices,n,i+1,0,limit,dp),helper(prices,n,i+1,1,limit,dp));
    }
    else{
      profit = max(prices[i]+helper(prices,n,i+1,1,limit-1,dp),helper(prices,n,i+1,0,limit,dp));
    }
    return dp[i][buy][limit] = profit;
  }
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
        return helper(prices,n,0,1,2,dp);
    }
};