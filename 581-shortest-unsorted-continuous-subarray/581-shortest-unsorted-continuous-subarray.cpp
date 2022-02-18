class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     vector<int> nums2;
        nums2=nums;
        sort(nums2.begin(),nums2.end());
        int n=nums.size();
        int left,right;
        if(nums==nums2)
        return 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=nums2[i])
            {
                left=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]!=nums2[i])
            {
                right=i;
                break;
            }
        }
        return right-left+1;
    }
};