class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        for(int i=1;i<=n;i++)
        {
            int sum1,sum2,sum3;
            sum1=nums[i-1]+dp[i-1][0];
            sum2=nums[i-1]+dp[i-1][1];
            sum3=nums[i-1]+dp[i-1][2];
            dp[i]=dp[i-1];
            dp[i][sum1%3]=max(dp[i][sum1%3],sum1);
            dp[i][sum2%3]=max(dp[i][sum2%3],sum2);
            dp[i][sum3%3]=max(dp[i][sum3%3],sum3);
        }
        return dp[n][0];
    }
};