class Solution {
public:
    int longestSubsequence(vector<int>& nums, int d) {
     int n=nums.size(); 
     vector<int> dp(n,1);
     int maxi=1;
     map<int,int> mp;
     for(int i=0;i<n;i++)
     {
          if(mp.find(nums[i]-d)!=mp.end())
          {
              int idx=mp[nums[i]-d];
              dp[i]=max(dp[i],1+dp[idx]);
              maxi=max(maxi,dp[i]);
          }
          mp[nums[i]]=i;
     }
     return maxi;
    }
};