class Solution {
public:
  bool isPallindrome(int l, int h, string s){
    while(l<=h){
      if(s[l++]!=s[h--]) return false;
    }
    return true;
  }
  void solve(string s, int i, vector<vector<string>> &ans, vector<string> &temp){
    if(i==s.length()){
      ans.push_back(temp);
      return ;
    }
    for(int j=i; j<s.length(); j++){
      if(isPallindrome(i,j,s)){
        temp.push_back(s.substr(i,j-i+1));
        solve(s,j+1,ans,temp);
        temp.pop_back();
      }
    }
  }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
      vector<string> temp;
      solve(s,0,ans,temp);
      return ans;
    }
};