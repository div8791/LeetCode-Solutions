class Solution {
public:
  bool isSafe(int row, int col, vector<string> &boards, int n){
    int x = row;
    int y = col;
    while(y>=0){
      if(boards[x][y]=='Q') return false;
      y--;
    }
    x = row, y = col;
    while(x>=0 && y>=0){
      if(boards[x][y]=='Q') return false;
      x--;
      y--;
    }
    x = row, y = col;
    while(x<n && y>=0){
if(boards[x][y]=='Q') return false;
    x++; y--;}
    return true;
  }
  void solve(int col, vector<string> &boards,  vector<vector<string>> &ans, int n){
    if(col==n){
      ans.push_back(boards);
      return ;
    }
    for(int i=0; i<n; i++){
      if(isSafe(i,col,boards,n)){
        boards[i][col] = 'Q';
        solve(col+1,boards,ans,n);
        boards[i][col] = '.';
      }
    }
  }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> boards(n);
        string s(n,'.');
      for(int i=0; i<n; i++){
        boards[i] = s;
      }
      solve(0,boards,ans,n);
      return ans;
    }
};