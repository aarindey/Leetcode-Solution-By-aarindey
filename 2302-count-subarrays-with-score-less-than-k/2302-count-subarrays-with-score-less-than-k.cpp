#define ll long long int
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll i=-1,j=0;
        ll n=nums.size();
        vector<ll> p(n,0);
        p[0]=nums[0];
        for(ll i=1;i<n;i++)
        {
            p[i]=p[i-1]+nums[i];
        }
        ll sum=0;
        ll ans=0;
        while(j<n)
        {
            if(i==-1)
            {
                if(p[j]*(j+1)>=k)
                {
                    cout<<n-j<<endl;
                    ans+=n-j;
                    i++;
                } 
                else
                {
                    j++;
                }
            }
            else
            {
                if((p[j]-p[i])*(j-i)>=k)
                {
                    ans+=n-j;
                    i++;
                }
                else
                {
                    j++;
                }   
            } 
        }
        ans=n*(n+1)/2-ans;
        return ans;
    }
};