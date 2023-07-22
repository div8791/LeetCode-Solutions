class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> temp(n,-1);
      for(int i=0; i<n; i++){
        temp[i] = i+1;
      }
      sort(temp.begin(),temp.end());
      while(k>1){
        next_permutation(temp.begin(),temp.end());
        k--;
      }
      // for(int i=0; i<n; i++){
      //   cout<<temp[i]<<" ";
      // }
      string ans = "";
      for(int i=0; i<n; i++){
        ans += to_string(temp[i]);
      }
      return ans;
    }
};