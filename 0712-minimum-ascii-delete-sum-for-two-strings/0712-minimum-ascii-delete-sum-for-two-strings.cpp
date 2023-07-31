class Solution {
public:
    int minimumDeleteSum(string text1, string text2) {
         vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
        for(int i=0; i<=text1.length(); i++){
            dp[i][0] = 0;
        }
        for(int j=0; j<=text2.length(); j++){
            dp[0][j] = 0;
        }
        for(int i=1; i<=text1.length(); i++){
             for(int j=1; j<=text2.length(); j++){
                 if(text1[i-1]==text2[j-1]) dp[i][j] = text1[i-1]+ dp[i-1][j-1];
                 else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
             }
        }
      int sum = 0;
      for(int i=0; i<text1.length(); i++) sum += text1[i];
       for(int i=0; i<text2.length(); i++) sum += text2[i];
      
      return sum - 2*dp[text1.length()][text2.length()];
    }
};