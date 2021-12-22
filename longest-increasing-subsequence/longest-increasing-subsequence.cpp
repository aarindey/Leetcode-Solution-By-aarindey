class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=1;
        int ans=1;
        for(int i=1;i<n;i++)
        {
            int maxi=0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    maxi=max(dp[j],maxi);
                }
            }
            dp[i]=maxi+1;
            ans=max(dp[i],ans);
        }
        return ans;
    }
};