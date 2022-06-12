class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> lis(n,1);
        int maxi=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0&&lis[i]<=lis[j]+1)
                {
                    lis[i]=lis[j]+1;
                    maxi=max(maxi,lis[i]);
                }
            }
        }
        
        int prev=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(lis[i]==maxi&&(prev==-1||prev%nums[i]==0))
            {
                ans.push_back(nums[i]);
                prev=nums[i];
                maxi--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};