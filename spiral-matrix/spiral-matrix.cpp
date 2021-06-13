class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     int m=matrix.size();
      int n=matrix[0].size();
              vector<int> ans;
        if(m==0||n==0)
           return ans; 
  int sr=0,sc=0,er=m-1,ec=n-1;
        int c=0;
        while(sr<=er&&sc<=ec)
        {
            for(int i=sc;i<=ec;i++)
            {
                ans.push_back(matrix[sr][i]);
                c++;
            }  
            sr++;
            if(c==(m*n))
                return ans;
            for(int i=sr;i<=er;i++)
            {
                ans.push_back(matrix[i][ec]);
                c++;
            } 
            ec--;
             if(c==(m*n))
                return ans;
            for(int i=ec;i>=sc;i--)
            {
                ans.push_back(matrix[er][i]);
                c++;
            } 
            er--;
             if(c==(m*n))
                return ans;
            for(int i=er;i>=sr;i--)
            {
                ans.push_back(matrix[i][sc]);
                c++;
            }
            sc++;
             if(c==(m*n))
                return ans;
        }
        return ans;
    }
};