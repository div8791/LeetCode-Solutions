class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int mx = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
             mx = max(sum,mx);
            if(sum<0){
                sum = 0;
            }
           
        }
        return mx;
    }
};