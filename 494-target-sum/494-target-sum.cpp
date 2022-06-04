class Solution {
public:
    int total=0;
    int solve(vector<int> &nums,int i,int n,int sum,int target,vector<vector<int> > &memo)
    {
        if(i==n)
        {
            if(sum==target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
        if(memo[i][total+sum]!=INT_MIN)
        {
            return memo[i][total+sum];
        }
        int add=0,sub=0;
        add+=solve(nums,i+1,n,sum+nums[i],target,memo);
        sub+=solve(nums,i+1,n,sum-nums[i],target,memo);     
        return memo[i][sum+total]=add+sub;
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        total=accumulate(nums.begin(),nums.end(),(long long)0);
        int n=nums.size();
        vector<vector<int>> memo(n+1,vector<int>(total*2+1,INT_MIN));
        return solve(nums,0,nums.size(),0,target,memo);
    }
};