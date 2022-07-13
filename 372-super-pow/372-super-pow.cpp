#define ll long long int
class Solution {
public:
    ll binpow(ll a,ll b,ll m)
    {
        ll prod=1;
        while(b>0)
        {
            if(b&1)
            {
                b--;
                prod=(prod*1ll*a)%m;
            }
            else
            {
                a=(a*1ll*a)%m;
                b=b>>1;
            }
        }
        return prod%m;
    }
    int superPow(int a, vector<int>& b) {
        ll m=1337;
        ll ETF_of_m=1140;
        ll sum=0;
        ll n=b.size();
        for(int i=0;i<n;i++)
        {
            sum=(10*sum+b[i])%ETF_of_m;
        }
        return binpow(a,sum,m);
    }
};