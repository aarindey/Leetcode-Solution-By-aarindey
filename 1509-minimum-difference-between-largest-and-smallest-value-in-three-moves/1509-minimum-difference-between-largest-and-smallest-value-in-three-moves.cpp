class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4)
        return 0;
        sort(nums.begin(),nums.end());
        //changing first second and third smallest to next smallest
        int res=nums[n-1]-nums[3];
        //changing last three greatest numbers
        res=min(res,nums[n-4]-nums[0]);
        //changing 2 smallest+1 greatest
        res=min(res,nums[n-2]-nums[2]);
        //changing 2 greatest+ 1 smallest;
        res=min(res,nums[n-3]-nums[1]);
        return res;
    }
};