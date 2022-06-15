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
        int i=0;
        while(!qq.empty())
        {
            int ele=qq.front();
            qq.pop();
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
                ans.push_back(matrix[q[i][0]][q[i][1]]);
        }
        return ans;
        
    }
};