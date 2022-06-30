#define ll long long int
class Solution {
public:
    //flag=-1 -> neither add nor sub   flag=1 -> last add    flag=0 -> last sub
    ll fun(vector<int> &nums,ll i,ll &n,int flag,vector<vector<ll>> &dp)
    {
        if(i==n-1)
        {
            if(flag==1)
            {
                return 0;
            }
            else
            {
                return nums[n-1];
            }
        }
        
        if(dp[i][flag]!=-1)
        return dp[i][flag];
        
        ll ans=INT_MIN;
        if(flag==2)
        {
            ans=max(ans,nums[i]+fun(nums,i+1,n,1,dp));
            ans=max(ans,fun(nums,i+1,n,2,dp));
        }
        else if(flag==1)
        {
            ans=max(ans,-nums[i]+fun(nums,i+1,n,0,dp));
            ans=max(ans,fun(nums,i+1,n,1,dp));
        }
        else
        {
            ans=max(ans,nums[i]+fun(nums,i+1,n,1,dp));
            ans=max(ans,fun(nums,i+1,n,0,dp));
        }
        return dp[i][flag]=ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        ll n = nums.size();
        vector<vector<ll>> dp(n+1,vector<ll>(3,-1));
        return fun(nums,0,n,2,dp);
    }
};