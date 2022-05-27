class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
                else if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string lcs="";
        int i=n,j=m;
        while(i!=0&&j!=0)
        {
            if(str1[i-1]==str2[j-1])
            {
                lcs+=str1[i-1];
                i--;
                j--;
            }
            else 
            {
                if(dp[i][j]==dp[i-1][j])
                {
                    i--;
                }
                else
                {
                    j--;
                }
            }
        }
        //cout<<lcs<<endl;
        reverse(lcs.begin(),lcs.end());
        string scs="";
        i=0;
        j=0;
        int k=0;
        while(i<n&&j<m)
        {
            if(k<lcs.length()&&str1[i]==lcs[k])
            {
                if(str2[j]!=lcs[k])
                {
                    scs+=str2[j];
                    j++;
                }
                else
                {
                    scs+=lcs[k];
                    k++;
                    i++;
                    j++;
                }
            }
            else if(k<lcs.length()&&str2[j]==lcs[k])
            {
                scs+=str1[i];
                i++;
            }
            else if(k<lcs.size())
            {
                scs+=str1[i];
                scs+=str2[j];
                i++;
                j++;
            }
            else
            {
                break;
            }
        }
        if(i<n)
        {
            scs+=str1.substr(i);
        }
        if(j<m)
        {
            scs+=str2.substr(j);
        }
        return scs;
    }
};