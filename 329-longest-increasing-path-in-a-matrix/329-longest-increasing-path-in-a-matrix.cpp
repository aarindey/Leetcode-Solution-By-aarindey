class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        vector<vector<int>> adj(m*n);
        vector<int> indegree(m*n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int node=m*i+j;
                for(int k=0;k<4;k++)
                {
                    int new_x,new_y;
                    new_x=i+dx[k];
                    new_y=j+dy[k];
                    if(new_x>=0&&new_x<n&&new_y>=0&&new_y<m)
                    {
                        if(matrix[new_x][new_y]>matrix[i][j])
                        {
                            adj[node].push_back(new_x*m+new_y);
                            indegree[new_x*m+new_y]++;
                        }
                    }
                }
            }
        }
        queue<int> q;
        int ans=0;
        for(int i=0;i<n*m;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int level=0;
        vector<int> vis(m*n,0);
        while(!q.empty())
        {
            int sz=q.size();
            level++;
            while(sz--)
            {
                int ele=q.front();
                q.pop();
                if(vis[ele]<level)
                {
                    vis[ele]=level;
                    for(auto &x:adj[ele])
                    {
                        q.push(x);
                    }
                }
            }
        }
        return level;
    }
};