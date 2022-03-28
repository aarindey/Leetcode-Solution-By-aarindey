class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int l1,l2;
        l1=nums1.size();
        l2=nums2.size();
        int ans=INT_MIN;
        vector<vector<int> > dp(l1+1,vector<int>(l2+1));
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};