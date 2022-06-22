class Solution {
public:
    void bfs(vector<vector<int>> &adj,vector<int> &ans,int node)
    {
        queue<pair<int,int>> q;
        q.push({node,1});
        ans[node]=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
            pair<int,int> ele=q.front();
            q.pop();
            int color=ele.second;
            int node=ele.first;
            for(auto &x:adj[node])
            {
                if(ans[x]==-1||ans[node]==ans[x])
                {
                    ++color;
                    ans[x]=color;
                    if(color>=4)
                    {
                        color=color%4;
                    }
                    q.push({x,color});
                }
            }
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<paths.size();i++)
        {
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> ans(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(ans[i]==-1)
            {
                bfs(adj,ans,i);
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};