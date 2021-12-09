class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        if(n==1)
        return matrix[0][0];
        if(n==0)
        return 0;
        for(int r=1;r<n;r++)
        {
            for(int c=0;c<n;c++)
            {
                int mini=INT_MAX;
                for(int i=0;i<n;i++)
                {
                    if(i!=c)
                    {
                        mini=min(mini,matrix[r-1][i]);
                    }
                }
                matrix[r][c]+=mini;
            if(r==n-1)
            {
                   ans=min(ans,matrix[r][c]); 
            }  
            }
        }
        return ans;
    }
};