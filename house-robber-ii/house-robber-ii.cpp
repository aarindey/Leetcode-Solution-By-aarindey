class Solution {
public:
    int recurse(vector<int> &nums,int i,vector<int> &dp,int n)
    {
        if(nums.size()==0)
        return 0;
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];

            return dp[i]=max(nums[i]+recurse(nums,i+2,dp,n),recurse(nums,i+1,dp,n));
    }
    int rob(vector<int>& nums) {
       vector<int> dp(nums.size()+1,-1);
        int n=nums.size();
        if(n==3)
        return *max_element(nums.begin(),nums.end());
        else if(n==1)
        return nums[0];
        int x1=recurse(nums,0,dp,n-1);
        vector<int> dp2(n+1,-1);
        int x2=recurse(nums,1,dp2,n);
        return max(x1,x2);
    }
};