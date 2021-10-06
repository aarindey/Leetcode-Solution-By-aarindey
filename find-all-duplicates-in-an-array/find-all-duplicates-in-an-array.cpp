class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
     vector<int> v;
     unordered_map<int,int> mp;
     for(auto x:nums)
     {
         mp[x]++;
     }
    for(auto pr:mp)
    {
        if(pr.second==2)
        v.push_back(pr.first);
    }
    return v;
    }
};