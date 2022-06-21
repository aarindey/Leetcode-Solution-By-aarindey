class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto time:times)
        {
            adj[time[0]].push_back({time[1],time[2]});
        }
        vector<int> dis(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dis[k]=0;
        while(!pq.empty())
        {
            pair<int,int> ele=pq.top();
            pq.pop();
            int wt,node;
            wt=ele.first;
            node=ele.second;
            for(auto &z:adj[node])
            {
                int t=wt+z.second;
                int node2=z.first;
                if(dis[node2]>t)
                {
                    dis[node2]=t;
                    pq.push({t,node2});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,dis[i]);
        }
        if(ans==INT_MAX)
        return -1;
        
        return ans;
    }
};