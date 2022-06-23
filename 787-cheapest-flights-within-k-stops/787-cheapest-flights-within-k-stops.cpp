class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f:flights)
        {
            adj[f[0]].push_back({f[1],f[2]});
        }
        set<vector<int>> pq;
        pq.insert({0,src,k+1});
        while(!pq.empty())
        {
            vector<int> ele=*pq.begin();
            pq.erase(pq.begin());
            int price=ele[0];
            int node=ele[1];
            int stops=ele[2];
            if(node==dst&&stops>=0)
            return price;
            for(auto &x:adj[node])
            {
                if(stops>0)
                pq.insert({price+x.second,x.first,stops-1});
            }
        }
        return -1;
    }
};