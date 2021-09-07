class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
    int n=nums.size(),t=target;
    int left=0,right=0,len=INT_MAX;
    while(left<n)
    {
         t-=nums[right];
        if(t<=0)
        {
            len=min(len,right-left+1);
        }
        right++;
        if(t<0||right>=n)
        {
             t=target;
            left++;
            right=left;
        }
    }
        if(len==INT_MAX)
        return 0;  
        
        return len;    
    }
};
