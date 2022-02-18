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
         mini=min(mini,nums[n-i-1]);
         if(mini<nums[n-i-1])
         {
            begin=n-i-1;
         }
        }
        if(begin==end&&begin==-1)
        return 0;
        return end-begin+1;
    }
};