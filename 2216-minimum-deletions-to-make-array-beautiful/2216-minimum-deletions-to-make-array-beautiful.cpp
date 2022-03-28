class Solution {
public:
    int minDeletion(vector<int>& nums) {
     int n=nums.size();
     if(n==0)
     return 0;
        int i,j=0,ans=0;
        for(i=0;i<n;i++)
        {
            int j=i;
            while(i+1<n&&nums[i]==nums[i+1])
            {
                i++;
            }
            ans+=i-j;
            i++;
        }
        if(i!=n)
        ans++;
        return ans;
    }
};