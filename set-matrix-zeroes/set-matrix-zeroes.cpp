class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0||n==0)
            return;
        bool firstrow=false,firstcol=false;
        for(int i=0;i<n;i++)
        {
            if(matrix[0][i]==0)
             firstrow=true;   
        }  
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
              firstcol=true;  
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                     matrix[0][j]=0;   
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                  matrix[i][j]=0;  
            }
        }
        if(firstrow==true)
        {
            for(int i=0;i<n;i++)
            {
                matrix[0][i]=0;
            }
        }  
        if(firstcol==true)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};