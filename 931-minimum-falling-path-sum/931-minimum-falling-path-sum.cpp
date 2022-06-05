class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        if(n==1)
        return matrix[0][0];
        if(n==0)
        return 0;
        for(int r=1;r<n;r++)
        {
            for(int c=0;c<n;c++)
            {
                if(c==0)
                {
                    matrix[r][c]+=min(matrix[r-1][c],matrix[r-1][c+1]);
                }
                else if(c==n-1)
                {
                    matrix[r][c]+=min(matrix[r-1][c],matrix[r-1][c-1]);
                }
                else
                {
                    matrix[r][c]+=min(matrix[r-1][c],min(matrix[r-1][c+1],matrix[r-1][c-1]));
                }
                if(r==n-1)
                {
                    mini=min(mini,matrix[r][c]);
                }
            }
        }
        return mini;
    }
};