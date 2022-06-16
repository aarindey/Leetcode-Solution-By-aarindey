class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<vector<bool>> matrix(n,vector<bool>(n,false));
        vector<int> graph[n];
        vector<int> indegree(n,0);
        for(auto edge:edges)
        {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
            // matrix[edge[0]][edge[1]]=true;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            for(auto x:graph[ele])
            {
                matrix[ele][x]=true;
                for(int i=0;i<n;i++)
                {
                    if(matrix[i][ele])
                    {
                        matrix[i][x]=true;
                    }
                }
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(matrix[i][j])
                ans[j].push_back(i);
            }
        }
        return ans;
    }
};