class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> mp;
    for(auto &word:words1)
    {
        mp[word]++;
    }
    for(auto &word:words2)
    {
        if(mp[word]<2)
        mp[word]--;
    }
        int c=0;
        for(auto pr:mp)
        {
            if(pr.second==0)
            {
                c++;
            }
        }
        return c;
    }
};