// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends


int minDeletions(string s, int n) { 
    //complete the function here
        vector<vector<int> > dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        dp[i][i]=1;
        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j=l+i-1;
                if(l==2&&s[i]==s[j])
                {
                    dp[i][j]=2;
                }
                else if(s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                } 
                else
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);    
            }
        }
        return n-dp[0][n-1];
} 