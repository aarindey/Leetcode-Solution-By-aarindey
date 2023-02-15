//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
void dfs(int i, int j, vector<vector<bool>> &ocean, int n, int m, vector<vector<int>> &mat, int lst) {
        if (i<0 || j<0 || i>=n || j>=m || ocean[i][j] || mat[i][j] < lst) {
            return;
        }
        ocean[i][j]=true;
        dfs(i+1, j, ocean, n, m, mat, mat[i][j]);
        dfs(i, j+1, ocean, n, m, mat, mat[i][j]);
        dfs(i-1, j, ocean, n, m, mat, mat[i][j]);
        dfs(i, j-1, ocean, n, m, mat, mat[i][j]);
    }
    int water_flow(vector<vector<int>> &mat,int n,int m){
    // Write your code here.
    vector<vector<int>> ans;
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        for (int i=0; i<n; i++) {
            dfs(i, 0, pacific, n, m, mat, INT_MIN);
            dfs(i, m-1, atlantic, n, m, mat, INT_MIN);
        }
        for (int j=0; j<m; j++) {
            dfs(0, j, pacific, n, m, mat, INT_MIN);
            dfs(n-1, j, atlantic, n, m, mat, INT_MIN);
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans.size();
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends