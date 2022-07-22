class Solution {
public:
    int n;
    int fun(vector<int> &nums,int i,int sum,int rem,vector<vector<int>> &dp)
    {
        if(i>=n)
        {
            if(sum%3==0)
            return 0;
            else
            return INT_MIN;
        }
        
        if(dp[i][rem]!=-1)
        return dp[i][rem];
        
        int ans=0;
        ans=nums[i]+fun(nums,i+1,sum+nums[i],(rem+nums[i]%3)%3,dp);
        ans=max(ans,fun(nums,i+1,sum,rem,dp));
        
        return dp[i][rem]=ans;
    }
    int maxSumDivThree(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return fun(nums,0,0,0,dp);
    }
};