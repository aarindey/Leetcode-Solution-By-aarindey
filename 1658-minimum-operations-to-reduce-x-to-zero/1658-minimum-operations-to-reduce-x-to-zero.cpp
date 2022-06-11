#define ll long long int
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<ll> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        int total=prefix[n-1];
        if(total==x)
        return n;
        if(x>total)
        return -1;
        unordered_map<int,int> mp;
        mp[0]=0;
        int target=total-x;
        int ans=INT_MIN;

        for(int i=0;i<n;i++)
        {
            mp[prefix[i]]=i;
            
            if(prefix[i]==target)
            {
                ans=max(ans,i+1);
            }
            if(prefix[i]==(total-target))
            {
                ans=max(ans,n-i-1);
            }
            if(prefix[i]>target)
            {
                if(mp.find(prefix[i]-target)!=mp.end())
                {
                    ans=max(ans,i-mp[prefix[i]-target]);
                }
            }
        }
        
        return (ans==INT_MIN)?-1:(n-ans);
    }
};
/*
[5,2,3,1,1]
5
*/