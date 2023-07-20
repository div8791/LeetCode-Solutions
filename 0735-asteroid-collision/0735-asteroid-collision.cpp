class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
      stack<int> st;
      int n = asteroids.size();
      for(int i=0; i<n; i++){
        if(st.empty() || asteroids[i]>0){
          st.push(asteroids[i]);
        }
        else{
          while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
            st.pop();
          }
          if(!st.empty() && st.top()==abs(asteroids[i])){
st.pop();}
          else{
            if(st.empty() || st.top()<0){
              st.push(asteroids[i]);
            }
          }
        }
      }
      while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};