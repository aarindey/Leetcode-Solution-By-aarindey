#define ll long long int
class Solution {
public:
    ll sum(vector<ll> &dig)
    {
        ll s=accumulate(dig.begin(),dig.end(),(ll)0);
        return s;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        ll ans=0;
        vector<ll> dig;
        ll z=n;
        while(z>0)
        {
            dig.push_back(z%10);
            z/=10;
        }
        dig.push_back(0);
        reverse(dig.begin(),dig.end());
        ll r=dig.size()-1;
        ll mul=1;
        while(sum(dig)>target)
        {
            while(dig[r]==0)
            {
                r--;
                mul*=10;
            }
            ll z=10-dig[r];
            ans+=z*mul;
            dig[r]=0;
            dig[r-1]++;
        }
        return ans;
    }
};