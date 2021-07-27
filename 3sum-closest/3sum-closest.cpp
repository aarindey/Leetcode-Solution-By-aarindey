//16. 3Sum Closest
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int mini=INT_MAX,res;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    if(abs(nums[i]+nums[j]+nums[k]-target)<mini)
                    {
                     mini=  abs(nums[i]+nums[j]+nums[k]-target);
                       res= nums[i]+nums[j]+nums[k];        
                    }
                }   
            }   
        } 
        return res;  
    }
};