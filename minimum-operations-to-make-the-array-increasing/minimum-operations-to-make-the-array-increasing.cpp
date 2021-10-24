class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size;
        int count=0,diff=0;
        size=nums.size();
        if(size<=1)
            return 0;
        for(int i=1;i<size;i++)
        {
            if(nums[i-1]>=nums[i])
            {
               diff=nums[i-1]-nums[i]+1;
                count+=diff;
                nums[i]+=diff;
            }
        }
        return count;
    }
};