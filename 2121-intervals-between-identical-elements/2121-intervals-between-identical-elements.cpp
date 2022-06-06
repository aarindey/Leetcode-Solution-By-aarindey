class Solution {
public:
    #define ll long long int
    ll abbs(ll x)
    {
        return abs(x);
    }
    vector<long long> getDistances(vector<int>& arr) {
     map<ll,vector<ll>> mp;
        ll n=arr.size();
        for(ll i=n-1;i>=0;i--)
        {
            mp[arr[i]].push_back(i);
        }
        vector<ll> ans(n);
        
        for(auto pr:mp)
        {
            ll res=0;
            vector<ll> v=pr.second;
            ll pre=0;
            ll total=0;
            for(auto &x:v)
            {
                total+=x;
            }
            for(ll i=0;i<v.size();i++)
            {
                res=abs((i)*(v[i])-pre)+abbs((total-pre-v[i])-(v.size()-i-1)*v[i]);
                ans[v[i]]=res;
                pre+=v[i];
            }
            
        }
        
        return ans;
    }
};