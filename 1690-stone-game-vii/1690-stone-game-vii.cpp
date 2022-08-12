class Solution {
public:
    int helper(int i,int j,int sum,vector<int> &stones,vector<vector<int>> &dp)
    {
        if(i>j)
        return 0;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
            return dp[i][j]=max(sum-stones[i]-helper(i+1,j,sum-stones[i],stones,dp),sum-stones[j]-helper(i,j-1,sum-stones[j],stones,dp));
        
        return 0;
    }
    int stoneGameVII(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        int n=stones.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=helper(0,n-1,sum,stones,dp);
        return ans;
    }
};