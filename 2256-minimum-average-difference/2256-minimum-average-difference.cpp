#define ll long long int
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll n=nums.size();
        vector<ll> prefix(n);
        prefix[0]=nums[0];
        for(ll i=1;i<n;i++)
        {
            prefix[i]=nums[i]+prefix[i-1];
        }
        ll mini=INT_MAX; 
        ll left,right;
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            left=prefix[i];
            ll l,r;
            l=i+1;
            r=n-i-1;
            ll v1,v2;
            if(i==n-1)
            {
                 right=0;
                 v1=left/l;
                 v2=0;
            }
                else 
                {
            right=prefix[n-1]-prefix[i];
                     v1=left/l;
                     v2=right/r;
                }
                
                              ll x=abs(v1-v2);
                              if(x<mini)
                              {
                                  mini=x;
                                  ans=i;
                          
        }            
        }
    return ans;
    }
};