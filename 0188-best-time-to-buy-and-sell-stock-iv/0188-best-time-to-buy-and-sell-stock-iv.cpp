class Solution {
public:
  int helper(vector<int> &prices, int buy, int i, int limit,  vector<vector<vector<int>>> &dp){
    if(i==prices.size()) return 0;
    if(limit==0) return 0;
    if(dp[i][buy][limit]!=-1) return dp[i][buy][limit];
    int profit;
    if(buy==1){
      profit = max(-prices[i]+helper(prices,0,i+1,limit,dp),helper(prices,1,i+1,limit,dp));
    }
    else{
      profit = max(prices[i]+helper(prices,1,i+1,limit-1,dp),helper(prices,0,i+1,limit,dp));
    }
    return dp[i][buy][limit]= profit;
  }
    int maxProfit(int k, vector<int>& prices) {
      vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (2,vector<int> (k+1,-1)));
        return helper(prices,1,0,k,dp);
    }
};