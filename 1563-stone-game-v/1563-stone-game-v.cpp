class Solution {
public:
    int fun(vector<int> &v,int l,int r,vector<vector<int> > &dp)
    {
        if(dp[l][r]!=-1)
        return dp[l][r];
        int total=accumulate(v.begin()+l,v.begin()+r+1,0);
        int sum=0,res=0;  
        if(l>=r)
        return 0;
        for(int i=l;i<r;i++)
        {
            sum+=v[i];
            total-=v[i];
            if(sum<total)
            {
                res=max(res,sum+fun(v,l,i,dp));      
            }
            else if(sum>total)
            {
                res=max(res,total+fun(v,i+1,r,dp));
            }
            else
            {
                res=max(res,sum+max(fun(v,l,i,dp),fun(v,i+1,r,dp)));
            }
        }
        return dp[l][r]=res;
    }
    int stoneGameV(vector<int>& stoneValue) {       
        int n=stoneValue.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fun(stoneValue,0,n-1,dp);
    }
};