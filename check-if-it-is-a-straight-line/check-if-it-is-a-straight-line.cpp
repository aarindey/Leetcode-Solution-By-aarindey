class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int m=c.size();
        if(m==2)
            return true;
        int det=0;
        for(int i=2;i<m;i++)
        {
            det=c[0][0]*(c[1][1]-c[i][1])-c[0][1]*(c[1][0]-c[i][0])+(c[1][0]*c[i][1]-c[1][1]*c[i][0]);
            if(det!=0)
               return false; 
        }
        return true;
    }
};