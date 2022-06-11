class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int> pre(n,0);
        vector<int> suff(n,0);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=suff[i+1]+nums[i];
        }
        int count=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            if(suff[i]>x)
            {
                break;
            }
            if(suff[i]==x)
            {
                count=min(count,n-i);
            }
            else
            {
                int idx=lower_bound(pre.begin(),pre.end(),x-suff[i])-pre.begin();
                if(idx<i&&pre[idx]+suff[i]==x)
                {
                    count=min(count,idx+1+n-i);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(pre[i]>x)
            {
                break;
            }
            if(pre[i]==x)
            {
                count=min(count,i+1);
            }
        }
        return count==INT_MAX?-1:count;
    }
};