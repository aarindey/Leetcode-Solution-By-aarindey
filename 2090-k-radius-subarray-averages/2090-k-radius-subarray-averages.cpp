#define ll long long int
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,-1);
        vector<ll> pre(n);
        pre[0]=nums[0];
        for(ll i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        ll div=2*k+1;
        for(ll i=k;i<n-k;i++)
        {
            if(i==k)
            {
                ans[i]=pre[i+k]/div;
            }
            else
            {
                ans[i]=(pre[i+k]-pre[i-k-1])/div;
            }
        }
        return ans;
    }
};