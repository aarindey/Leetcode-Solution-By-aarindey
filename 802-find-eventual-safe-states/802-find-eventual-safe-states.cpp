class Solution {
public:
    bool dfs(vector<vector<int>> &graph,vector<bool> &vis,vector<bool> &dfsvis,int i)
    {
        vis[i]=true;
        dfsvis[i]=true;
        for(auto x:graph[i])
        {
            if(!vis[x]&&!dfsvis[x])
            {
                if(dfs(graph,vis,dfsvis,x))
                    return true;
            }
            else if(dfsvis[x])
            {
                    return true;
            }
        }
        dfsvis[i]=false;
        return false;
    }
 vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,false); 
        vector<bool> dfsvis(n,false);
        vector<bool> pos(n,false);
        // vector<int> topo;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            
                if(!dfs(graph,vis,dfsvis,i))
                {
                   //ans.push_back(i); 
                }   
                if(!dfsvis[i])
                ans.push_back(i);
        }
        return ans;
    }
};

