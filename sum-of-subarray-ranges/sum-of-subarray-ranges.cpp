class Solution {
public:
    #define ll long long
    long long subArrayRanges(vector<int>& nums) {
     long long ans=0;
      int n=nums.size();
        ll maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            maxi=nums[i];
            mini=nums[i];
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]>maxi)
                maxi=nums[j];
                if(nums[j]<mini)
                mini=nums[j];
                ans+=(ll)(maxi-mini);
                  
            }
        }
        return ans;
    }
};