class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(nums.size()<3)
        return ans;    
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            continue;    
            int low=i+1,high=nums.size()-1;
            while(low<high)
            {
                
                if(nums[i]+nums[low]+nums[high]==0)
                {
                    ans.push_back({nums[i],nums[low],nums[high]});
                    low++;
                    while(low<high&&nums[low]==nums[low-1])
                    low++;    
                }   
                else if(nums[i]+nums[low]+nums[high]>0)
                high--;
                else
                low++;    
            }    
        }  
        return ans;
    }
};