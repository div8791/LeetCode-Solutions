class Solution {
public:
  int calculate_firstScore(vector<int>& nums, int i, int j){
    if(i>j) return 0;
    if(i==j) return nums[i];
    
    int currScore = max(nums[i]+min(calculate_firstScore(nums,i+2,j),calculate_firstScore(nums,i+1,j-1)),nums[j] + min(calculate_firstScore(nums,i,j-2),calculate_firstScore(nums,i+1,j-1)));
    
    return currScore;
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
      int firstScore = calculate_firstScore(nums,0,nums.size()-1);
      return firstScore >= totalScore-firstScore;
    }
};