class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size()-1; 
        int lastIndex=0;
        for(int i=0;i<=n;i++)
        {
          if(nums[i]!=0)
           nums[lastIndex++]=nums[i];   
        }   
        for(int i=lastIndex;i<=n;i++)
        {
            nums[i]=0;
        }
    }
};