class Solution {
public:
    bool dfs(vector<vector<char>> &board,string word,int k,int r,int c,vector<vector<bool>> &visited)
    {
        if(k==word.length())
        return true;
        if(r<0||c<0||r>=board.size()||c>=board[0].size()||visited[r][c]==true)
        return false;
        if(word[k]!=board[r][c])
        return false;
        visited[r][c]=true;
            if(dfs(board,word,k+1,r+1,c,visited)||dfs(board,word,k+1,r-1,c,visited)||dfs(board,word,k+1,r,c+1,visited)||dfs(board,word,k+1,r,c-1,visited)){
            return true;
            }
        visited[r][c]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
     for(int i=0;i<board.size();i++)
     {
         for(int j=0;j<board[0].size();j++)
         {
             if(board[i][j]==word[0])
             {
                 vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
                 if(dfs(board,word,0,i,j,visited))
                 return true;
             }
         }
     }
    return false;
    }
};