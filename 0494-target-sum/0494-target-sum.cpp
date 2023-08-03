class Solution {
public:
  int helper(vector<int>& nums, int t, int i, vector<vector<int>> &dp){
    if(i==0){
      if(t==0 && nums[0]==0){
        return 2;
      }
      if(t==0 || t==nums[0]) return 1;
      return 0;
    }
    if(dp[i][t]!=-1) return dp[i][t];
    int skip = helper(nums,t,i-1,dp);
    int take = 0;
    if(nums[i]<=t) take = helper(nums,t-nums[i],i-1,dp);
    
    return dp[i][t]= skip+take;
  }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
      int n=nums.size();
      for(int i=0; i<n; i++) totalSum += nums[i];
      if(totalSum<target || (totalSum-target)%2) return 0;
      int t = (totalSum-target)/2;
      vector<vector<int>> dp(n,vector<int> (t+1,-1));
      return helper(nums,t,n-1,dp);
    }
};