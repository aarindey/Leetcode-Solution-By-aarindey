class Solution {
public:
    int n;
    int deleteAndEarn(vector<int>& nums) {
        n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<vector<int>> dp(maxi+1,vector<int>(2,0));
        vector<int> mp(maxi+1,0);
        for(auto &x:nums)
        {
            mp[x]++;
        }
        for(int i=1;i<=maxi;i++)
        {
            for(int j=0;j<=1;j++)
            {
                if(j==0)
                dp[i][j]=max(dp[i-1][0],dp[i-1][1]);
                else
                dp[i][j]=dp[i-1][0]+(mp[i]*i);
            }
        }
        return max(dp[maxi][0],dp[maxi][1]);
    }
};