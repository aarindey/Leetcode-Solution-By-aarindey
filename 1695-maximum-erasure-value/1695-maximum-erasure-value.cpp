class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        unordered_map<int,int> mp;
        int sum=0,ans=INT_MIN;
        while(j<n)
        {
            mp[nums[j]]++;
            sum+=nums[j];
            if(j-i+1==mp.size())
            {
                ans=max(ans,sum);
            }
            else if(j-i+1>mp.size())
            {
                while(j-i+1>mp.size())
                {
                    sum-=nums[i];
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                    {
                        mp.erase(nums[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};