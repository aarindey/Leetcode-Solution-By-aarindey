class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int n2=primes.size();
        vector<int> pointers(n2,1);
        vector<int> dp(n+1);
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int mini=INT_MAX;
            for(int j=0;j<n2;j++)
            {
                mini=min(mini,dp[pointers[j]]*primes[j]);
            }
            dp[i]=mini;
            for(int j=0;j<n2;j++)
            {
                if(dp[pointers[j]]*primes[j]==mini)
                {
                    pointers[j]++;
                }
            }
            
        }
        return dp[n];
    }
};