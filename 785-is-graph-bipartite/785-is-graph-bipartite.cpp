class Solution {
public:
    bool bfs(vector<vector<int>> &graph,vector<int> &v,int i)
    {
        int n=graph.size();
        queue<int> q;
        q.push(i);
        v[i]=0;
        int colour=0;
        
        while(!q.empty())
        {
            int curr=q.front();
            int color=v[curr];
            q.pop();
            for(auto x:graph[curr])
            {
                if(v[x]!=-1)
                {
                    if(v[x]==color)
                    {
                        return false;
                    }
                }
                else
                {
                    v[x]=1-color;
                    q.push(x);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> v(n,-1);
        bool ok=true;
        for(int i=0;i<n;i++)
        {
            if(v[i]==-1)
            {
                ok&=bfs(graph,v,i);
            }
        }
        return ok;
    }
};