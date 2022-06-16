class Solution {
public:
    unordered_map<int,int> parent,rank;

    int find (int node)
    {
        if(parent[node]==node)
        return node;
       return parent[node]=find(parent[node]); 
    }
    int addEdge(int x,int y)
    {
        int p1=find(x);
        int p2=find(y);
        
        if(p1==p2)
        return 0;

        if(rank[p1]>rank[p2])
        parent[p2]=p1;
        else if(rank[p1]<rank[p2])
        parent[p1]=p2;
        else {
            parent[p1]=p2;
            rank[p2]+=1;
        }
        
        return 1; 
    }
  
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int cnt=1;

        for(int i=0;i<(n+1)*(n+1);i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0||i==n||j==n)
                {
                    addEdge(0,(n+1)*i+j);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                int top,bottom;
                if(grid[i][j]=='/'){
                    top=i*(n+1)+j+1;
                    bottom=(i+1)*(n+1)+j;
                    if(!addEdge(top,bottom))
                        cnt++;
                }
                else if(grid[i][j]=='\\'){
                    top=i*(n+1)+j;
                    bottom=(i+1)*(n+1)+j+1;
                    if(!addEdge(top,bottom))
                        cnt++;
                }
            }
        }
        return cnt;
      return 0;  
    }
};