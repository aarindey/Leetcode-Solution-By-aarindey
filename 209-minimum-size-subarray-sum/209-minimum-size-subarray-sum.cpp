class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums)
{
    int n = nums.size();
    int len = INT_MAX,left=0,sum=0;
    for(int right=0;right<n;right++)
    {
        sum+=nums[right];
        while(sum>=target)
        {
            len=min(len,right-left+1);
            sum-=nums[left++];
        }
    }
      return (len==INT_MAX)?0:len;
}
};
