class Solution {
public:
    int dfs(vector<int> &arr,int k,vector<int> &dp,int start)
    {
        int n=arr.size();
        if(start>=n)
        return 0;
        if(dp[start]!=0)
        {
            return dp[start];
        }
        int maxVal=0,maxSum=0;
        for(int i=start;i<min(n,start+k);i++)
        {
            maxVal=max(maxVal,arr[i]);
            maxSum=max(maxSum,(i-start+1)*maxVal+dfs(arr,k,dp,i+1));
        }
        return dp[start]=maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,0);
        return dfs(arr,k,dp,0);
    }
};