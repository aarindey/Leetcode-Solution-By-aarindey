class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;
        int c=0;
        for(auto x:nums)
        {
            for(auto z:x)
            {
                v.push_back({z,c});
            }
            c++;
        }
        sort(v.begin(),v.end());
        int j=0;
        int total=0;
        int k=nums.size();
        int n=v.size();
        int mini=INT_MAX;
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[v[i].second]++;
            if(mp[v[i].second]==1)
            {
                total++;
            }
            if(total==k)
            {
                if(v[i].first-v[j].first+1<mini)
                {
                    mini=v[i].first-v[j].first+1;
                    ans={v[j].first,v[i].first};
                }
            }
            if(total==k)
            {
                while(j<i&&mp[v[j].second]!=1)
                {
                    mp[v[j].second]--;
                    j++;
                }
                if(v[i].first-v[j].first+1<mini)
                {
                    mini=v[i].first-v[j].first+1;
                    ans={v[j].first,v[i].first};
                }
            }
            
        }
        return ans;
    }
};