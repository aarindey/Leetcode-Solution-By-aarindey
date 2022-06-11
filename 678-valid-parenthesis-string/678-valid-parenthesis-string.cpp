class Solution {
public:
    bool check(string s,int i,int n,int count,vector<vector<int>> &dp)
    {
        if(i>=n)
        {
            return count==0;
        }
        if(count>n/2)
        {
            return false;
        }
        if(count<0)
        {
            return false;
        }
        if(dp[i][count]!=-1)
        {
            return dp[i][count];
        }
        bool ans=false;
        if(s[i]=='*')
        {
            ans|=check(s,i+1,n,count+1,dp);
            ans|=check(s,i+1,n,count,dp);
            ans|=check(s,i+1,n,count-1,dp);
        }
        else
        {
            if(s[i]=='(')
            ans|=check(s,i+1,n,count+1,dp);
            else
            ans|=check(s,i+1,n,count-1,dp);
        }
        return dp[i][count]=ans;
    }
    bool checkValidString(string s) {
       int n=s.size();
       vector<vector<int>> dp(n+1,vector<int>(101,-1));
       return check(s,0,n,0,dp);
    }
};