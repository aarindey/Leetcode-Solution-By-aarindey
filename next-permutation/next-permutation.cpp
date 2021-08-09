class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n=nums.size();
        int i,k;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                break;
            }    
        }    
        if(i<0)
        reverse(nums.begin(),nums.end());
        else
        {
            for(k=n-1;k>=0;k--)
            {
                if(nums[k]>nums[i])
                break;
            }
            swap(nums[i],nums[k]);
            reverse(nums.begin()+i+1,nums.end());
        }    
    }
};