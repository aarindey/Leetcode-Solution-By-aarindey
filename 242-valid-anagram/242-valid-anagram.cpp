class Solution{
public:
bool isAnagram(string s, string t)
{
        unordered_map<char,int> mp;
        int i;
        for(i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        for(i=0;i<t.length();i++)
        {
            mp[t[i]]--;
        }  
        for(auto pr:mp)
        {
            if(pr.second!=0)
            return false;
        }
        return true;
}
};