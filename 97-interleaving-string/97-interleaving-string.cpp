class Solution {
public:
    int dp[101][101];
    bool helper(string s1,string s2,string s3,int n1,int n2,int n3,int i,int j,int k)
    {
        if(k==n3)
        return true;
        if(dp[i][j]!=-1)
        return dp[i][j];
        bool case1,case2;
        case1=case2=false;
        if(s1[i]==s3[k])
        case1=helper(s1,s2,s3,n1,n2,n3,i+1,j,k+1);
        if(s2[j]==s3[k])
        case2=helper(s1,s2,s3,n1,n2,n3,i,j+1,k+1);
        return dp[i][j]=case1||case2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length(),n2=s2.length(),n3=s3.length();
        if(n1+n2!=n3)
        return false;
        memset(dp,-1,sizeof(dp));
        return helper(s1,s2,s3,n1,n2,n3,0,0,0);
    }
};