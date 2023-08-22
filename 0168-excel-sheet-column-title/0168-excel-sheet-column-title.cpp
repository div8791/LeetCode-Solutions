class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
      while(columnNumber>0){
        columnNumber--;
        int rem = columnNumber % 26;
        res += rem + 'A';
        columnNumber /= 26;
      }
      reverse(res.begin(),res.end());
      return res;
    }
};