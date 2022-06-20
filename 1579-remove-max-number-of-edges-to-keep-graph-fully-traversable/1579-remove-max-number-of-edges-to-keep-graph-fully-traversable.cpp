class DSU
{
    public:
    int findParent(int node,vector<int>& par)
    {
        if(par[node]==node)return node;
        return par[node]=findParent(par[node],par);
    }
    void Union(int u,int v,vector<int> &par,vector<int> &size)
    {
        int pu=findParent(u,par);
        int pv=findParent(v,par);
        if(pu==pv)return;
    
        if(size[pu]<=size[pv])
        {
            par[pu]=pv;
            size[pv]++;
        }
        else
        {
            par[pv]=pu;
            size[pu]++;
        }
    }
    bool isConnected(int u,int v,vector<int> &par)
    {
        int pu=findParent(u,par);
        int pv=findParent(v,par);
        if(pu==pv)return 1;
        return 0;
    }
    int isValid(int type,vector<vector<int>> &edges,vector<int> &parent,vector<int> &size)
    {
        int c=0;
        int n=edges.size();
        for(int i=0;i<n;i++)
        {
            if(edges[i][0]==type&&(findParent(edges[i][1],parent)!=findParent(edges[i][2],parent)))
            {
                c++;
                Union(edges[i][1],edges[i][2],parent,size);
            }
        }
        return c;
    }
};
class Solution {
public:

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parent(n+1);
        vector<int> size(n+1,1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        int t1,t2,t3;
        DSU dsu;

        t3=dsu.isValid(3,edges,parent,size);
        vector<int> p;
        p=parent;
        t2=dsu.isValid(2,edges,p,size);
        p=parent;
        t1=dsu.isValid(1,edges,p,size);
        if(t3+t1!=n-1||t3+t2!=n-1)
         return -1;
        return edges.size()-t1-t2-t3;
    }
};