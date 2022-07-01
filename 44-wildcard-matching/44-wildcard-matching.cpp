class Solution {
public:
//     bool fun(string s,string p,int n,int m,vector<vector<int>> &dp)
//     {
//         if(n==0&&m==0)
//         {
//             return true;
//         }
//         if(m==0)
//         {
//             return false;
//         }
//         if(n==0)
//         {
//             bool flag=true;
//             for(int i=0;i<m;i++)
//             {
//                 if(p[i]!='*')
//                 {
//                     flag=false;
//                     break;
//                 }
//             }
//             return flag;
//         }
//         if(dp[n][m]!=-1)
//         {
//             return dp[n][m];
//         }
        
//         if(s[n-1]==p[m-1])
//         {
//             return dp[n][m]=fun(s,p,n-1,m-1,dp);
//         }
//         if(p[m-1]=='?')
//         {
//             return dp[n][m]=fun(s,p,n-1,m-1,dp);
//         }
//         if(p[m-1]=='*')
//         {
//             return dp[n][m]=fun(s,p,n,m-1,dp)||fun(s,p,n-1,m,dp);
//         }
//         return dp[n][m]=false;
//     }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=false;
        }
        bool flag=true;
        for(int i=0;i<=m;i++)
        {
            if(i>=1&&p[i-1]!='*')
            {
                flag=false;
            }
            dp[0][i]=flag;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {

                    if(s[i-1]==p[j-1]||p[j-1]=='?')
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if(p[j-1]=='*')
                    {
                        dp[i][j]=dp[i][j-1]||dp[i-1][j];
                    }
                    else
                    dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};