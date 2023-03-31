//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define ll long long int
class Solution {
  public:
    long long int minOperations(int n) {
        // Code here
        if(n==1)return 0;
        ll ans=0;
        if(n&1){
            ll lim=n/2;
            ans=lim*1LL*(lim+1);
        }else{
            ll lim=n/2;
            // 1+3+5
            ans=lim*1LL* (2*1 + (lim-1)*2);
            ans=ans/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperations(n) << endl;
    }
    return 0;
}
// } Driver Code Ends