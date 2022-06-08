class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int num=1;
        queue<pair<int,int>> q;
        int n=board.size();
        for(int i=n-2;i>=0;i-=2)
        {
            reverse(board[i].begin(),board[i].end());
        }
        if(board[0][n-1]!=-1)
        return -1;
        q.push({num,0});
        int steps=0;
        vector<bool> visited(n*n+1,false);
        visited[1]=true;
        while(!q.empty())
        {
            pair<int,int> ele=q.front();
            q.pop();
            num=ele.first;
            steps=ele.second;
            for(int i=1;i<=6;i++)
            {
                int new_num=num+i;
                if(visited[new_num])
                {
                    continue;
                }
                if(new_num>n*n)
                {
                    break;
                }
                if(new_num==n*n)
                return steps+1;
                int row=new_num/n;
                if(new_num%n>0)
                row++;
                int col=new_num%n-1;
                if(new_num%n==0)
                col=n-1;
                if(board[n-row][col]==new_num)
                {    
                    continue;
                }
                if(board[n-row][col]!=-1)
                {
                    if(board[n-row][col]==n*n)
                    return steps+1;
                    visited[new_num]=true;
                    q.push({board[n-row][col],steps+1});
                    continue;
                }
                if(!visited[new_num])
                {
                    visited[new_num]=true;
                    q.push({new_num,steps+1});
                    continue;
                }
            }
        }
        return -1;
    }
};