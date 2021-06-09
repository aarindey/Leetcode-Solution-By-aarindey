class Solution {
public:
    int firstUniqChar(string s) {
     unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }    
        char c;
        for(auto pr:mp)
        {
            if(pr.second==1)
             c=pr.first;   
        }
        for(int i=0;i<s.length();i++)
        {
            if(c==s[i])
                return i;
        }   
        return -1;
    }
};