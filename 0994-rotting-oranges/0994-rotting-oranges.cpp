class Solution {
public:
  bool isSafe(vector<vector<int>>& grid, int x, int y){
    int n = grid.size();
    int m = grid[0].size();
    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1) return true;
    
    return false;
  }
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
      int fresh = 0;
      queue<pair<int,int>> q;
      for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
          if(grid[i][j]==2){
            q.push({i,j});
          }
          else if(grid[i][j]==1) fresh++;
        }
      }
      if(fresh==0) return 0;
      while(!q.empty()){
        int size = q.size();
        int temp = 0;
        while(size!=0){
          pair<int,int> p = q.front();
          q.pop();
          int x = p.first;
          int y = p.second;
          int ax[4] = {-1,0,0,1};
          int ay[4] = {0,-1,1,0};
          for(int i=0; i<4; i++){
              int x1 = x+ax[i];
              int y1 = y+ay[i];
            if(isSafe(grid,x1,y1)){
              temp++;
              grid[x1][y1] = 2;
              q.push({x1,y1});
            }
          }
          size--;
        }
        if(temp!=0) time++;
      }
      for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
          if(grid[i][j]==1){ 
            time = -1;
            break;
          }
        }
      }
      return time;
    }
};