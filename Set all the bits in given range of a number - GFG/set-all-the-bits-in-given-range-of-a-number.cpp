// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int setAllRangeBits(int N , int L , int R) {
        // code here
        for(int i=0;i<32;i++)
        {
            if(i+1>=L&&i+1<=R)
            {
                N|=(1<<i);
            }
        }
        return N;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.setAllRangeBits(N,L,R) << endl;
    }
    return 0;
}  // } Driver Code Ends