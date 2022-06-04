class Solution {
public:
    bool isSafe(int row,int col,vector<string> &v,int n)
    {
        int row1=row,col1=col;
        while(row>=0&&col>=0)
        {
         if(v[row][col]=='Q')
             return false;
            row--;
            col--;
        }
        row=row1;
        col=col1;
        while(col>=0)
        {
            if(v[row][col]=='Q')
            {
                return false;
            }
            col--;
        }
        row=row1;
        col=col1;
        while(col>=0&&row<n)
        {
            if(v[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,vector<string> &v,vector<vector<string>> &ans,int n)
    {
        if(col==n)
        {
            ans.push_back(v);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,v,n))
            {
                v[row][col]='Q';
                solve(col+1,v,ans,n);
                v[row][col]='.';
            }
        }
        
    }
    int totalNQueens(int n) {
        
         vector<string> board(n,string(n,'.'));
        
        vector<vector<string> > ans;
        solve(0,board,ans,n);
        return ans.size();
    }
};