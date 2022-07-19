class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //map<int,int> mp;
        int n=nums.size();
        int curr=0;
        int ans=INT_MAX;
        int j=0;
        for(int i=0;i<n;i++)
        {
            curr+=nums[i];
            if(curr>=target)
            {
                ans=min(ans,i-j+1);
                while(j<=i&&curr>=target)
                {
                    curr-=nums[j];
                    ans=min(ans,i-j+1);
                    j++;
                }
            }
        }
        if(ans==INT_MAX)
        return 0;
        return ans;
    }
};