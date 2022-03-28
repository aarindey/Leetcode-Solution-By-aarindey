class Solution {
public:
    int dp[72][5000];
    int n,m;
    int solve(vector<vector<int> > &mat,int row,int sum,int target)
    {
        if(row==n)
        return abs(sum-target);
        
        if(dp[row][sum]!=-1)
        return dp[row][sum];
        
        int minDifference=INT_MAX;
        for(int i=0;i<m;i++)
        {
            minDifference=min(minDifference,solve(mat,row+1,sum+mat[row][i],target));
        }
        return dp[row][sum]=minDifference;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target)    {
     n=mat.size();
     m=mat[0].size();
     memset(dp,-1,sizeof(dp));
     return solve(mat,0,0,target);
    }
};