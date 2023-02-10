//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        unordered_map<char, int> mp1, mp2;
        for(auto e : "balloon"){
            mp1[e]++;
        }
        for(auto &e : s){
            if(mp1.count(e)){
                mp2[e]++;
            }
        }
        int ans = INT_MAX;
        for(auto &e : mp2){
            ans = min(ans, e.second/mp1[e.first]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends