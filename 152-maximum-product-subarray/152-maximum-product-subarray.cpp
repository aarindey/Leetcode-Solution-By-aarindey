class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=nums[0];
        int mini=nums[0];
        int ans=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
            {
                int premaxi=maxi;
                maxi=max(nums[i],mini*nums[i]);
                mini=min(nums[i],premaxi*nums[i]);
            }
            else
            {
                maxi=max(nums[i],maxi*nums[i]);
                mini=min(nums[i],mini*nums[i]);
            }
           // cout<<maxi<<" "<<mini<<endl;
            ans=max(ans,maxi);
        }
        return ans;
    }
};