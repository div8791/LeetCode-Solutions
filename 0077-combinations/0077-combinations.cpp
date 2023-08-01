class Solution {
public:
  void solve(vector<int> &temp, int i, vector<vector<int>> &ans, int k, int n){
    if(temp.size()==k){
       ans.push_back(temp);
      return ;
    }
      for(int j=i; j<n+1; j++){
        temp.push_back(j);
        solve(temp,j+1,ans,k,n);
        temp.pop_back();
      }
  }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
      vector<vector<int>> ans;
      solve(temp,1,ans,k,n);
      return ans;
    }
};