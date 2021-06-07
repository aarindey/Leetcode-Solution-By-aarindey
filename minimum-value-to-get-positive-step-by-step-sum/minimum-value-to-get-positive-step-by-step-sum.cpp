class Solution {
public:
    int minStartValue(vector<int>& nums) {
     int sum=0;  
      int ans=INT_MAX;  
     for(int i=0;i<nums.size();i++)
     {
        sum+=nums[i];
         ans=min(sum,ans);
     }
        if(ans>=1)
         return 1;   
        return (1-ans);
    }
};