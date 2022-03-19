class Solution {
public:
    int dp[1002][1002];
    int solve(string &floor,int i,int n,int l,vector<int> &prefix)
    {
        if(i>=floor.size()||n==0)
        return 0;
        if(dp[i][n]!=-1)
        return dp[i][n];
        if(floor[i]=='0')
        return dp[i][n]=solve(floor,i+1,n,l,prefix);
        int x=min((int)(floor.size()),(int)(i+l))-1;
        int white=prefix[x];
        if(i!=0)
        white-=prefix[i-1];
        int ans1=white+solve(floor,i+l,n-1,l,prefix);
        int ans2=solve(floor,i+1,n,l,prefix);
        return dp[i][n]=max(ans1,ans2);
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n=floor.size();
        vector<int> prefix(n);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=numCarpets;j++)
            {
                dp[i][j]=-1;
            }
        }
        if(floor[0]=='1')
        prefix[0]=1;
        else
        prefix[0]=0;
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+(floor[i]=='1');
        }
        int total_white=prefix[n-1];
        if(total_white==0)
        return 0;
        return total_white-solve(floor,0,numCarpets,carpetLen,prefix);
    }
};