class Solution {
public:
    int fun(vector<int>& piles,int i,int sum,vector<int> &memo)
    {
        int n=piles.size();
        if(i>=n) return 0;
        if(memo[i]!=-1)
        return memo[i];
        int res=INT_MIN;
        int currsum=0;
        for(int x=1;x<=3;x++)
        {
            if(i+x>n) break;
            currsum+=piles[i+x-1];
            res=max(res,sum-fun(piles,i+x,sum-currsum,memo));
        }
        return memo[i]=res;
    }
    string stoneGameIII(vector<int>& piles) {
        int n=piles.size();
        int sum=accumulate(piles.begin(),piles.end(),0);
        vector<int> memo(n+1,-1);
        int x=fun(piles,0,sum,memo);
        
        if(2*x>sum) return "Alice";
        if(2*x<sum) return "Bob";
        return "Tie";
    }
};