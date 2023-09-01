class Solution {
public:
  int countSet(int n){
    int c = 0;
    while(n){
      n &= (n-1);
      c++;
    }
    return c;
  }
    vector<int> countBits(int n) {
        vector<int> ans;
     // ans[0] = 0;
      for(int i=0; i<=n; i++){
        ans.push_back(countSet(i));
      }
      return ans;
    }
};