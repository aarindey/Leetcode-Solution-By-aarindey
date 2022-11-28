class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
      vector<vector<int>> ans;
        map<int,int> mp1,mp2;
        for(auto m:matches)
        {
            mp1[m[0]]++;
            mp2[m[1]]++;
        }
        vector<int> v;
        for(auto pr:mp1)
        {
            if(mp2.find(pr.first)==mp2.end())
            {
                v.push_back(pr.first);
            }
        }
        ans.push_back(v);
        v.clear();
        for(auto pr:mp2)
        {
            if(pr.second==1)
            {
                v.push_back(pr.first);
            }
        }
        ans.push_back(v);
        return ans;
    }
};