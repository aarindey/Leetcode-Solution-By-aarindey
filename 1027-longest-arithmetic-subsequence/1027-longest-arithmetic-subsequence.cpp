class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
     int n=nums.size(); 
     vector<vector<int>> dp(n+1,vector<int>(2500,1));
     int maxi=1;
     for(int i=1;i<n;i++)
     {
         for(int j=0;j<i;j++)
         {
             int diff=nums[i]-nums[j]+501;
             dp[i][diff]=max(dp[i][diff],1+dp[j][diff]);
             maxi=max(maxi,dp[i][diff]);
         }   
     }   
    return maxi;
    }
};