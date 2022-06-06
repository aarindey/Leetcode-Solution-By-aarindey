class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     int n=nums.size(); 
     vector<int> lis(n,1);
     int maxi=0;
     for(int i=1;i<n;i++)
     {
         for(int j=0;j<i;j++)
         {
             if(nums[j]<nums[i]&&lis[i]<=lis[j])
             {
                 lis[i]=1+lis[j];
                 if(lis[i]>maxi)
                 maxi=lis[i];    
             }   
         }   
     }   
    if(maxi==0)
    return 1;
    return maxi;
    }
};