class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int>  vec;
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int sum_ele=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            vec.push_back(nums[i]);
            sum-=nums[i];
            sum_ele+=nums[i];
            if(sum_ele>sum)
              break;  
        }
        return vec;
    }
};