class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length(),c=n;
        vector<vector<bool> > dp(n,vector<bool>(n));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
        }    
        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j=l+i-1;
                if(l==2&&s[i]==s[j])
                {
                dp[i][j]=true;
                c++;
                }
                else if(s[i]==s[j]&&dp[i+1][j-1])
                {
                    dp[i][j]=true;
                    c++;
                }
                else
                dp[i][j]=false;    
            }
        }
        return c;
    }
};