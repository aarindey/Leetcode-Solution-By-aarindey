#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> paths={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        vector<vector<int>> dp(n+1,vector<int>(10,0));
        for(int j=0;j<10;j++)
        {
            dp[1][j]=1;
        }
        for(int i=2;i<=n;i++)
        {
            
            for(int j=0;j<10;j++)
            {
             
                int nums=0;
                for(int &x:paths[j])
                {
                    nums+=dp[i-1][x];
                    nums=nums%mod;
                }
                dp[i][j]=nums;
            }
        }
        int ans=0;
        for(int j=0;j<10;j++)
        {
            ans+=dp[n][j];
            ans=ans%mod;
        }
        return ans;
    }
};