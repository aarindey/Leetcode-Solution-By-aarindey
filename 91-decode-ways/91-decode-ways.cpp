class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1,0);
        dp[0]=1;
        if(s[0]=='0')
        {
            dp[0]=0;
        }
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0'&&s[i-1]=='0')
            {
                dp[i]=0;
            }
            else if(s[i]!='0'&&s[i-1]=='0')
            {
                dp[i]=dp[i-1];
            }
            else if(s[i]=='0'&&s[i-1]!='0')
            {
                if(s[i-1]=='1'||s[i-1]=='2')
                {
                    dp[i]=(i>=2?dp[i-2]:dp[0]);
                }
                else
                {
                    dp[i]=0;
                }
            }
            else
            {
                string str=s.substr(i-1,2);
                int z=stoi(str);
                if(z<=26)
                {
                    dp[i]=dp[i-1]+(i>=2?dp[i-2]:dp[0]);
                }
                else
                {
                    dp[i]=dp[i-1];
                }
            }
        }
        return dp[n-1];
    }
};