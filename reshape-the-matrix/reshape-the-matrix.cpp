class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
     int n=mat.size(),m=mat[0].size(),k=0;
    if(c*r!=n*m)
        return mat;
        vector<vector<int>> ans;
        vector<int> v;
     for(int i=0;i<n;i++)
        {
         for(int j=0;j<m;j++)
         {
         v.push_back(mat[i][j]);
             k++;
             if(k==c)
             {
                k=0; 
                ans.push_back(v); 
                v.clear();    
             }
        }
     }
        return ans;
    }
};