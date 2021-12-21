class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1]=1;
        int p1,p2,p3;
        p1=1;
        p2=1;
        p3=1;
        for(int i=2;i<=n;i++)
        {
            int f1,f2,f3;
            f1=2*dp[p1];
            f2=3*dp[p2];
            f3=5*dp[p3];
            int mini=min(f1,min(f2,f3));
            dp[i]=mini;
            if(f1==mini)
            {
                p1++;
            }
            if(f2==mini)
            {
                p2++;
            }
            if(f3==mini)
            {
                p3++;
            }
        }
        return dp[n];
    }
};