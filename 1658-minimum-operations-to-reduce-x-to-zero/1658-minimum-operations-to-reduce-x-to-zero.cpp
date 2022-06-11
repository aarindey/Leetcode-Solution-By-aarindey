#define ll long long int
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total==x)
        return n;
        if(x>total)
        return -1;
        unordered_map<int,int> mp;
        mp[0]=0;
        int target=total-x;
        int ans=INT_MIN;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            curr+=nums[i];
            mp[curr]=i;
            
            if(curr==target)
            {
                ans=max(ans,i+1);
            }
            if(curr==(total-target))
            {
                ans=max(ans,n-i-1);
            }
            if(curr>target)
            {
                if(mp.find(curr-target)!=mp.end())
                {
                    ans=max(ans,i-mp[curr-target]);
                }
            }
        }
        
        return (ans==INT_MIN)?-1:(n-ans);
    }
};