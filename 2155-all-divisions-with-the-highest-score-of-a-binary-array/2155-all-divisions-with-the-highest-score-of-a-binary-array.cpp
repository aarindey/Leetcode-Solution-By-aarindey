class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        int c=prefix[n-1];
        int num;
        map<int,vector<int>> mp;
        mp[prefix[n-1]].push_back(0);
        for(int i=1;i<=n;i++)
        {
        num=i-prefix[i-1]+prefix[n-1]-prefix[i-1];
        c=max(c,num);
        mp[num].push_back(i);
        }
        return mp[c];
    }
};