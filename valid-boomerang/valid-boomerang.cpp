class Solution {
public:
    bool isBoomerang(vector<vector<int>>& p) {
      int det;
        if(p[0]==p[1]||p[1]==p[2]||p[2]==p[0])
          return false;  
    det=p[0][0]*(p[1][1]-p[2][1])-p[0][1]*(p[1][0]-p[2][0])+(p[1][0]*p[2][1]-p[2][0]*p[1][1]);
        return det!=0;
    }
};