class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      //first transpose
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //then reverse each row
       int s,e;
        for(int i=0;i<m;i++)
        {
            s=0,e=n-1;
            while(s<e)
            {
                swap(matrix[i][s],matrix[i][e]);
                s++;
                e--;
            }
        }
    }
};