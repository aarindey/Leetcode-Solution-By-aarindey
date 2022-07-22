class Solution {
public:
    int n;
    double fun(vector<int> &nums,int k,int i,int prev,vector<vector<double>> &dp)
    {
        if(i==n&&k==1||i==n&&k==0)
        return 0;
        if(i>=n||k<=0)
        {
            return INT_MIN;
        }
        if(dp[prev+1][k]!=-1)
        return dp[prev+1][k];
        
        double ans=0.0;
        for(int j=i;j<n;j++)
        {
            if(prev==-1)
            {
                ans=max(ans,(double)(nums[j])/((1.0)*(j-prev))+fun(nums,k-1,j+1,j,dp));
                ans=max(ans,fun(nums,k,j+1,prev,dp));
            }
            else
            {
                ans=max(ans,(double)(nums[j]-nums[prev])/((1.0)*(j-prev))+fun(nums,k-1,j+1,j,dp));
                ans=max(ans,fun(nums,k,j+1,prev,dp));
            }
        }
        return dp[prev+1][k]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        n=nums.size();
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        vector<vector<double>> dp(n+2,vector<double>(n+1,-1));
        return fun(nums,k,0,-1,dp);
    }
};