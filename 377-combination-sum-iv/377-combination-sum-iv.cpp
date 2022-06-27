long long mod=1e9+7;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target+1);
        dp[0]=1;
        int n=nums.size();
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i-nums[j]>=0)
                {
                    dp[i]+=dp[i-nums[j]];
                    if(dp[i]>INT_MAX)
                    dp[i]=dp[i]%mod;
                }
            }
        }
        return dp[target];
    }
};