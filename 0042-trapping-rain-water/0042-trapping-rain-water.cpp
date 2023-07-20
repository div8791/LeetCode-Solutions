class Solution {
public:
    int trap(vector<int>& height) {
      int total_water = 0;
      int n = height.size();
      vector<int> ngl(n);
      vector<int> ngr(n);
      vector<int> water(n);
      ngl[0] = height[0];
      for(int i=1; i<n; i++){
        ngl[i] = max(ngl[i-1],height[i]);
      }
      ngr[n-1] = height[n-1];
      for(int i=n-2; i>=0; i--){
        ngr[i] = max(ngr[i+1],height[i]);
      }
      for(int i=0; i<n; i++){
        water[i] = min(ngl[i],ngr[i]) - height[i];
        total_water += water[i];
      }
      return total_water;
    }
};