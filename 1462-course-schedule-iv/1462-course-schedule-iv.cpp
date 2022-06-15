class Solution {
public:
    bool dfs(int source,int destination,vector<int> graph[],vector<bool> &vis)
    {
        vis[source]=true;
        if(source==destination)
        return true;
        
        for(auto x:graph[source])
        {
            if(!vis[x]&&dfs(x,destination,graph,vis))
            return true;
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        if(p.size()==0)
        {
            vector<bool> ans(q.size(),false);
            return ans;
        }
        vector<int> indegree(n,0);
        vector<int> graph[n];
        for(auto x:p)
        {
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int> qq;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                qq.push(i);
            }
        }
        
        map<int,int> mp;
        int i=0;
        while(!qq.empty())
        {
            int ele=qq.front();
            qq.pop();
            mp[ele]=i++;
            for(auto z:graph[ele])
            {
                indegree[z]--;
                if(indegree[z]==0)
                {
                    qq.push(z);
                }
            }
        }
       
        vector<bool> ans;
        for(int i=0;i<q.size();i++)
        {
            int u,v;
            u=q[i][0];
            v=q[i][1];
            vector<bool> vis(n,false);
            if(!dfs(u,v,graph,vis))
            {
                ans.push_back(false);
            }
            else if(mp[u]>mp[v])
            {
                ans.push_back(false);
            }
            else
            {
                ans.push_back(true);
            }
        }
        return ans;
        
    }
};