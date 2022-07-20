#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    vector<vector<ll>> dp;
    int fun(int i1,int i2)
    {
        ll ans=0;
        if(i1<0||i2<0)
        return 0;
        if(i1==i2&&i1==0)
        return 1;
        
        
        if(dp[i1][i2]!=-1)
        return dp[i1][i2];
        if(i1==i2)
        {
            ans+=fun(i1-1,i2-1);
            ans=ans%mod;
            ans+=fun(i1-2,i2-1);
            ans=ans%mod;
            ans+=fun(i1-1,i2-2);
            ans=ans%mod;
            ans+=fun(i1-2,i2);
            ans=ans%mod;
            // ans+=fun(i1,i2-2);
            // ans=ans%mod;
        }
        if(i1==i2+1)
        {
            ans+=fun(i1-2,i2-1);
            ans=ans%mod;
            // ans+=fun(i1-2,i2);
            // ans=ans%mod;
        }
        if(i2==i1+1)
        {
            ans+=fun(i1-1,i2-2);
            ans=ans%mod;
            // ans+=fun(i1,i2-2);
            // ans=ans%mod;
        }
        if(i1>i2)
        {
            ans+=fun(i1-2,i2);
        }
        if(i1<i2)
        ans+=fun(i1,i2-2);
        
        ans=ans%mod;
        
        return dp[i1][i2]=ans;
    }
    int numTilings(int n) {
        dp.resize(n+1,vector<ll>(n+1,-1));
        return fun(n,n);
    }
};