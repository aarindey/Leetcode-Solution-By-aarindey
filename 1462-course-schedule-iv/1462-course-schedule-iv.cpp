class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<vector<bool>> matrix(n,vector<bool>(n,false));
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
        vector<int> topo;
        
        map<int,int> mp;
        int i=0;
        while(!qq.empty())
        {
            int ele=qq.front();
            qq.pop();
            topo.push_back(ele);
            mp[ele]=i++;
            for(auto z:graph[ele])
            {
                matrix[ele][z]=true;
                for(int i=0;i<n;i++) 
                {
                   if(matrix[i][ele])
                   {
                       matrix[i][z]=true;
                   }
                }
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
            if(!matrix[u][v])
            {
                ans.push_back(matrix[u][v]);
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