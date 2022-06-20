class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
        {
            if(k%2==0)
            {
                return nums[0];
            }
            else
            {
                return -1;
            }
        }
        if(k==0)
        {
            if(n>=1)
            return nums[0];
            else
            return -1;
        }
        int m=min(k-1,n);
        int maxi=-1;
        for(int j=0;j<m;j++)
        {
            maxi=max(nums[j],maxi);
        }
        if(k<n)
        {
            maxi=max(nums[k],maxi);
        }
        return maxi;
    }
};