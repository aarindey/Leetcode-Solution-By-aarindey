class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto &edge:redEdges)
        {
            adj[edge[0]].push_back({edge[1],0});
        }
        for(auto &edge:blueEdges)
        {
            adj[edge[0]].push_back({edge[1],1});
        }
        vector<int> dis(n,-1);
        dis[0]=0;
        queue<pair<int,int>> q;
        q.push({0,-1});
        int level=0;
        vector<int> redDis(n,-1),blueDis(n,-1);
        redDis[0]=0;
        blueDis[0]=0;
        while(!q.empty())
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
               pair<int,int> ele=q.front();
                q.pop();
                int flag,node;
                node=ele.first;
                flag=ele.second;
                for(auto &x:adj[node])
                {
                    if(x.second==flag||(x.second==1&&blueDis[x.first]!=-1)||(x.second==0&&redDis[x.first]!=-1))
                    {
                        continue;
                    }
                    if(x.second==0)
                    redDis[x.first]=level+1;
                    else
                    blueDis[x.first]=level+1;
                    q.push({x.first,x.second});
                }
            }
            level++;
        }
        for(int i=0;i<n;i++)
        {
            if(min(redDis[i],blueDis[i])==-1)
            {
                dis[i]=max(redDis[i],blueDis[i]);
            }
            else
            {
                dis[i]=min(redDis[i],blueDis[i]);
            }
        }
        return dis;
    }
};