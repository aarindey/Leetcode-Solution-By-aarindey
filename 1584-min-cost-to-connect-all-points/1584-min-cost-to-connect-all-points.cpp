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
      priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int ans=0;
        int n=p.size();
        int c=0;
        vector<int> par(n),rank(n,0);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int d=abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]);
                pq.push({d,i,j});
            }
        }
        while(!pq.empty())
        {
            vector<int> ele=pq.top();
            pq.pop();
            if(findParent(ele[1],par)!=findParent(ele[2],par))
            {
                join(ele[1],ele[2],par,rank);
                ans+=ele[0];
                c++;
            }
            if(c==n-1)
            break;
        }
        return ans;
    }
};