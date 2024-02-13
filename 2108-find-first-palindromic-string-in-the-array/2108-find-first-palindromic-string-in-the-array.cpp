class Solution {
public:
  bool isPallindrome(string t){
    string p = t;
    reverse(p.begin(),p.end());
    if(p==t) return true;
    return false;
  }
    string firstPalindrome(vector<string>& words) {
       string ans = "";
      for(int i=0; i<words.size(); i++){
        if(isPallindrome(words[i])){ 
          ans = words[i];
          break;
        }
      }
      return ans;
    }
};