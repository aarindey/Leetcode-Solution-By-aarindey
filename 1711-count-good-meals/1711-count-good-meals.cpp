#define ll long long
class Solution {
public:
    int countPairs(vector<int>& d) {
        ll mod=1e9+7;
        unordered_map<ll,ll> mp2;
        ll n=d.size(),ans=0;
        for(ll i=0;i<n;i++)
        {
            if(!mp2.empty())
            for(ll j=0;j<=21;j++)
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