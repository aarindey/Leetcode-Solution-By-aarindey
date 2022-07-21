class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size();
        int mul=1;
        int j=-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            mul*=nums[i];
            if(mul>0)
            {
                mul=1;
                ans=max(ans,i-j);
            }
            else if(mul<0)
            {
                mul=-1;
            }
            else 
            {
                mul=1;
                j=i;
            }
        }
        j=n;
        mul=1;
        for(int i=n-1;i>=0;i--)
        {
            mul*=nums[i];
            if(mul>0)
            {
                mul=1;
                ans=max(ans,j-i);
            }
            else if(mul<0)
            {
                mul=-1;
            }
            else
            {
                j=i;
                mul=1;
            }
        }
        return ans; 
    }
};