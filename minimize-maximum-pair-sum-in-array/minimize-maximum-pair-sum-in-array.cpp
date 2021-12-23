class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=INT_MIN;
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j)
        {
            int sum=nums[i]+nums[j];
            maxi=max(sum,maxi);
            i++;
            j--;
        }
        return maxi;
    }
};