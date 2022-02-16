class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
      unordered_map<char,int> mp;
      unordered_map<string,int> mp2;
      int i=0,n=s.size();
      int j=0,res=0;
        while(j<n)
        {
            mp[s[j]]++;
            if(j-i+1>minSize)
            {
                if(--mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            if(j-i+1==minSize&&mp.size()<=maxLetters)
            {
                string str=s.substr(i,j-i+1);
                mp2[str]++;
                res=max(res,mp2[str]);
            }
            j++;
        }
        return res;
    }
};

