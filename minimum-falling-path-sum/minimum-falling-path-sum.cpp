class Solution {
public:
    int dfs(vector<vector<int>>& matrix,int c,int r,vector<vector<int>> &visited)
    {
     int sum=0;
     if(c>=matrix.size()||c<0||r>=matrix.size())
     return 0;
     if(visited[r][c]!=-1)
     return visited[r][c];
     sum+=matrix[r][c];
     if(c==0)
     {
        sum+=min(dfs(matrix,c,r+1,visited),dfs(matrix,c+1,r+1,visited));
     }
     else if(c==matrix.size()-1)
     {
        sum+=min(dfs(matrix,c,r+1,visited),dfs(matrix,c-1,r+1,visited));
     }
     else
     {
        sum+=min(dfs(matrix,c,r+1,visited),min(dfs(matrix,c-1,r+1,visited),dfs(matrix,c+1,r+1,visited)));
     }
    visited[r][c]=sum;
    return sum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini=INT_MAX;
        int n=matrix.size();
        vector<vector<int> > visited(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            mini=min(mini,dfs(matrix,i,0,visited));
        }
        return mini;
    }
};