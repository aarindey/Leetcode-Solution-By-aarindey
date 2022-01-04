class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0,ans;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        ans=sum;
        for(int i=k;i<n;i++)
        {
            sum+=nums[i];
            sum-=nums[i-k];
            ans=max(sum,ans);
        }
        return (double)(ans/k);
    }
};