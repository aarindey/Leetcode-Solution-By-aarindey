class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int n=coins.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[coins[i]]++;
        }
        int ans=0;
        for(auto &pr:mp)
        {
            int numMax=pr.first*pr.second;
            if(ans+1>=pr.first)
            {
                ans+=numMax;
            }
            else
            break;
        }
        return ans+1;
    }
};