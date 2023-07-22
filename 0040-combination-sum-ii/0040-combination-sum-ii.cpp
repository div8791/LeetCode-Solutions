class Solution {
public:
  void solve(vector<int>& candidates, int target, int i, vector<vector<int>> &ans, vector<int> &temp){
    if(target==0){
      ans.push_back(temp);
      return ;
    }
    for(int j=i; j<candidates.size(); j++){
      if(j>i and candidates[j]==candidates[j-1]) continue;
      if(candidates[j]>target) return;
        temp.push_back(candidates[j]);
        solve(candidates,target-candidates[j],j+1,ans,temp);
        temp.pop_back();
    }
    
  }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
      sort(candidates.begin(),candidates.end());
      vector<int> temp;
      solve(candidates,target,0,ans,temp);
      return ans;
    }
};