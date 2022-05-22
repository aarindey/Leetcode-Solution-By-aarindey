class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int n=ob.size();
        int m=ob[0].size();
        if(ob[0][0]==1)
        return 0;
        ob[0][0]=1;
        for(int i=1;i<n;i++)
        {
            if(ob[i][0]==1)
            ob[i][0]=0;
            else
            {
                ob[i][0]=ob[i-1][0];
            }
        }
        for(int i=1;i<m;i++)
        {
            if(ob[0][i]==1)
            ob[0][i]=0;
            else
            {
                ob[0][i]=ob[0][i-1];
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(ob[i][j]==1)
                ob[i][j]=0;
                else
                ob[i][j]=ob[i-1][j]+ob[i][j-1];
            }
        }
        return ob[n-1][m-1];
    }
};