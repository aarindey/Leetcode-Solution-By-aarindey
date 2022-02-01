class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
        return false;
        vector<int> c1(26,0),c2(26,0);
        for(char ch:s1)
        {
            c1[ch-'a']++;
        }
        int k=s1.size();
        int n=s2.length();
        for(int i=0;i<k;i++)
        {
            c2[s2[i]-'a']++;
        }
        if(c1==c2)
        return true;
        for(int i=0;i<n-k;i++)
        {
            c2[s2[i]-'a']--;
            c2[s2[i+k]-'a']++;
            if(c1==c2)
            return true;
        }
        return false;
    }
};