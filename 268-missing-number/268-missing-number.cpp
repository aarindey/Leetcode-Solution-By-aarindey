class Solution {
public:
    int missingNumber(vector<int>& nums) {
      sort(nums.begin(),nums.end());
        int max=nums[nums.size()-1];
        for(int i=0;i<=max;i++)
        {
            if(i!=nums[i])
              return i;  
        }
     return (max+1);   
    }
};