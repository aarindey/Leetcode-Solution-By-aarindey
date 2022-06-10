#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    ll helper(string &s,ll i,ll n,vector<ll> &dp)
    {
        if(i>=n)
        {
            return 1;
        }
        if(dp[i]!=-1)
        {
            return dp[i]%mod;
        }
        if(s[i]=='0')
        return 0; 
        int ans=0;
        if(s[i]=='*')
        ans=(ans%mod+9*(helper(s,i+1,n,dp))%mod)%mod;
        else 
        ans=(ans%mod+helper(s,i+1,n,dp)%mod)%mod;
        if(i+1<n)
        {
            if(s[i]=='*'&&s[i+1]!='*')
            {
                if(s[i+1]<='6')
                {
                    ans=(ans%mod+2*helper(s,i+2,n,dp)%mod)%mod;
                }
                else
                {
                    ans=(ans%mod+helper(s,i+2,n,dp)%mod)%mod;
                }
            }
            else if(s[i]!='*'&&s[i+1]=='*')
            {
                if(s[i]=='2')
                {
                    ans=(ans%mod+6*helper(s,i+2,n,dp)%mod)%mod;
                }
                else if(s[i]=='1')
                {
                    ans=(ans%mod+9*helper(s,i+2,n,dp)%mod)%mod;
                }
            }
            else if(s[i]=='*'&&s[i+1]=='*')
            {
                ans=(ans%mod+15*helper(s,i+2,n,dp)%mod)%mod;
            }
            else
            {
                string str=s.substr(i,2);
                if(stoi(str)>=10&&stoi(str)<=26)
                {
                    ans=(ans%mod+helper(s,i+2,n,dp)%mod)%mod;
                }
            }
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        ll n=s.length();
        vector<ll> dp(n+1,-1);
        return helper(s,0,n,dp);
    }
};