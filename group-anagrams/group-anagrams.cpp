class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > mp;
        string t;
        for(int i=0;i<strs.size();i++)
        {
             t=strs[i];
             sort(t.begin(),t.end());
             mp[t].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto pr:mp)
        {
            ans.push_back(pr.second);
        }
    return ans;
    }
};