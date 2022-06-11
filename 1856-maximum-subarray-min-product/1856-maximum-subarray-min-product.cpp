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
            if(st.empty())
            {
                nsr[i]=n;
                st.push(i);
                continue;
            }
            else
            {
                nsr[i]=st.top();
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
            while(!st.empty() && nums[i]<=nums[st.top()])
                st.pop();
            if(st.empty())
            {
                nsl[i]=-1;
                st.push(i);
                continue;
            }
            else
            {
                nsl[i]=st.top();
                st.push(i);
            }
        }
        return nsl;
    }
    int maxSumMinProduct(vector<int>& nums) {
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
        ll ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int idxL=nextSmallerL[i];
            int idxR=nextSmallerR[i];
            if(idxL==-1&&idxR==n)
            {
                ans=max(ans,(pre[n-1]*(1ll)*nums[i]));
            }
            else if(idxL==-1&&idxR!=n)
            {
                ans=max(ans,(pre[idxR-1]*(1ll)*(nums[i])));
            }
            else if(idxL!=-1&&idxR==n)
            {
                ans=max(ans,((pre[n-1]-pre[idxL])*(1ll)*(nums[i])));
            }
            else
            {
                ans=max(ans,((pre[idxR-1]-pre[idxL])*(1ll)*(nums[i])));
            }
        }
        return ans%mod;
    }
};