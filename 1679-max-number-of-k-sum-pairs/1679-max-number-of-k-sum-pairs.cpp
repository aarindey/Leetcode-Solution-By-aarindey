class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      int n=nums.size();
        unordered_map<int,int> cnt;
        for(auto num:nums)
        {
            cnt[num]++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(k-nums[i]!=nums[i])
            {
            if(cnt.find(k-nums[i])!=cnt.end()&&cnt[nums[i]]>0&&cnt[k-nums[i]]>0)
            {
                cnt[nums[i]]--;
                cnt[k-nums[i]]--;
                ans++;
            }
            }
            else 
            {
              if(cnt[nums[i]]>1&&nums[i]*2==k)
            {
                cnt[nums[i]]--;
                cnt[k-nums[i]]--;
                ans++;
            }  
            }
        }
        return ans;
    }
};