class Solution {
public:
    bool dfs(vector<vector<int>> &graph,vector<int> &v,int i)
    {
        int n=graph.size();
        if(i==n)
        return true;
        int color=v[i];
        bool ok=true;
        for(int j=0;j<graph[i].size();j++)
        {
            if(v[graph[i][j]]==-1)
            {
                v[graph[i][j]]=1-color;
                ok&=dfs(graph,v,graph[i][j]);
            }
            else
            {
               if(v[graph[i][j]]==color)
               {
                   return false;
               }
            }
        }
        return ok;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> v(n,-1);
        bool ok=true;
        for(int i=0;i<n;i++)
        {
            if(v[i]==-1)
            {
                v[i]=0;
                ok&=dfs(graph,v,i);
            }
        }
        return ok;
    }
};