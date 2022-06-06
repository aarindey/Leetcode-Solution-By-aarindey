class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> mp;
        int n=nums.size();
        vector<int> pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        int ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            if(mp.find(pre[i]-goal)!=mp.end())
            {
                ans+=mp[pre[i]-goal];
            }
            mp[pre[i]]++;
        }
        return ans;
    }
};