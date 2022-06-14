class Solution {
public:
     bool dfsCycleChecker(int node,int target,int par,vector<vector<int>> &graph,vector<int> &vis)     {
        if(node==target)
        return true;
        vis[node]=true;
        for(auto &it : graph[node]){
            
            if(node==par&&it==target)
            {
                continue;
            }
            if(!vis[it])
            if(dfsCycleChecker(it,target,node,graph,vis)){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> graph(n+1);
        for(auto edge:edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i=n-1;i>=0;i--)
        {
            vector<int> vis(n+1,0);
            if(dfsCycleChecker(edges[i][0],edges[i][1],edges[i][0],graph,vis))
            {
                return edges[i];
            }
        }
        return {};
    }
};