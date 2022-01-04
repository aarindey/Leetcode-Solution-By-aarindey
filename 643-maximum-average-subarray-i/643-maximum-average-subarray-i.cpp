class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double ans=0;
        vector<int> prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        double avg;
        ans=(double)prefixSum[k-1]/k;
        for(int i=k;i<n;i++)
        {
            avg=(double)(prefixSum[i]-prefixSum[i-k])/k;
            ans=max(ans,avg);
        }
        return ans;
    }
};