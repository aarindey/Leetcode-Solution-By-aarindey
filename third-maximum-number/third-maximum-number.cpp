class Solution {
public:
    int thirdMax(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int max=2;
        int n=nums.size();  
           if(n==1)
            return nums[0];
        
     for(int i=n-2;i>=0;i--)
     {
         if(nums[i]==nums[i+1])
          continue;
         else
           max--;  
       if(max==0)
          return nums[i]; 
        else if(i==0)
       return nums[n-1];
     }
        return nums[n-1];
    }
};