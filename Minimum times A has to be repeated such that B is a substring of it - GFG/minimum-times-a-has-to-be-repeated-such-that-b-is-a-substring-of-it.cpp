//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool issubstring(string s1, string s2)
    {
        if (s2.find(s1) != string::npos)
        {
            return true;
        }
        return false;
    }
    int minRepeats(string A, string B) {
        // code here
        int a = A.size();
        int b = B.size();
        int temp = b / a + 1;
        string newa = "";
        int ans = -1;
        for (int i = 0; i < temp + 1 ; ++i)
        {
            newa += A;
            if (issubstring(B, newa))
            {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends