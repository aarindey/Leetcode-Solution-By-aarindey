class Solution {
public:
    void solve(vector<vector<string>> &ans,vector<string> &v,int col,int n,vector<int> &rowHash,vector<int> &lowerDiag,vector<int> &upperDiag)
{
    if(col==n)
    {
        ans.push_back(v);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(rowHash[row]==0&&lowerDiag[row+col]==0&&upperDiag[n-1+col-row]==0)
        {
            v[row][col]='Q';
            rowHash[row]=1;
            lowerDiag[row+col]=1;
            upperDiag[n-1+col-row]=1;
            solve(ans,v,col+1,n,rowHash,lowerDiag,upperDiag);
            v[row][col]='.';
            rowHash[row]=0;
            lowerDiag[row+col]=0;
            upperDiag[n-1+col-row]=0;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    
    string s(n,'.');
    vector<string> v(n,s);
    vector<int> rowHash(n,0);
    vector<int> lowerDiag(2*n-1,0);
    vector<int> upperDiag(2*n-1,0);
    solve(ans,v,0,n,rowHash,lowerDiag,upperDiag);
    return ans;        
}
};