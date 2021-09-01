class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int divisor=nums[0],dividend=nums[nums.size()-1];
        while(dividend%divisor!=0)
        {
            int t=divisor;
            divisor=dividend%divisor;
            dividend=t;
        }    
        return divisor;
    }
};