class Solution {
public:
    void solve(vector<int>& nums,int i, vector<int> &temp,vector<vector<int>> &ans){
      ans.push_back(temp);
      for(int j=i; j<nums.size(); j++){
        if(j!=i and nums[j]==nums[j-1]) continue;
        temp.push_back(nums[j]);
      solve(nums,j+1,temp,ans);
      temp.pop_back();
      }
      
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
      vector<int> temp;
      int n = nums.size();
      sort(nums.begin(),nums.end());
      solve(nums,0,temp,ans);
      return ans;
    }
};