class Solution {
public:
    bool isValid(int new_x,int new_y,int n)
    {
        if(new_x>=0&&new_y>=0&&new_x<n&&new_y<n)
            return true;
        
        return false;
    }
    int getArea(vector<vector<int>>& grid,int i,int j,int id,int n)
    {
        if(i<0||j<0||i>=n||j>=n||grid[i][j]!=1)
        return 0;
        grid[i][j]=id;
        return 1+getArea(grid,i+1,j,id,n)+getArea(grid,i,j-1,id,n)+getArea(grid,i,j+1,id,n)+getArea(grid,i-1,j,id,n);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int gridID=2;
        unordered_map<int,int> area;
        bool ok=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    area[gridID]=getArea(grid,i,j,gridID,n);
                    gridID++;
                    ok=true;
                }
            }
        }
        if(!ok)
        return 1;
        int ans=area[2],curr=0;
        vector<vector<int>> dir(4);
        dir={{0,1},{1,0},{-1,0},{0,-1}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(grid[i][j]==0)
                {
                    set<int> st;
                    curr=1;
                    for(auto d:dir)
                    {
                        int new_x,new_y;
                        new_x=i+d[0];
                        new_y=j+d[1];
                       
                        if(isValid(new_x,new_y,n))
                        {
                            int ID=grid[new_x][new_y];
                            if(st.find(ID)==st.end())
                            {
                            curr+=area[ID];
                            st.insert(ID);
                            }
                        }
                    }
                    ans=max(ans,curr);
                }
            }
        }
        return ans;
    }
};