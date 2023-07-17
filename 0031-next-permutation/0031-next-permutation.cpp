class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i1 = -1, i2 = -1;
        int n = nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                i1 = i;
                break;
            }
        }
        if(i1<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=n-1; i>=0; i--){
                if(nums[i]>nums[i1]){
                    i2 = i;
                    break;
                }
            }
            swap(nums[i1],nums[i2]);
            reverse(nums.begin()+i1+1,nums.end());
        }
    }
};