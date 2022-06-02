class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,INT_MAX);
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            int cost1=dp[i+1]+costs[0];
            int cost7,cost30;
            int d7=i,d30=i;
            while(d7<n&&days[d7]<days[i]+7)
            {
                d7++;
            }
            while(d30<n&&days[d30]<days[i]+30)
            {
                d30++;
            }
            cost7=dp[d7]+costs[1];
            cost30=dp[d30]+costs[2];
            dp[i]=min(cost1,min(cost7,cost30));
        }
        return dp[0];
    }
};