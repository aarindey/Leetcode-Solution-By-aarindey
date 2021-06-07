class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
      int rows=matrix[0].size(),columns=matrix.size();
        for(int i=0;i<columns;i++)
        for(int j=0;j<rows;j++)
        {
           if(i>0&&j>0&&matrix[i][j]!=matrix[i-1][j-1])
            return false;   
        }   
        return true;
    }
};