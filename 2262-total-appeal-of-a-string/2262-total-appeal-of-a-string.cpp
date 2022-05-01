#define ll long long
class Solution {
public:
    long long appealSum(string s) {
       ll ans=0;
       int n=s.length();
       vector<ll> dp(n+1,0);
       map<char,ll> mp;
        for(ll i=0;i<n;i++)
        {
            char ch=s[i];
            if(mp.find(ch)!=mp.end())
            dp[i+1]=dp[i]+i-mp[ch];
            else
            dp[i+1]=dp[i]+i+1;
            ans+=dp[i+1];
            mp[ch]=i;
        }
        return ans;
    }
};