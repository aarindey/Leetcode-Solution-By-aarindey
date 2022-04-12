class Solution {
public:
    bool fun(int n,vector<int> &memo)
    {
        bool res=false;
        if(memo[n]!=-1)
            return memo[n];
        for(int i=1;i*i<=n;i++)
        {
            res=res|(!fun(n-i*i,memo));
        }
        return memo[n]=res;
    }
    bool winnerSquareGame(int n) {
        vector<int> memo(n+1,-1);
        return fun(n,memo);
        
    }
};