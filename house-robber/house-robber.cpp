class Solution {
public:
    int recurse(vector<int> &nums,int i,int prev,vector<int> &dp)
    {
        if(nums.size()==0)
        return 0;
        if(i>=nums.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        if(prev!=-1&&abs(i-prev)==1)
        {
        return dp[i]=recurse(nums,i+1,prev,dp);
        }
        else
        {
            return dp[i]=max(nums[i]+recurse(nums,i+2,i,dp),recurse(nums,i+1,prev,dp));
        }
    }
    int rob(vector<int>& nums) {
     vector<int> dp(nums.size()+1,-1);
     int ans=recurse(nums,0,-1,dp);
      return ans;
    }
};