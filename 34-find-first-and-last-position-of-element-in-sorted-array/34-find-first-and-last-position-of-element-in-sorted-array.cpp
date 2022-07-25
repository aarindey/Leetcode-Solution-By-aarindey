class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,mid;
        int ans1=-1,ans2=-1;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                ans1=mid;
                right=mid-1;
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }
            else
            {
               right=mid-1; 
            }
          }
          left=0,right=nums.size()-1;
            while(left<=right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                
                ans2=mid;
                left=mid+1;
                
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }
            else
            {                        
            right=mid-1;
            }
        }
      
        return {ans1,ans2};
    }
};