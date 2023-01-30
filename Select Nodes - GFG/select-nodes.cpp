//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
     vector<int>g[100001];
     int dp[100001][2];
     int fun(int i,int p,int c){
        int ans=0;
        if(dp[i][c]!=-1)return dp[i][c];
         if(c==0){
             ans++;
             for(auto j:g[i]){
                 if(j!=p){
                     ans+=fun(j,i,1);
                 }
             }
         }
         else{
             int k1=0;
             for(auto j:g[i]){
                 if(j!=p){
                     k1+=fun(j,i,0);
                 }
             }
             int k2=1;
             for(auto j:g[i]){
                 if(j!=p){
                     k2+=fun(j,i,1);
                 }
             }
             ans=min(k1,k2);
         }
         return dp[i][c]=ans;
     }
    int countVertex(int N, vector<vector<int>>e){
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<e.size();i++){
            g[e[i][0]].push_back(e[i][1]);
            g[e[i][1]].push_back(e[i][0]);
        }
        return min(fun(1,0,1),fun(1,0,0));
    }
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends