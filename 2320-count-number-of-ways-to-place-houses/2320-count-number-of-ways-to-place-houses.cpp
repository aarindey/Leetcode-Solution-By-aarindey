#define ll long long int
ll mod=1e9+7;
class Solution {
public:
     ll rec(int n,vector<ll>& dp)
    {
        if(n<=0) 
        return 1;
         
        if(dp[n]!=-1) return dp[n];
        ll res=0;
        
        res=(res%mod+rec(n-1,dp)%mod)%mod;
        res=(res%mod+rec(n-2,dp)%mod)%mod;
         
        return dp[n]=res;
    }
   int countHousePlacements(int n) {
        vector<ll> dp(n+100,-1);
        ll z=rec(n,dp);
        z=((z%mod)*1LL*(z%mod))%mod;
        
        return z;
    }
};