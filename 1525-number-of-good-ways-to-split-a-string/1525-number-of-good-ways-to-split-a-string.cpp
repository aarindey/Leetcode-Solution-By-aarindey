class Solution {
public:
    int numSplits(string s) {
        int ans=0;
        int n=s.length();
        unordered_map<char,int> mp1,mp2;
        for(auto ch:s)
        {
            mp2[ch]++;
        }
        for(int i=1;i<n;i++)
        {
            mp1[s[i-1]]++;
            if(--mp2[s[i-1]]==0)
            mp2.erase(s[i-1]);
            if(mp1.size()==mp2.size())
            {
                ans++;
            }
        }
        return ans;
    }
};