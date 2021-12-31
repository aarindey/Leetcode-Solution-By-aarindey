class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> mp;
        int n=paths.size();
        for(int i=0;i<n;i++)
        {
            mp[paths[i][0]]=paths[i][1];
        }
        for(int i=0;i<n;i++)
        {
            if(mp.find(paths[i][1])==mp.end())
            return paths[i][1];
        }
        return "";
    }
};