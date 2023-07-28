class Solution {
public:
  int calculate_firstScore(vector<int>& nums, int i, int j,vector<vector<int>>& dp){
    if(i>j) return 0;
    if(i==j) return nums[i];
    if(dp[i][j]!=-1) return dp[i][j];
    int currScore = max(nums[i]+min(calculate_firstScore(nums,i+2,j,dp),calculate_firstScore(nums,i+1,j-1,dp)),nums[j] + min(calculate_firstScore(nums,i,j-2,dp),calculate_firstScore(nums,i+1,j-1,dp)));
    
    return dp[i][j]= currScore;
  }
  int calculate_totalScore(vector<int>& nums){
    int curr = 0;
    for(int i=0; i<nums.size(); i++){
      curr += nums[i];
    }
    return curr;
  }
    bool PredictTheWinner(vector<int>& nums) {
        int totalScore = calculate_totalScore(nums);
      int n = nums.size();
      vector<vector<int>> dp(n,vector<int> (n,-1));
      int firstScore = calculate_firstScore(nums,0,nums.size()-1,dp);
      return firstScore >= totalScore-firstScore;
    }
};