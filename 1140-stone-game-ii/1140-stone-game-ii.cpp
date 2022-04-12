class Solution {
public:
    int fun(vector<int>& piles,int i,int m,int sum,vector<vector<int>> &memo)
    {
        int n=piles.size();
        if(i>=n) return 0;
        if(memo[i][m]!=-1)
        return memo[i][m];
        int res=0;
        int currsum=0;
        for(int x=1;x<=2*m;x++)
        {
            if(i+x>n) break;
            currsum+=piles[i+x-1];
            res=max(res,sum-fun(piles,i+x,max(x,m),sum-currsum,memo));
        }
        return memo[i][m]=res;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        int sum=accumulate(piles.begin(),piles.end(),0);
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        return fun(piles,0,1,sum,memo);
    }
};