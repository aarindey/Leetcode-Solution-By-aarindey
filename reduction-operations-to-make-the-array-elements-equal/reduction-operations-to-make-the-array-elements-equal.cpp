class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=1;i--)
        {
            if(nums[i]>nums[i-1])
            ans+=n-i;
        }
        return ans;
    }
};