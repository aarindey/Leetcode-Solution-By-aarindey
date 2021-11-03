class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        int sum1=0,sum2=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>=nums[i-1])
            sum1++;
        }
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
            sum2++;
        }
     return sum1==n-1||sum2==n-1;
    }
};