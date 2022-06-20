class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
     int level=0;
     set<vector<vector<int>>> st;
     queue<vector<vector<int>>> q;
     q.push(board);
     vector<int> dx={1,-1,0,0};
     vector<int> dy={0,0,1,-1};
     vector<vector<int>> target={{1,2,3},{4,5,0}};
     if(board==target)
     return 0;
     while(!q.empty())
     {
         int sz=q.size();
         while(sz--)
         {
         vector<vector<int>> t=q.front();
         q.pop();
         int x,y;
         
         for(int i=0;i<2;i++)
         {
             for(int j=0;j<3;j++)
             {
                 if(t[i][j]==0)
                 {
                     x=i;
                     y=j;
                     break;
                 }
             }
         }
         for(int i=0;i<4;i++)
         {
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            if(new_x<0||new_y<0||new_x>=2||new_y>=3)
            {
                continue;
            }
            swap(t[x][y],t[new_x][new_y]);
            if(t==target)
            {
                return level+1;
            }
            if(st.find(t)==st.end())
            {
                st.insert(t);
                q.push(t);
            }
            swap(t[x][y],t[new_x][new_y]);
         }
         }
         level++;
     }
    return -1;
    }
};