class Solution {
public:
    int distinctSubseqII(string s) {
    int n=s.length();
     vector<long long int> dp(n+1);
     dp[0]=1;
        const int MOD=1e9+7;
        unordered_map<char,int> lastIndex;
        for(int i=1;i<=n;i++)
        {
            dp[i]=2*dp[i-1]%MOD;
            if(lastIndex.find(s[i-1])!=lastIndex.end())
            dp[i]=dp[i]-dp[lastIndex[s[i-1]]-1];
            dp[i] %= MOD;
            lastIndex[s[i-1]]=i;
        }
        dp[n]--;
        if(dp[n]<0)
        dp[n]+=MOD;
        return dp[n];
    }
};