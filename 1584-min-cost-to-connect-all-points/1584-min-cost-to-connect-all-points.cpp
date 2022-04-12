class Solution {
public:
    void join(int i,int j,vector<int> &parent,vector<int> &rank)
    {
        i=findParent(i,parent);
        j=findParent(j,parent);
        if(rank[i]==rank[j])
        {
            parent[i]=j;
            rank[j]++;
        }
        else if(rank[i]>rank[j])
        {
            parent[j]=i;
        }
        else
        {
            parent[i]=j;
        }
    }
    int findParent(int i,vector<int> &parent)
    {
        if(parent[i]==i)
        return i;
        
        return parent[i]=findParent(parent[i],parent);
    }
    int minCostConnectPoints(vector<vector<int>>& p) {
        // vector<vector<int> > vec;
        int i=0,n=p.size(),d;
        vector<int> parent(n),rank(n,0);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        for(int i=0;i<n;i++)
        parent[i]=i;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                d=(abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]));
                pq.push({d,i,j});
            }
        }
        // sort(vec.begin(),vec.end());
        int ans=0;
        int c=0;
        while(!pq.empty())
        {
            vector<int> v;
            v=pq.top();
            pq.pop();
            if(findParent(v[1],parent)==findParent(v[2],parent))
            {
                continue;
            }
            else
            {
                join(v[1],v[2],parent,rank);
                ans+=v[0];
                c++;
            }
            if(c==n-1)
            break;
        }
        return ans;
    }
};