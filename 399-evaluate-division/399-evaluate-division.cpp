class Solution {
private:
    vector<double> res;
    unordered_map<string, list<pair<string, double>>> adj;

    void addEdge(string u, string v, double x)
    {
        adj[u].push_back(make_pair(v, x));
        adj[v].push_back(make_pair(u, 1 / x));
    }

    double bfs(string src, string dest)
    {
        if (adj.find(src) == adj.end() || adj.find(dest) == adj.end())  return -1.0;

        unordered_map<string, bool>visited;
        queue<pair<string, double>>q;

        q.push({src, 1});
        visited[src] = true;

        while (!q.empty())
        {
            auto f = q.front();    q.pop();
            string node = f.first;
            double value = f.second;

            if (node == dest)    return value;

            for (auto ngbr : adj[node])
            {
                if (visited[ngbr.first] == false)
                {
                    q.push({ngbr.first, value * ngbr.second});
                    visited[ngbr.first] = true;
                }
            }
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < values.size(); i++)
            addEdge(equations[i][0], equations[i][1], values[i]);

        int n = queries.size();
        for (int i = 0; i < n; i++)
        {
            string src = queries[i][0];
            string dest = queries[i][1];
            double p = bfs(src, dest);
            res.push_back(p);
        }
        return res;
    }
};
