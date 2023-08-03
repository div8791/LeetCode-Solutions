class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
      deque<int> dq;
      int n = nums.size();
      if(k>n){
        ans.push_back(*max_element(nums.begin(),nums.end()));
      }
      int i=0, j=0;
      while(j<n){
        while(dq.size()>0 && dq.back()<nums[j]) dq.pop_back();
        dq.push_back(nums[j]);
        if(j-i+1<k) j++;
        else if(j-i+1==k){
          ans.push_back(dq.front());
          if(dq.front()==nums[i]){
            dq.pop_front();
          }
          i++;
          j++;
        }
      }
      return ans;
    }
};