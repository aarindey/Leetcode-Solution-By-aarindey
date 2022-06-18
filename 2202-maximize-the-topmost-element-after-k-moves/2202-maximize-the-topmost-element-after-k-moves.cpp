class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1&&k==1)
        return -1;
        if(k==0)
        {
            return nums[0];
        }
        if(k==1)
        {
            return nums[1];
        }
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
        int maxi=INT_MIN;
        int i;
        int preMax=INT_MIN;
        if(k==n)
        {
        for(i=0;i<n-1;i++)
        {
            maxi=max(maxi,nums[i]);
            if(k!=1)
            preMax=maxi;
            k--;
            if(k==0)
            break;
        }
        }
        else
        for(i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            if(k!=1)
            preMax=maxi;
            k--;
            if(k==0)
            break;
        }
        ++i;
        if(i<n)
        {
            maxi=max(maxi,nums[i]);
            if(preMax!=INT_MIN&&maxi>nums[i]&&maxi!=preMax)
            return max(preMax,nums[i]);
        }
        return maxi;
    }
};