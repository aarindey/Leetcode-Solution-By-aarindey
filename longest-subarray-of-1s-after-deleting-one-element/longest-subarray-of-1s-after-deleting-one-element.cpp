class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int zeroPos;
        int n=nums.size();
        int ans=0;
        int c=0;
        while(i<n&&j<n)
        {
            if(nums[j]==0)
            {
                c++;
                if(c>1)
                {
                    i=zeroPos+1;
                    
                }
                zeroPos=j;
            }
            j++;
            ans=max(ans,j-i);
        }
        return ans-1;
    }
};