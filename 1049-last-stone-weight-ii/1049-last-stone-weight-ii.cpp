class Solution {
public:
    int total;
    int solve(vector<int> &v,int i,int n,int sum,vector<vector<int> > &memo)
    {
        if(i==n)
        {
            return abs(total-2*sum);
        }
        if(memo[i][sum]!=-1)
        {
            return memo[i][sum];
        }
        int pick,nonpick;
        pick=solve(v,i+1,n,sum+v[i],memo);
        nonpick=solve(v,i+1,n,sum,memo);
        return memo[i][sum]=min(pick,nonpick);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        total=accumulate(stones.begin(),stones.end(),0);
        vector<vector<int> > memo(n+1,vector<int>(3001,-1));
        return solve(stones,0,n,0,memo);
    }
};