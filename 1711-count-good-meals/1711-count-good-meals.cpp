#define ll long long
class Solution {
public:
    int countPairs(vector<int>& d) {
        ll mod=1e9+7;
        unordered_map<ll,ll> mp2;
        ll n=d.size(),ans=0;
        sort(d.begin(),d.end());
        ll maxTwo;
        if(n>=2)
        {
            maxTwo=log2(d[n-1]+d[n-2]);
        }else
        {
            maxTwo=log2(d[n-1]);
        }
        for(ll i=0;i<n;i++)
        {
            if(!mp2.empty())
            for(ll j=0;j<=maxTwo;j++)
            {
                ll x=(ll)pow(2,j)-d[i];
                if(mp2.find(x)!=mp2.end())
                {
                    ans=(ans+mp2[x])%mod;
                }
            }
            mp2[d[i]]++;
        }
        return (int)ans%mod;
    }
};