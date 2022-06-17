class Solution {
public:
    void dfs(int node,vector<vector<int>> &graph,vector<vector<int>> &ungraph,vector<int>&vis,int &cnt){
        vis[node]=1;
        for(auto &it  : graph[node]){
            if(!vis[it])
                cnt++;
        }
        for(auto &it : ungraph[node]){
            if(!vis[it]){
                dfs(it,graph,ungraph,vis,cnt);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ungraph(n);
        vector<vector<int>> graph(n);
        for(auto &it : connections){
            ungraph[it[0]].push_back(it[1]);
            ungraph[it[1]].push_back(it[0]);
            graph[it[0]].push_back(it[1]);
        }
        vector<int> vis(n,0);
        int cnt=0;
        dfs(0,graph,ungraph,vis,cnt);
        return cnt;
    }
};