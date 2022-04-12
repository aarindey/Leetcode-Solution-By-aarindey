class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
     int n=board.size();
     int m=board[0].size();
     vector<vector<int>> b(n,vector<int>(m,0));
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            int sum=0;
            if(j+1<m)   sum+=board[i][j+1];
            if(i+1<n)   sum+=board[i+1][j];
            if(j-1>=0)  sum+=board[i][j-1];
            if(i-1>=0)  sum+=board[i-1][j];
            
            if(i-1>=0 && j-1>=0) sum+=board[i-1][j-1];
            if(i-1>=0 && j+1<m) sum+=board[i-1][j+1];
            if(i+1<n && j-1>=0) sum+=board[i+1][j-1];
            if(i+1<n && j+1<m) sum+=board[i+1][j+1];
            
            if(sum==3)
            {
                b[i][j]=1;
            }
            else if(sum==2&&board[i][j])
            {
                b[i][j]=1;
            }
        }
     }
    board=b;
    }
};