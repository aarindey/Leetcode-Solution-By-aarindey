class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        if(target<matrix[0][0]||target>matrix[m-1][n-1]||m==0)
         return false;
        int i=0,j=n-1;
        while(i<=m-1&&j>=0)
        {
            if(matrix[i][j]==target)
            {
              return true;
            }
            else if(matrix[i][j]<target)
              i++;
            else if(matrix[i][j]>target)
                j--;
            }
        return false;
    }
};