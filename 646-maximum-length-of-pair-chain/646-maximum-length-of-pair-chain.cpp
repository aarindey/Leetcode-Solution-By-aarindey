class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int ans=1;
        int n=pairs.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0]>pairs[j][1])
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};