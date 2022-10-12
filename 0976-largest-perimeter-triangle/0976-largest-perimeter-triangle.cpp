class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int mx;
        sort(nums.begin(),nums.end());
        if(nums.size()<3)
         return 0;   
  for(int i=nums.size()-3;i>=0;i--)
  {
      if(nums[i+1]+ nums[i]>nums[i+2])
       return (nums[i]+nums[i+1]+nums[i+2]);   
  }
        return 0;
    }
};