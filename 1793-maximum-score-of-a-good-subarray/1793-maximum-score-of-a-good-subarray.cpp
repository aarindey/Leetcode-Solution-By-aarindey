class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int left=nums[0];
        int right=nums[n-1];
        int i=0,j=n-1;
        if(k-1>=0)
        {
            i=k-1;
            left=nums[i];
        }
        if(k+1<n)
        {
            j=k+1;
            right=nums[j];
        }
        int ans=nums[k];
        int mini=nums[k];
        while(i>=0||j<n)
        {
            if(i>=0&&j<n)
            {
                if(nums[i]>=nums[j])
                {
                    mini=min(nums[i],mini);
                    i--;
                }
                else
                {
                    mini=min(nums[j],mini);
                    j++;
                }
            }
            else if(i>=0)
            {
                    mini=min(nums[i],mini);
                    i--;                
            }
            else if(j<n)
            {
                    mini=min(nums[j],mini);
                    j++;                
            }
            ans=max(ans,mini*((j-1)-(i+1)+1));
        }
        return ans;
    }
};