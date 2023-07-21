class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi = 1;
        for(int i=0; i<=n-1; i++){
            for(int j=0; j<=i-1; j++){
                if(nums[i]>nums[j] && dp[i]<1+dp[j]){
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                }
                else if(nums[i]>nums[j] && dp[i]==1+dp[j]){
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int c = 0;
        for(int i=0; i<n; i++){
            if(dp[i]==maxi) c+=cnt[i];
        }
        return c;
       
    }
};