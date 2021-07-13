class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int mul=1,mul2=1,count=0;
        for(int i=0;i<nums.size();i++)
        {
        mul*=nums[i];
            if(nums[i]==0)
               count++;
            if(nums[i]!=0)
               mul2*=nums[i]; 
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            ans.push_back(mul/nums[i]);
            else if(nums[i]==0&&count==1)
            {
                ans.push_back(mul2);
            }
            else if(count>1)
             ans.push_back(0);   
        }
        return ans;
    }
};