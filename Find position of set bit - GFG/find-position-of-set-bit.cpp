// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        bool ok=true;
        int ans;
        for(int i=0;i<32;i++)
        {
            if((1<<i)&N)
            {
            if(!ok)
            {
                return -1;
            }
            ans=i+1;
            ok=false;
            }
        }
        if(ok==true)
        return -1;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends