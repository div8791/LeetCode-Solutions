class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      int n1 = nums1.size();
      int n2 = nums2.size();
       vector<int> ans;
      stack<int> s;
      unordered_map<int,int> mp;
      for(int i=n2-1; i>=0; i--){
        if(s.empty()){
          mp[nums2[i]] = -1;
        }
        else if(!s.empty() && s.top()>nums2[i]){
          mp[nums2[i]] = s.top();
        }
        else if(!s.empty() && s.top()<=nums2[i]){
          while(!s.empty() && s.top()<=nums2[i]){
            s.pop();
          }
          if(s.empty()){
            mp[nums2[i]] = -1;
          }
          else{
            mp[nums2[i]] = s.top();
          }
        }
        s.push(nums2[i]);
      }
      for(int i=0; i<n1; i++){
        ans.push_back(mp[nums1[i]]);
      }
      return ans;
    }
};