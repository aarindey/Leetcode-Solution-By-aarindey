class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        if(nums.size()==0)
        return -1;
        if(k==1)
        return 0;
        
        for(int i=0;i<nums.size()-k+1;i++)
        {
            mini=min(mini,nums[i+k-1]-nums[i]);
        }
        return mini;
    }
};