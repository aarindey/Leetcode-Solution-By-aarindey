class Solution {
public:
    set<string> dict;
    unordered_map<string,bool> memo;
    int n;
    bool check(string &s)
    {
        if(s.size()==0)
        {
            return true;
        }
        for(int j=1;j<=s.length();j++)
        {
            string left=s.substr(0,j);
            string right=s.substr(j);
            if(memo.find(s)!=memo.end())
            return memo[s];
            if(dict.find(left)!=dict.end()&&check(right))
            {
                return memo[s]=true;
            }
        }
        return memo[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        for(auto &word:wordDict)
        {
            dict.insert(word);
        }
        return check(s);
    }
};