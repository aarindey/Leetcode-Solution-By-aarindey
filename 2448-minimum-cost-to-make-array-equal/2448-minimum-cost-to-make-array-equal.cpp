#define ll long long int
class Solution {
public:
    ll l,r;
    ll f(ll mid,vector<int> &nums,vector<int> &cost)
    {
        // if(mid<l||mid>r)
        // return -1;
        ll ans=0;
        for(ll i=0;i<nums.size();i++)
        {
            ans+=abs(mid-nums[i])*cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll l=*min_element(nums.begin(),nums.end());
        ll r=*max_element(nums.begin(),nums.end());
        // cout<<l<<" "<<r<<endl;
        ll low=l;
        ll high=r;
        ll ans=LLONG_MAX;
        while(low<=high)
        {
            ll mid=low+(high-low)/2;
            ll left=mid-1;
            ll right=mid+1;
            ll lval=(f(left,nums,cost));
            ll rval=(f(right,nums,cost));
            ll mval=(f(mid,nums,cost));
            if(mval!=-1)
            ans=min(ans,mval);
            
                if(left<l)
                {
                    low=mid+1;
                }
                else if(right>r)
                {
                    high=mid-1;
                }
                else if(lval<=rval)
                {
                    high=mid-1;
                }
                else if(lval>rval)
                {
                    low=mid+1;
                }
            
        }
        return ans;
    }
};