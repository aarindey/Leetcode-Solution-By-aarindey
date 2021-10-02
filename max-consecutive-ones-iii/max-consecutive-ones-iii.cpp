class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j=-1;
        int count=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            count++;
            while(count>k)
            {
                j++;
                if(nums[j]==0)
                count--;
            }
            int len=i-j;
            if(len>ans)
            ans=len;
        }
        return ans;
    }
};