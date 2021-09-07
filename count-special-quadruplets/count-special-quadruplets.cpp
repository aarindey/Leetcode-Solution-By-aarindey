class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n=nums.size(),ans=0;
        unordered_map<int,int> mp;
        
        for(int i=n-1;i>1;i--)
        {
            for(int j=i-1;j>0;j--)
            {
                for(int k=j-1;k>=0;k--)
                {
                
                 if (mp.count(nums[i] + nums[j] + nums[k]))
                    {
                        ans += mp[nums[i] + nums[j] + nums[k]];
                    }
                }
            }
                    mp[nums[i]]++;
        }
        return ans;
    }
        
};