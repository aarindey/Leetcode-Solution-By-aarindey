class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> dis(n,1e-5);
        priority_queue<pair<int,double>> q;
        q.push({start,1});
        dis[start]=1;
        while(!q.empty())
        {
            pair<int,double> ele=q.top();
            q.pop();
            double pro=ele.second;
            int node=ele.first;
            for(auto x:adj[node])
            {
                if(pro*x.second>dis[x.first])
                {
                    dis[x.first]=pro*x.second;
                    q.push({x.first,dis[x.first]});
                }
            }
        }
        return dis[end];
    }
};