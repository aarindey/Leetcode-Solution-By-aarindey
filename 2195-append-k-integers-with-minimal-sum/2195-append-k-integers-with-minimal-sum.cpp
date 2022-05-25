#define ll long long int
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<ll> st;
        for(auto num:nums)
        {
            st.insert(num);
        }
        ll start=1;
        ll ans=0,l,r;
        for(auto num:st)
        {
            r=num;
            l=start;
            if(k>(r-l))
            {
                k-=(r-l);
                ans+=(r*(r-1))/2-(l*(l-1))/2;
                start=r+1;
            }
            else
            {
                break;
            }
        }
        l=start;
        r=l+k;
        ans+=(r*(r-1))/2-(l*(l-1))/2;
        return ans;
    }
};