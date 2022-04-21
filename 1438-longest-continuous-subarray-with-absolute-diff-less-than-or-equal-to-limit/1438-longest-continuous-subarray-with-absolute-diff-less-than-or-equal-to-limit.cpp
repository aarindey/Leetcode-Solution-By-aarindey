class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int i=0,j=0;
        multiset<int> m;
        int ans=1;
        m.insert(nums[0]);
        while(i<n&&j<n)
        {
            if(*m.rbegin()-*m.begin()<=limit)
            {
                ans=max((j-i+1),ans);
                j++;
                if(j<n)
                {
                m.insert(nums[j]);
                }
            }
            else 
            {
                m.erase(m.find(nums[i]));
                i++;
            }
        }
        return ans;
    }
};