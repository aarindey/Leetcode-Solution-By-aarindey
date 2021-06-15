class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count=0,mx=0;
        for(int i=0;i<nums.size()-1;i++)
        {
           if(nums[i]<nums[i+1]) 
           {
               count++;
               mx=max(mx,count);
           }
            else
            {
                count=0;
            }
        }
       
         return mx+1;   
    }
};