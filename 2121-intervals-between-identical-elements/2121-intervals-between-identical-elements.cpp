class Solution {
public:
    #define ll long long int
    vector<long long> getDistances(vector<int>& arr) {
     unordered_map<ll,vector<ll>> mp;
        ll n=arr.size();
        for(ll i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<ll> ans(n);
        for(auto pr:mp)
        {
            vector<ll> v=pr.second;
            ll total=accumulate(v.begin(),v.end(),(ll)0);
            ll pre=0;
            ll n2=v.size();
            ll res=0;
            for(ll i=0;i<n2;i++)
            {
                res=i*v[i]-pre+(total-pre-v[i])-(n2-i-1)*v[i];
                pre+=v[i];
                ans[v[i]]=res;
            }
        }
        return ans;
    }
};