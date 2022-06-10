#define ll long long int
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        ll mod=1e9+7;
        ll n=nums.size();
        vector<ll> prefix(n,0);
        prefix[0]=nums[0];
        for(ll i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        ll ans=0;
        ll sum=0;
        ll total=prefix[n-1];
        for(int i=0;i<n-2;i++)
        {
            if(prefix[i]>total/3)
            break;
            ll j=lower_bound(prefix.begin()+i+1,prefix.end(),prefix[i]*2)-prefix.begin();
            ll l=upper_bound(prefix.begin()+i+1,prefix.end(),(total-prefix[i])/2+prefix[i])-prefix.begin();
            if(l<j)
            continue;
            else
            {
                if(l==n)
                {
                    ans=(ans%mod+(l-j-1)%mod)%mod;
                }
                else
                    ans=(ans%mod+(l-j)%mod)%mod;
            } 
        }
        if(n==3&&ans>1)
        return 1;
        return (int)(ans%mod);
    }
};