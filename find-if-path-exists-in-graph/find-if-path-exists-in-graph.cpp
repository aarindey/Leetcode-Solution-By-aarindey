class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int> > graph;
        if(start==end)
        return true;
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        q.push(start);
        vector<bool> visited(n,false);
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            visited[ele]=true;
            for(int i=0;i<graph[ele].size();i++)
            {
                if(graph[ele][i]==end)
                return true;
                if(!visited[graph[ele][i]])
                q.push(graph[ele][i]);
            }
        }
        return false;
    }
};