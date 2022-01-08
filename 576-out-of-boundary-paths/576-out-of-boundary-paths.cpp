#define ll long long int
class Solution {
public:
    ll mod=1e9+7;
    ll helper(vector<vector<vector<ll>>> &memo,int m,int n,int maxMove,int r,int c)
    {
        if(maxMove<0)
        return 0;
        
        if(r==m||c==n||r<0||c<0)
        return 1;
        
        if(memo[r][c][maxMove]!=-1)
        return memo[r][c][maxMove];
        
        ll left,right,up,down;
        left=helper(memo,m,n,maxMove-1,r,c-1);
        right=helper(memo,m,n,maxMove-1,r,c+1);
        up=helper(memo,m,n,maxMove-1,r-1,c);
        down=helper(memo,m,n,maxMove-1,r+1,c);
        ll ans=(left+right+up+down)%mod;
        
        return memo[r][c][maxMove]=ans;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<ll>>> memo(m+1,vector<vector<ll>>(n+1,vector<ll>(maxMove+1,-1)));
        return (int)helper(memo,m,n,maxMove,startRow,startColumn);
    }
};