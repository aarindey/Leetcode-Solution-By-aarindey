class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans=0;
        int n=s.length();
        int m=t.length();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int miss=0;
                for(int p=0;i+p<n&&j+p<m;p++)
                {
                    if(s[i+p]!=t[j+p])
                    {
                        miss++;
                        if(miss>=2)
                        break;
                    }
                    ans+=miss;
                }
            }
        }
        return ans;
    }
};