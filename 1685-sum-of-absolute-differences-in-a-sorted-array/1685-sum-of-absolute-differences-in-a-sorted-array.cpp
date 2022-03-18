class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans,pre(n),suf(n);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            pre[i]=nums[i]+pre[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+nums[i];
        }
        for(int i=0;i<n;i++)
        {
        if(i==0)
        {
            ans.push_back(i*nums[i]+suf[i+1]-nums[i]*(n-i-1));
        }
        else if(i==n-1)
        {
            ans.push_back(i*nums[i]-pre[i-1]-nums[i]*(n-i-1));  
        }
        else
            ans.push_back(i*nums[i]-pre[i-1]+suf[i+1]-nums[i]*(n-i-1));
        }
        return ans;
    }
};