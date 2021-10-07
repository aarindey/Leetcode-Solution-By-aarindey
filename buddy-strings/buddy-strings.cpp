class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n1=s.length(),n2=goal.length();
        if(n1!=n2)
        return false;
        if(s==goal)
        {
            unordered_map<char,int> mp;
            for(char ch:s)
            mp[ch]++;
            if(mp.size()<s.size())
            return true;
            else
            return false;
        }
        vector<int> v;
        for(int i=0;i<n1;i++)
        {
            if(s[i]!=goal[i])
            v.push_back(i);
        }
        if(v.size()==2&&s[v[0]]==goal[v[1]]&&s[v[1]]==goal[v[0]])
        return true;
        
        return false;
    }
};