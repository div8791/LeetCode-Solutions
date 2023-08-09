class Solution {
public:
  bool isPossible(vector<int>& nums, int m, int p){
    int i=0, count=0;
    while(i<nums.size()-1){
      if(nums[i+1]-nums[i]<=m){
        count++;
        i = i+2;
      }
      else i++;
    }
    return count>=p;
  }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
      int s = 0;
      int result = 0;
      int n  = nums.size();
      int e = nums[n-1] - nums[0];
      while(s<=e){
        int mid = s + (e-s)/2;
        if(isPossible(nums,mid,p)){
          result = mid;
          e = mid-1;
        }
        else s = mid+1;
      }
      return result;
    }
};