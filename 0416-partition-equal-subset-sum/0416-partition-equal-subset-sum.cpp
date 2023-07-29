class Solution {
public:
  bool helper(vector<int>& nums, int i, int t, vector<vector<int>> &dp){
    if(t==0) return true;
    if(i==0) return t==nums[0];
    if(dp[i][t]!=-1) return dp[i][t];
    int nottake = helper(nums,i-1,t,dp);
    int take = false;
    if(nums[i]<=t) take = helper(nums,i-1,t-nums[i],dp);
    
    return dp[i][t]= nottake || take;
  }
    bool canPartition(vector<int>& nums) {
      int n = nums.size();
      int s = 0;
      for(int i=0; i<n; i++) s += nums[i];
        vector<vector<int>> dp(n,vector<int> ((s/2)+1,-1));
      if(s%2!=0) return false;
      return helper(nums,n-1,s/2,dp);
    }
};