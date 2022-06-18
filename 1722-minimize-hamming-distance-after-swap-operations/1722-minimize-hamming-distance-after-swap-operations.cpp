class Solution {
public:
    int findParent(int node,vector<int> &parent)
    {
        if(node==parent[node])
        return node;
        
        return parent[node]=findParent(parent[node],parent);
    }
    void Union(int x,int y,vector<int> &parent,vector<int> &rank)
    {
        x=findParent(x,parent);
        y=findParent(y,parent);
        
        if(x==y)
        return;
        
        if(rank[x]<=rank[y])
        {
            parent[x]=y;
            rank[y]++;
        }
        else if(rank[y]<rank[x])
        {
            parent[y]=x;
            rank[x]++;
        }
    }
    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& as) {
        int n=s.size();
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<as.size();i++)
        {
            int x=as[i][0];
            int y=as[i][1];
            Union(x,y,parent,rank);
        }
        map<int,map<int,int>> store;
        for(int i=0;i<n;i++)
        {
            int x=findParent(i,parent);
            store[x][s[i]]++;
        }
        int hammingDis=0;
        for(int i=0;i<n;i++)
        {
            int x=findParent(i,parent);
            if(t[i]==s[i])
            {
                if(store[x][t[i]]>0)
                store[x][t[i]]--;
                else
                hammingDis++;
            }
            else
            {
                if(store[x].find(t[i])!=store[x].end()&&store[x][t[i]]>0)
                {
                    store[x][t[i]]--;
                }
                else
                {
                    hammingDis++;
                }
            }
        }
        return hammingDis;
    }
};