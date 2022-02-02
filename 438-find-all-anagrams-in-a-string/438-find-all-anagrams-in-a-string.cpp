class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> c1(26,0),c2(26,0),ans;
        int k=p.size(),n=s.size();
        if(k>n)
        return ans;
        for(int i=0;i<k;i++)
        {
            c1[p[i]-'a']++;
        }
        
        for(int i=0;i<k;i++)
        {
            c2[s[i]-'a']++;
        }
        if(c1==c2)
        {
            ans.push_back(0);
        }
        for(int i=0;i<n-k;i++)
        {
            c2[s[i]-'a']--;
            c2[s[i+k]-'a']++;
            if(c2==c1)
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};