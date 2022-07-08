class Solution {
public:
    set<string> dict;
    int n;
    void backtrack(string &s,vector<string> &ans,string str)
    {
        if(s.size()==0)
        {
            ans.push_back(str);
            return;
        }
        for(int j=1;j<=s.size();j++)
        {
            string left=s.substr(0,j);
            string right=s.substr(j);
            if(dict.find(left)!=dict.end())
            {
                string z=str;
                str+=left;
                str+=' ';
                backtrack(right,ans,str);
                str=z;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        for(auto &word:wordDict)
        {
            dict.insert(word);
        }
        
        vector<string> ans;
        backtrack(s,ans,"");
        for(auto &x:ans)
        {
            x.pop_back();
        }
        return ans;
    }
};