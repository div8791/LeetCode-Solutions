class Solution {
public: 
    void solve(string &digits, int i, string map[], string &temp, vector<string> &ans){
        if(i>=digits.length()){
            ans.push_back(temp);
            return ;
        }
        int num = digits[i]-'0';
        string value = map[num];
        for(int j=0; j<value.length(); j++){
            temp.push_back(value[j]);
            solve(digits,i+1,map,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        string temp = "";
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,0,map,temp,ans);
        return ans;
    }
};