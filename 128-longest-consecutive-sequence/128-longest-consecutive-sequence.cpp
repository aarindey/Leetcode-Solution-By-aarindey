class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int ans=1,n=nums.size();
        if(n==0)
        return 0;
        if(n==1)
        return 1;
        int maxi=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]==1)
            {
                ans++;
                maxi=max(maxi,ans);
            }
            else if(nums[i]==nums[i-1])
            continue;
            else
            ans=1;
        }
        if(maxi==INT_MIN)
        return 1;
        return maxi;
    }
};