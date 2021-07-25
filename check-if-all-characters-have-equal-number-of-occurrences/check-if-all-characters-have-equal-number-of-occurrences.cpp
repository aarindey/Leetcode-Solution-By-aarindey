class Solution {
public:
    bool areOccurrencesEqual(string s) {
     unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }    
        int count=0;
        for(auto pr:mp)
        {
            if(count==0)
            {
                count=pr.second;
            }  
            else if(count!=pr.second)
            {
                return false;
            }
            count=pr.second;
        }
        return true;
    }
};