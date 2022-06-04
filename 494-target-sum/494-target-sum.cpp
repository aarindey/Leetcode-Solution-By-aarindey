class Solution {
public:
    int count=0;
    void solve(vector<int> &nums,int i,int n,int sum,int target)
    {
        if(i==n)
        {
            if(sum==target)
            {
                count++;
            }
            return;
        }
        
        solve(nums,i+1,n,sum+nums[i],target);
        solve(nums,i+1,n,sum-nums[i],target);     
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums,0,nums.size(),0,target);
        return count;
    }
};