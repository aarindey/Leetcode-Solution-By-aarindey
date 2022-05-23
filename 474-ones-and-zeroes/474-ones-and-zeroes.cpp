class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(auto s:strs)
        {
            int zeroes=0,ones=0;
            for(char ch:s)
            {
                if(ch=='1')
                {
                    ones++;
                }
                else
                {
                    zeroes++;
                }
            }
            for(int i=m;i>=zeroes;i--)
            {
                for(int j=n;j>=ones;j--)
                {
                    dp[i][j]=max(dp[i][j],1+dp[i-zeroes][j-ones]);
                }
            }
        }
        return dp[m][n];
    }
};