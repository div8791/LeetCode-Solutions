class Solution {
public:
  bool helper(int i, string &s, unordered_set<string> &set, vector<int> &dp){
    int l = s.length();
    if(i==l) return true;
    if(dp[i]!=-1) return dp[i];
    for(int j=i; j<l; j++){
      if(set.count(s.substr(i,j-i+1)) && helper(j+1,s,set,dp)){
        dp[i] = true;
        return dp[i];
      }
    }
    return dp[i]= false;
  }
    bool wordBreak(string s, vector<string>& wordDict) {
      unordered_set<string> set(wordDict.begin(),wordDict.end());
      vector<int> dp(s.size(),-1);
        return helper(0,s,set,dp);
    }
};