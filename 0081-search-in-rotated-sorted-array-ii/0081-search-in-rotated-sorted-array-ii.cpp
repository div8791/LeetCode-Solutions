class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m]==target){
                return true;
            }
            if(nums[s]==nums[m] && nums[e]==nums[m]){
                s++;
                e--;
            }
           else if(nums[s]<=nums[m]){
                if(target<nums[m] && target>=nums[s]){
                    e = m-1;
                }
                else{
                    s = m+1;
                }
            }
            else{
                if(target>nums[m] && target<=nums[e]){
                    s = m+1;
                }
                else{
                    e = m-1;
                }
            }
        }
        return false;
    }
};