class NumMatrix {
    
public:
    vector<vector<int>> prefix2d;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> pre(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                pre[i][j]=matrix[i-1][j-1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
     
                //cout<<pre[i][j]<<" ";
            }
            //cout<<endl;
        }
        prefix2d=pre;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix2d[row2+1][col2+1] - prefix2d[row2+1][col1] - prefix2d[row1][col2+1] + prefix2d[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */