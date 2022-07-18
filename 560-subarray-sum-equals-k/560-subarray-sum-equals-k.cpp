class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        map<int,int> mp;
        int curr=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            curr+=nums[i];
            if(curr-k==0)
            ans++;
            if(mp.find(curr-k)!=mp.end())
            {
                ans+=mp[curr-k];
            }
            mp[curr]++;
        }
        return ans;
    }
};