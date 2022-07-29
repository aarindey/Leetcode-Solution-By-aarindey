class Solution {
public:
    int n;
    bool check(string s,string pattern)
    {
        unordered_map<char,char> mp;
        if(n!=s.length())
        return false;
            for(int i=0;i<n;i++)
            {
                if(mp.find(s[i])!=mp.end())
                {
                if(mp[s[i]]!=pattern[i])
                return false;
                }
                mp[s[i]]=pattern[i];
            }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        n=pattern.length();
        for(int i=0;i<words.size();i++)
        {
            if(check(words[i],pattern)&&check(pattern,words[i]))
            {
                ans.push_back(words[i]);
            }
        }
    return ans;
    }
};