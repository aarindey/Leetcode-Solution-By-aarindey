class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans=0;
        vector<int> graphf[n];
        vector<int> graphb[n];
        // vector<vector<bool>> matrix(n,vector<bool>(n,false));
        queue<int> q;
        for(auto x:connections)
        {
            graphf[x[0]].push_back(x[1]);
            graphb[x[1]].push_back(x[0]);
        }
        vector<bool> vis(n,false);
        q.push(0);
        vis[0]=true;
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            for(auto &x:graphf[ele])
            {
                if(!vis[x])
                {
                    ans++;
                    q.push(x);
                    vis[x]=true;
                }
            }
            for(auto &y:graphb[ele])
            {
                if(vis[y]==false)
                {
                    q.push(y);
                    vis[y]=true;
                }
            }
        }
        return ans;
    }
};