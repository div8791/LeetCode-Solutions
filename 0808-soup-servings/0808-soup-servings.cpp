class Solution {
public:
  double probabilityA(int A, int B, vector<vector<double>> &dp){
    if(A<=0 && B<=0) return 0.5;
    if(A<=0) return 1.0;
    if(B<=0) return 0.0;
    if(dp[A][B]!=-1.0) return dp[A][B];
    vector<pair<int,int>> op = {{100,0},{75,25},{50,50},{25,75}};
    double prob = 0.0;
    for(auto &p: op){
      int A_taken = p.first;
      int B_taken = p.second;
      prob += probabilityA(A-A_taken,B-B_taken,dp);
    }
    return dp[A][B] = (0.25 * prob);
  }
    double soupServings(int n) {
      if(n>=5000) return 1.0;
      vector<vector<double>> dp(n+1,vector<double> (n+1,-1.0));
        return probabilityA(n,n,dp);
    }
};