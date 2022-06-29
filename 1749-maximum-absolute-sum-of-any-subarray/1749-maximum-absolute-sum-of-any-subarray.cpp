class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int sum=0,maxi=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0)
            sum=0;   
        }
      return maxi;
    }
    int minSubArray(vector<int>& nums) {
     int sum=0,mini=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>0)
            sum=0;
            mini=min(mini,sum); 
        }
      return mini;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        return max(maxSubArray(nums),abs(minSubArray(nums)));
    }
};