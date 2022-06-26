class Solution {
public:
    vector<vector<int>> dp;
    int n,m;
    int recurse(int i,int m,int start,vector<int> &nums,vector<int> &mul)
    {
        if(i==n)
        return 0;
        if(dp[start][i]!=INT_MAX)
        return dp[start][i];
        int left,right;
        int end=m-(i-start)-1;
        return dp[start][i]=max(nums[start]*mul[i]+recurse(i+1,m,start+1,nums,mul),nums[end]*mul[i]+recurse(i+1,m,start,nums,mul));
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        n=mul.size();
        m=nums.size();
        dp.resize(1001,vector<int>(1001,INT_MAX));
        int ans=recurse(0,m,0,nums,mul);
        return ans;
    }
};