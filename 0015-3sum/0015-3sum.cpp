class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
      sort(nums.begin(),nums.end());
      int n = nums.size();
      set<vector<int>> s;
      for(int i=0; i<n-2; i++){
        int l = i+1;
        int r = n-1;
        int x = nums[i];
        while(l<r){
          if(x+nums[l]+nums[r]==0){
            s.insert({x,nums[l],nums[r]});
            l++;
            r--;
          }
          else if(x+nums[l]+nums[r]<0){
            l++;
          }
          else r--;
        }
      }
      for(auto i: s){
        ans.push_back(i);
      }
      return ans;
    }
};