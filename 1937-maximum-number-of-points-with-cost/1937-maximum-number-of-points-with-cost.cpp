#define ll long long int
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();
        vector<vector<ll>> dp(n,vector<ll>(m));
        for(ll i=0;i<m;i++)
        {
            dp[0][i]=points[0][i];
        }
        for(ll i=1;i<n;i++)
        {
            vector<ll> pre(m),post(m);
            pre[0]=dp[i-1][0];
            post[m-1]=dp[i-1][m-1]-(m-1);
            for(ll k=1;k<m;k++)
            {
                pre[k]=max(pre[k-1],dp[i-1][k]+k);
            }
            for(ll k=m-2;k>=0;k--)
            {
                post[k]=max(post[k+1],dp[i-1][k]-k);
            }
            for(ll j=0;j<m;j++)
            {
                dp[i][j]=max(points[i][j]+j+post[j],points[i][j]-j+pre[j]);
            }
        }
        ll ans=0;
        for(ll i=0;i<m;i++)
        {
            ans=max(ans,dp[n-1][i]);
        }
        return ans;
    }
};