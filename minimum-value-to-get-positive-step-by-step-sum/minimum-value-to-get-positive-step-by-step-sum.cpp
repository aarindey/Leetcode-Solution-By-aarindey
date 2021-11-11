class Solution {
public:
    int minStartValue(vector<int>& nums) {
     int sum=nums[0];  
      int ans=nums[0];  
     for(int i=1;i<nums.size();i++)
     {
        sum+=nums[i];
         ans=min(sum,ans);
     }
        if(ans>=1)
         return 1;   
        return (1-ans);
    }
};