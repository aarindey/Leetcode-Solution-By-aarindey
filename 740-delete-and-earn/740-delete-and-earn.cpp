class Solution {
public:
    int fun(int maxi,vector<int> &mp,vector<int> &dp)
    {
        if(maxi<1)
        {
            return 0;
        }
        if(dp[maxi]!=-1)
        {
            return dp[maxi];
        }
        int take=0,nontake=0;
        take+=maxi*mp[maxi];
        if(maxi>=2)
        take+=fun(maxi-2,mp,dp);
        nontake=fun(maxi-1,mp,dp);
        return dp[maxi]=max(take,nontake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> mp(maxi+1,0);
        vector<int> dp(maxi+1,-1);
        for(auto &x:nums)
        {
            mp[x]++;
        }
        return fun(maxi,mp,dp);
    }
};