class Solution {
public:
    int recurse(vector<vector<int>> &triangle,int i,int j,int n,vector<vector<int>> &memo)
    {
        if(i==n||j==n)
        return 0;
        if(memo[i][j]!=-1)
        return memo[i][j];
        int first=0,second=0;
        if(i+1<n)
        {
            first=triangle[i+1][j]+recurse(triangle,i+1,j,n,memo);
        }
        if(i+1<n&&j+1<n)
        {
            second=triangle[i+1][j+1]+recurse(triangle,i+1,j+1,n,memo);
        }
        return memo[i][j]=min(first,second);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        int ans=recurse(triangle,0,0,n,memo);
        
        return triangle[0][0]+ans;
    }
};