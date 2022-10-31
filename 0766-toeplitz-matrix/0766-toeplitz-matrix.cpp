class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
      int c=m[0].size(),r=m.size();
        for(int i=1;i<r;i++)
        for(int j=1;j<c;j++)
        {
           if(i>0&&j>0&&m[i][j]!=m[i-1][j-1])
            return false;   
        }   
        return true;
    }
};