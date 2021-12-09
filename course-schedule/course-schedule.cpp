class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> visited(n,false);
        unordered_map<int,vector<int> > graph;
        vector<int> indegree(n,0);
        for(auto &x:prerequisites)
        {
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        bool enter=false;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
            q.push(i);
            enter=true;
            }
        }
        if(!enter)
        return false;
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            if(visited[ele])
            return false;
            visited[ele]=true;
            for(auto &z:graph[ele])
            {
                indegree[z]--;
                if(indegree[z]==0)
                q.push(z);
                else if(indegree[z]<0)
                return false;
            }
        }
        if(find(visited.begin(),visited.end(),false)==visited.end())
        return true;
        else
        return false;
    }
};