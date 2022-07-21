#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    int n;
    int helper(vector<int> &nums,int i,int prev,vector<vector<ll>> &dp)
    {
        if(i>=n)
        {
            if(prev==2)
            return 1;
            
            return 0;
        }
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        ll ans=0;
        if(nums[i]==prev||nums[i]==prev+1)
        {
            ans+=helper(nums,i+1,nums[i],dp);
        }
        ans+=helper(nums,i+1,prev,dp);
        return dp[i][prev+1]=ans%mod;
    }
    int countSpecialSubsequences(vector<int>& nums) {
        n=nums.size();
        vector<vector<ll>> dp(n+1,vector<ll>(4,-1));
        return helper(nums,0,-1,dp);
    }
};