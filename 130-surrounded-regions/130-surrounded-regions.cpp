class Solution {
public:
    void dfs(vector<vector<char> > &board,int i, int j,int n,int m)
    {
        if(i<0||j<0||i>=n||j>=m||board[i][j]!='O')
        return;
        board[i][j]='Z';
        dfs(board,i+1,j,n,m);
        dfs(board,i-1,j,n,m);
        dfs(board,i,j-1,n,m);
        dfs(board,i,j+1,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            dfs(board,i,0,n,m);
            if(board[i][m-1]=='O')
            dfs(board,i,m-1,n,m);
        }
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
            dfs(board,0,j,n,m);
            if(board[n-1][j]=='O')
            dfs(board,n-1,j,n,m);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='Z')
                {
                    board[i][j]='O';
                }
                else if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};