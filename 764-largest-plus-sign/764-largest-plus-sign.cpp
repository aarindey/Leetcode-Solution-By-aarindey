class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
     vector<vector<int> > v(n,vector<int>(n,1));
     for(auto &it:mines)
     {
         v[it[0]][it[1]]=0;
     }
      vector<vector<int> > top,bottom,left,right;
      top=left=right=bottom=v;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               int x,y;
                x=n-1-i;
                y=n-1-j;
               if(j>0&&left[i][j])
               left[i][j]=left[i][j]+left[i][j-1];
               if(i>0&&top[i][j])
               top[i][j]+=top[i-1][j];
               if(x<n-1&&bottom[x][y])
               bottom[x][y]+=bottom[x+1][y];
               if(y<n-1&&right[x][y])
               right[x][y]+=right[x][y+1];
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,min(top[i][j],min(bottom[i][j],min(left[i][j],right[i][j]))));
            }
        }
        return ans;
    }
};