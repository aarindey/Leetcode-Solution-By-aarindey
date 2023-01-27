//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


const int mod = 1e9 + 7;

class Solution {

 public:

 int CountWays(string s){

     // Code here

     int n = s.size();

            if (n == 0) return 0;

            if (s[0] == '0') return 0;

            

            int dp[n + 1];

            dp[0] = 1;

            dp[1] = 1;

            

            for (int i = 2; i <= n; i++) {

                if (s[i - 1] == '0') {

                    if (s[i - 2] == '1' || s[i - 2] == '2') {

                        dp[i] = dp[i - 2];

                    } else {

                        return 0;

                    }

                } else if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] >= '1' && s[i - 1] <= '6')) {

                    dp[i] = (dp[i - 1] + dp[i - 2]) % mod;

                } else {

                    dp[i] = dp[i - 1];

                }

            }            

            return dp[n];

 }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends