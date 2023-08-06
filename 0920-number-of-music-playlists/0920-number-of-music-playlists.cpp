class Solution {
public:
  long long int Mod = 1e9+7;
long long solve(int count_song, int count_unique, int n, int goal, int k, vector<vector<int>> &dp){
    if(count_song==goal){
      if(count_unique==n) return 1;
      return 0;
    }
  if(dp[count_song][count_unique]!=-1) return dp[count_song][count_unique];
    long long result = 0;
  if(count_unique<n)
    result += (n-count_unique)*solve(count_song+1,count_unique+1,n,goal,k,dp);
  
  if(count_unique>k)
    result += (count_unique-k)*solve(count_song+1,count_unique,n,goal,k,dp);
    
    return dp[count_song][count_unique] = result%Mod;
  }
    int numMusicPlaylists(int n, int goal, int k) {
      vector<vector<int>> dp(101,vector<int> (101,-1));
        return solve(0,0,n,goal,k,dp)%Mod;
    }
};