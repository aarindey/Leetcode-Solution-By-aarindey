class Solution {
public:
    bool isValid(int row,int col,vector<vector<char>>& board,char c)
    {
        int count=0;
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c)
                count++;
            if(board[i][col]==c)
                count++;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                count++;
        }
        return count==3;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]!='.')
                {
                    if(!isValid(i,j,board,board[i][j]))
                     return false;   
                }
            }
        }
        return true;
    }
};