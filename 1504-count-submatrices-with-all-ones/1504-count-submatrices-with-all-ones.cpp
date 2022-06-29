class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> pre(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=m-1;j>=0;j--)
            {
                if(mat[i][j])
                {
                    sum++;
                }
                else
                {
                    sum=0;
                }
                pre[i][j]=sum;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=INT_MAX;
                for(int k=i;k<n;k++)
                {
                    x=min(x,pre[k][j]);
                    if(x==0)
                    break;
                    ans+=x;
                }
            }
        }
        return ans;
    }
};