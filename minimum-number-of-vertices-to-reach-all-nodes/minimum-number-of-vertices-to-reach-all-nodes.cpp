class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<vector<int> > graph(n);
        vector<int> indegree(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            ans.push_back(i);
        }
        return ans;
    }
};