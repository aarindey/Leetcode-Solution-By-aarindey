class Solution {
public:
    int find(int x,vector<int> parent)
    {
        if(x==parent[x])
        {
            cout<<x<<endl;
            return x;
        }
        return parent[x]=find(parent[x],parent);
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
            parent[x]=y;
            rank[y]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26,0);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        for(string e:equations)
        {
            if(e[1]=='=')
            {
                int x,y;
                x=e[0]-'a';
                y=e[3]-'a';
                Union(x,y,parent,rank);
            }
        }
        for(string e:equations)
        {
            if(e[1]=='!')
            {
                int x,y;
                x=e[0]-'a';
                y=e[3]-'a';
                int lhs,rhs;
                lhs=find(x,parent);
                rhs=find(y,parent);
                if(lhs==rhs)
                {
                    return false;
                }
            }
        }
        return true;
    }
};