class Solution {
public:
    int find(vector<int> &par,int u)
    {
        if(u==par[u])
            return u;
        return par[u]=find(par,par[u]);
    }
    void unions(vector<int> &par,int u,int v)
    {
        int pu=find(par,u),pv=find(par,v);
        par[pu]=pv;
    }
    bool gcdSort(vector<int>& nums)
    {
        vector<int> par(100001);
        for(int i=0;i<100001;i++)
        {
            par[i]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=2;j*j<=nums[i];j++)
            {
                if(nums[i]%j==0)
                {
                    unions(par,nums[i],j);
                    unions(par,nums[i]/j,j);
                }
            }
        }
        vector<int> a=nums;
        sort(a.begin(),a.end());
        for(int i=0;i<nums.size();i++)
        {
            if(a[i]!=nums[i])
            {
                if(find(par,a[i])!=find(par,nums[i]))
                    return false;
            }
        }
        return true;
        
    }
};