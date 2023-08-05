class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
      int l = s.length();
      int i=0;
      while(i<l){
        while(i<l && s[i]==' ') i++;
        if(i>=l) break;
        int j=i;
        while(j<l && s[j]!=' ') j++;
        string t = s.substr(i,j-i);
        if(ans.length()==0) ans = t;
        else{
          ans = t + ' ' + ans;
        }
        i = j+1;
      }
      return ans;
    }
};