class Solution {
public:
    int func(int i,int j,int k,vector<vector<int>> &mat)
    {
        int sum=0;
        int n,m;
        n=mat.size();
        m=mat[0].size();
        for(int p=i-k;p<=i+k;p++)
        {
            for(int q=j-k;q<=j+k;q++)
            {
                if(p>=0&&p<n&&q>=0&&q<m)
                {
                    sum+=mat[p][q];
                }
            }
        }
        return sum;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans;
        ans=mat;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum=func(i,j,k,mat);
                ans[i][j]=sum;
            }
        }
        return ans;
    }
};