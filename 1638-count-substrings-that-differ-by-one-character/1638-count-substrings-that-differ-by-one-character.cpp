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
                if(s[i]!=t[j])
                {
                    int left=1,right=1;
                    while(i-left>=0&&j-left>=0&&s[i-left]==t[j-left])
                    {
                        ++left;
                    }
                    while((i+right)<n&&(j+right)<m&&s[i+right]==t[j+right])
                    {
                        ++right;
                    }
                    ans+=(left*right);
                }
            }
        }
        return ans;
    }
};