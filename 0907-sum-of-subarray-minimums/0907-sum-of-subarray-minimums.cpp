#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    vector<int> NSER(vector<int> &nums){
        stack<int> st;
        int n=nums.size();
        vector<int> nsr(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]<=nums[st.top()])
                st.pop();
            if(st.size()>0)
            {
                nsr[i]=st.top();
                st.push(i);
            }
            else
            {
                st.push(i);
            }
        }
        return nsr;
    }
    vector<int> NSEL(vector<int> &nums){
        stack<int> st;
        int n=nums.size();
        vector<int> nsl(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<nums[st.top()])
                st.pop();
            if(st.size()>0)
            {
                nsl[i]=st.top();
                st.push(i);
            }
            else
            {
                st.push(i);
            }
        }
        return nsl;
    }
    int sumSubarrayMins(vector<int>& nums) {
        int n=nums.size();
        vector<ll> pre(n,0);
        pre[0]=nums[0];
        for(ll i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        vector<int> nextSmallerL,nextSmallerR;
        nextSmallerL=NSEL(nums);
        nextSmallerR=NSER(nums);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int idxL=nextSmallerL[i]+1;
            int idxR=nextSmallerR[i]-1;
            ans=ans+nums[i]*(1ll)*(i-idxL+1)*(1ll)*(idxR-i+1);
            ans=ans%mod;
        }
        return ans%mod;
    }
};