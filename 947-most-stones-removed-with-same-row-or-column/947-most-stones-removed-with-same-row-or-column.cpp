class Solution {
public:
    int find(int node,vector<int> &parent)
    {
        if(node==parent[node])
        return node;
        return parent[node]=find(parent[node],parent);
    }
    void Union(int x,int y,vector<int> &parent,vector<int> &rank)
    {
        x=find(x,parent);
        y=find(y,parent);
        if(x==y)
        return;
        if(rank[x]<rank[y])
        {
            parent[x]=y;
        }
        else if(rank[y]<rank[x])
        {
            parent[y]=x;
        }
        else
        {
            parent[y]=x;
            rank[x]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> parent(n),rank(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                {
                    int x=find(i,parent);
                    int y=find(j,parent);
                    if(x!=y)
                    Union(x,y,parent,rank);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<find(i,parent)<<endl;
        }
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[parent[i]]++;
        }
        return n-mp.size();
    }
};