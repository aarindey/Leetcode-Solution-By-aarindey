class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        int maxi=INT_MIN;
        char c;
        for(char ch:s)
        {
            mp[ch]++;
            if(mp[ch]>maxi)
            {
                maxi=mp[ch];
                c=ch;
            }
        }
        int n=s.length();
        if(maxi>(n+1)/2)
        return "";
        string ans(n,'0');
        int i=0;
        while(mp[c]>0)
        {
            ans[i]=c;
            mp[c]--;
            i+=2;
        }
        for(auto pr:mp)
        {
            while(mp[pr.first]>0)
            {
                if(i>=ans.size())
                i=1;
                ans[i]=pr.first;
                mp[pr.first]--;
                i+=2;
            }
        }
        return ans;
    }
};