class Solution {
public:
    int bestClosingTime(string customers) {
        int j=-1, score=0, maxscore=0;
      for(int i=0; i<customers.size(); i++){
        score += (customers[i]=='Y') ? 1 : -1;
        if(score>maxscore) {
          j=i;
          maxscore = score;
        }
      }
      return j+1;
    }
};