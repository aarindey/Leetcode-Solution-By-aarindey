class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n));
        dp[0][0]=triangle[0][0];
        int ans=INT_MAX;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(i==j)
                {
                    dp[i][j]=dp[i-1][j-1]+triangle[i][j];
                }
                else if(j==0)
                {
                    dp[i][j]=dp[i-1][j]+triangle[i][j];
                }
                else 
                {
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
                }
                if(i==n-1)
                {
                    ans=min(ans,dp[i][j]);
                }
            }
        }
        if(ans==INT_MAX)
        return dp[0][0];
        return ans;
    }
};