class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,0);
        int ans=0;
        unordered_map<int,int> mp;
        int sum=0;
        mp[sum]++;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            nums[i]=0;
            else
            nums[i]=1;
            if(i==0)
            {
                sum=nums[0];
            }
            else
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};