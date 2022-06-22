class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
        //Comp which sorts the edges based on their weight
        return a[2]<b[2];
    }
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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        int z=edges.size();
        vector<bool> isPartOfMST(z,false);
        
        //Pushing the indexes of each edges
        for(int i=0;i<z;i++)
        {
            edges[i].push_back(i);
        }
        //sorting wrt cost
        sort(edges.begin(),edges.end(),comp);
        vector<int> parent(n),rank(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int c=0;
        int size=0;
        // Making the First MST
        for(int i=0;i<z;i++)
        {
            if(c==n-1)
            break;
            if(findParent(edges[i][0],parent)!=findParent(edges[i][1],parent))
            {
                size+=edges[i][2];
                join(edges[i][0],edges[i][1],parent,rank);
                isPartOfMST[edges[i][3]]=true;
                c++;
            }
        }
        //Storing the cost of the MST in size
        // cout<<size<<endl;
        vector<int> v;
        for(int i=0;i<z;i++)
        {
            vector<int> par(n),ra(n,0);
            
            for(int i=0;i<n;i++)
            {
                   par[i]=i;    
            }
            int c=0;
            int sz=0;
            vector<bool> temp(z,false);
            for(int j=0;j<z;j++)
            {
                // Applying Kruskal's Algo while not considering the ith edge
                if(i==j)
                {
                    continue;
                }
                if(c==n-1)
                break;
                if(findParent(edges[j][0],par)!=findParent(edges[j][1],par))
                {
                    join(edges[j][0],edges[j][1],par,ra);
                    sz+=edges[j][2];
                    c++;
                    temp[edges[j][3]]=true;
                    // Using temp to find all those edges which are part of at least one MST
                }
            }
            // cout<<sz<<endl;
            if(sz==size)
            {
                // if(sz==size)
                for(int k=0;k<z;k++)
                {
                    if(temp[k])
                    isPartOfMST[k]=true;
                }
            }
            else
            {
                // v stores the indices of the critical edges
                v.push_back(edges[i][3]);
            }
        }
        // pseudo stores the pseudo critical edges
        vector<int> pseudo;
        for(int i=0;i<z;i++)
        {
            if(!isPartOfMST[edges[i][3]])
            {
                // Making MSTs considering those edges which are still not part of some MST. To include all those cases which might have missed otherwise
                vector<int> pa(n),r(n,0);
            
                for(int i=0;i<n;i++)
                {
                       pa[i]=i;    
                }
                int c=1;
                int sz=edges[i][2];
                join(edges[i][0],edges[i][1],pa,r); 
                for(int j=0;j<z;j++)
                {
                    if(j==i)
                    continue;
                    
                    if(c==n-1)
                    break;
                    if(findParent(edges[j][0],pa)!=findParent(edges[j][1],pa))
                    {
                         join(edges[j][0],edges[j][1],pa,r);
                         sz+=edges[j][2];
                         c++;
                    }
                }
                if(sz==size)
                {
                    //We include those cases as pseudo critcal considering which we can build a ST with size equal to MST
                    pseudo.push_back(edges[i][3]);
                }
            }
        }
        ans.push_back(v);
        for(int i=0;i<v.size();i++)
        {
            // All critical edges aren't pseudocritical edges so we turn those false, here
            isPartOfMST[v[i]]=false;
        }
        
        for(int i=0;i<z;i++)
        {
            if(isPartOfMST[i])
            {
                //all edges which are part of MST but are not critical are actually pseudo critical edges
                pseudo.push_back(i);
            }
        }
        ans.push_back(pseudo);
        return ans;
    }
};