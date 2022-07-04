class Solution {
public:
    
    bool isvalid(int r,int c,int n,int m)
    {
        return r>=0&&r<n&&c>=0&&c<m;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int c=0;
        int grids=rows*cols;
        int go=1;
        bool up,left,right,down;
        left=up=down=false;
        int z=0;
        right=true;
        while(true)
        {
            if(isvalid(rStart,cStart,rows,cols))
            {
                c++;
                // cout<<c<<endl;
                // cout<<rStart<<" "<<cStart<<endl;
                ans.push_back({rStart,cStart});
            }
            if(c==grids)
            {
                
                break;
            }
            if(right&&z!=go)
            {
                cStart++;
                z++;
                if(z==go)
                {
                    right=false;
                    down=true;
                    z=0;
                }
            }
            else if(down&&z!=go)
            {
                rStart++;
                z++;
                if(z==go)
                {
                    down=false;
                    left=true;
                    go++;
                    z=0;
                }
            }
            else if(left)
            {
                cStart--;
                z++;
                if(z==go)
                {
                    left=false;
                    up=true;
                    z=0;
                }
            }
            else if(up)
            {
                rStart--;
                z++;
                if(z==go)
                {
                    up=false;
                    right=true;
                    go++;
                    z=0;
                }
            }
        }
        return ans;
    }
};