class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        int m=edges.size();
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            vector<int> dis(n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,i});
            dis[i]=0;
            while(!pq.empty())
            {
                pair<int,int> ele=pq.top();
                pq.pop();
                int dist=ele.first;
                int node=ele.second;
                for(auto &x:adj[node])
                {
                    if(dist+x.second<dis[x.first])
                    {
                        dis[x.first]=dist+x.second;
                        pq.push({dist+x.second,x.first});
                    }
                }
            }
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(dis[j]<=distanceThreshold)
                {
                    mp[i]++;
                }
            }
        }
        int freq=INT_MAX;
        for(auto &pr:mp)
        {
            freq=min(pr.second,freq);
        }
        int ans=0;
        for(auto &pr:mp)
        {
            if(pr.second==freq)
            {
                ans=max(ans,pr.first);
            }
        }
        return ans;
    }
};