class Solution {
public:
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime){   
    vector<vector<int>> adj(n);
    for(int i=0;i<manager.size();i++)
    {
        if(manager[i]!=-1)
        {
            adj[manager[i]].push_back(i);
        }
    }
    queue<pair<int,int>> q;
    q.push({headID,0});
    int ans=0;
    while(!q.empty())
    {
        pair<int,int> ele=q.front();
        q.pop();
        int node=ele.first;
        int last_time=ele.second;
        ans=max(ans,last_time);
        for(auto &x:adj[node])
        {
            q.push({x,last_time+informTime[node]});
        }
    }
    return ans;
}
};