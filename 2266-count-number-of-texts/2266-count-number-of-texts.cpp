#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    int solve(string &s,int i,int n,vector<int> &dp)
    {
        if(i>=n)
        {
            return 1;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        ll ans=0;
        if(i+1<n&&s[i]==s[i+1])
        {
            ans+=solve(s,i+2,n,dp)%mod;
            if(i+2<n&&s[i]==s[i+2])
            {
                ans+=solve(s,i+3,n,dp)%mod;
                if(i+3<n&&s[i]==s[i+3]&&(s[i]=='9'||s[i]=='7'))
                {
                    ans+=solve(s,i+4,n,dp)%mod;
                }
            }
        }
        ans=(ans%mod+solve(s,i+1,n,dp)%mod)%mod;
        return dp[i]=ans%mod;
    }
    int countTexts(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return solve(s,0,n,dp);
    }
};