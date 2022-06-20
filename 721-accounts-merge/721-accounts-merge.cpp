#define ll long long int
class Solution {
public:
ll find(ll x,vector<int> &parent)
{
    if (parent[x] != x)
    {

        parent[x] = find(parent[x],parent);
    }
    return parent[x];
}
void Union(ll x,ll y,vector<int> &parent,vector<int> &rank)
{

    ll xset = find(x,parent);
    ll yset = find(y,parent);

    if (xset == yset)
        return;

    if (rank[xset]< rank[yset])
    {
        parent[xset] = yset;
    }
    else if (rank[xset] > rank[yset])
    {
        parent[yset] = xset;
    }

    else
    {
        parent[yset] = xset;
        rank[xset] = rank[xset] + 1;
    }
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        vector<vector<string>> ans;
        int n=acc.size();
        int z=1;
        map<string,int> mp;
        for(auto vec:acc)
        {
            for(int i=1;i<vec.size();i++)
            {
                if(mp.find(vec[i])==mp.end())
                {
                    mp[vec[i]]=z++;
                }
            }
        }
        vector<int> parent(z,0);
        vector<int> rank(z,0);
        for(int i=0;i<z;i++)
        {
            parent[i]=i;
        }
        for(auto vec:acc)
        {
            for(int i=2;i<vec.size();i++)
            {
                Union(mp[vec[1]],mp[vec[i]],parent,rank);
            }
        }
        map<int,set<string>> mpp;
        map<int,string> name;
        for(auto vec:acc)
        {
            int x=find(mp[vec[1]],parent);
            name[x]=vec[0];
            for(int i=1;i<vec.size();i++)
            {
                mpp[x].insert(vec[i]);
            }
        }
        for(auto pr:mpp)
        {
            vector<string> temp;
            temp.push_back(name[pr.first]);
            for(auto &it:pr.second)
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// 1 2 1 3 4 5