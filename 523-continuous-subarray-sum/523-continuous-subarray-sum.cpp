class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                pre[i]=nums[0]%k;
            }
            else
            {
                pre[i]=(pre[i-1]+nums[i])%k;
                if(pre[i]==0)
                return true;
            }
        }
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(pre[i])!=mp.end()&&i-mp[pre[i]]>=2)
            {
                return true;
            }
            if(mp.find(pre[i])==mp.end())
            mp[pre[i]]=i;
        }
        return false;
    }
};