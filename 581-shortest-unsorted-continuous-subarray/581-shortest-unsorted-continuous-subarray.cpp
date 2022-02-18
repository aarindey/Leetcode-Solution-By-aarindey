class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN,begin=-1,end=-1,mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
         maxi=max(maxi,nums[i]);
         if(maxi>nums[i])
         {
             end=i;
         }
        }
        for(int i=n-1;i>=0;i--)
        {
            mini=min(mini,nums[i]);
            if(mini<nums[i])
            {
                begin=i;
            }
        }
        if(begin==end)
        return 0;
        return end-begin+1;
    }
};