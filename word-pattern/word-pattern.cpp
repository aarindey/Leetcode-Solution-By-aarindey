class Solution {
public:
    bool wordPattern(string pattern, string s) {
unordered_map<char,string> mp;
        s+=' ';
        vector<string> word;
        int left=0;
       
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                string str=s.substr(left,i-left);
                word.push_back(str);
                left=i+1;
            }
        }
         if(word.size()!=pattern.size())
            return false; 
        for(int i=0;i<pattern.size();i++)
        {
            if(mp.find(pattern[i])==mp.end())
            {
                mp[pattern[i]]=word[i];
            }
            else
            {
                if(mp[pattern[i]]!=word[i])
                    return false;
            }
        }
        for(auto pr:mp)
        {
            for(auto pr2:mp)
            {
                if(pr.first!=pr2.first&&pr.second==pr2.second)
                return false;    
            }
        }
        return true;
    }
};