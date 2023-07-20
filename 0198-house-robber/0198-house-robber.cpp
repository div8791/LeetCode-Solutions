class Solution {
public:
  // int solve(vector<int> &nums, int n, int i, vector<int> &dp){
  //   if(i==0){
  //     return nums[i];
  //   }
  //   if(i<0) return 0;
  //   if(dp[i]!=-1) return dp[i];
  //   int nottake = solve(nums,n,i-1,dp);
  //   int take = nums[i] + solve(nums,n,i-2,dp);
  //   return dp[i] = max(nottake,take);
  // }
    int rob(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n,0);
      dp[0] = nums[0];
      for(int i=1; i<n; i++){
        int take = nums[i];
        if(i>1) take += dp[i-2];
        int nottake = dp[i-1];
        dp[i] = max(take,nottake);
      }
      return dp[n-1];
    }
};