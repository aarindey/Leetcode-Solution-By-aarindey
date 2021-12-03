class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mul=nums[0],maxMul=nums[0];
     for(int i=0;i<nums.size();i++)
     {
         mul=nums[i];
         maxMul=max(maxMul,mul);
         if(i!=nums.size()-1)
         for(int j=i+1;j<nums.size();j++)
         {
             mul*=nums[j];
             maxMul=max(maxMul,mul);
         }
     }
        return maxMul;
    }
};