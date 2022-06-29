#define ll long long int
class Solution {
public:
    bool ispos(ll mid,vector<int> &v,ll t)
    {
        ll c=0;
        for(ll i=0;i<v.size();i++)
        {
            c+=v[i]/mid;
            if(v[i]%mid)
            c++;
        }
        return c<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        ll low=1;
        ll high=*max_element(nums.begin(),nums.end());
        ll n=nums.size();
        if(n>threshold)
        return -1;
        if(n==threshold)
        {
            return high;
        }
        ll ans;
        while(low<=high)
        {
            ll mid=(low+(high-low)/2);
            if(ispos(mid,nums,threshold))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return (int)ans;
    }
};