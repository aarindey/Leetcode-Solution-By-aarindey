class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
       int matrix[51][51]={0};                                      
        int c=0,r=0;
       for(int i=0;i<indices.size();i++)
       {                                   
         r=indices[i][0];
         c=indices[i][1];
           for(int j=0;j<n;j++)
            matrix[r][j]++;      
           for(int j=0;j<m;j++) 
             matrix[j][c]++;      
       }
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]%2!=0)
                count++;                    
            }
        }
        return count;
    }
};