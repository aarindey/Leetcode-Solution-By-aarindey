class Solution {
public:
    bool isValid(int i,int j,int n,int m)
    {
        if(i==n||j==m||j<0||i<0)
        return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int> > ans(n,vector<int>(m,-1));
        vector<vector<int>> dis;
        dis.push_back({1,0});
        dis.push_back({0,1});
        dis.push_back({-1,0});
        dis.push_back({0,-1});
        queue<pair<int,int> > q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            pair<int,int> ele;
            ele=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=ele.first+dis[i][0];
                int y=ele.second+dis[i][1];
                if(isValid(x,y,n,m)&&ans[x][y]==-1)
                {
                    ans[x][y]=ans[ele.first][ele.second]+1;
                    q.push({x,y});
                }
            }
        }
        return ans;
    }
};