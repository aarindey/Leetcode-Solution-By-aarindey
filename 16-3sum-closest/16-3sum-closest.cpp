class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
int n=nums.size(),low,high,ans=0,mini=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
          low=i+1;
          high=n-1;
           while(low<high)
           {
               if(abs(nums[i]+nums[high]+nums[low]-target)<mini)
               {
                   mini=abs(nums[i]+nums[high]+nums[low]-target);
                   ans=nums[i]+nums[high]+nums[low];
               }
               if(nums[i]+nums[high]+nums[low]<target)
               {
                   low++;
               }    
              else
              high--;
                
           }   
        } 
      return ans;  
    }
};