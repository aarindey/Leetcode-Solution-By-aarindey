#define ll long long int
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        map<ll,ll> mp;
        ll n=nums.size();
        for(ll i=0;i<n;i++)
        {
            nums[i]=__gcd(nums[i],k);
            mp[nums[i]]++;
        }
        ll ans=0;
        for(auto &x:mp)
        {
            for(auto &y:mp)
            {
                if((x.first*y.first)%k==0)
                {
                    if(x.first==y.first)
                    {
                        ans+=(mp[x.first]-1)*mp[y.first];   
                    }
                    else
                    {
                        ans+=(mp[x.first]*mp[y.first]);
                    }
                }
            }
        }
        return ans/2;
    }
};