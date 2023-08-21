class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int l = s.length();
      for(int i=l/2; i>=1; i--){
        if(l%i==0){
          int times = l/i;
          string pattern = s.substr(0,i);
          string newstr = "";
          while(times--){
            newstr += pattern;
          }
          if(newstr==s) return true;
        }
      }
      return false;
    }
};