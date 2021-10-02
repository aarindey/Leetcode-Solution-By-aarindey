class Solution {
public:
    bool solve(vector<int> &nums,int k,vector<bool> &visited,int start,int sumPerSet,int currSum)
    {
        if(k==0)
        return true;
        if(currSum>sumPerSet)
        return false;
        if(currSum==sumPerSet)
        return solve(nums,k-1,visited,0,sumPerSet,0);
        for(int i=start;i<nums.size();i++)
        {
            if(visited[i])
            continue;
            visited[i]=true;
            if(solve(nums,k,visited,start+1,sumPerSet,currSum+nums[i]))
            return true;
            visited[i]=false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size(),sum=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        sum+=nums[i];
        if(n<k)
        return false;
        if(sum%k!=0)
        return false;
        int sumPerSet=sum/k;
        return solve(nums,k,visited,0,sumPerSet,0);
    }
};