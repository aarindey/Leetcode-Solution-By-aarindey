class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int idx=0;
        for(int i=m-1;i>=0;i--)
        {
            int j=i,k=0;
            vector<int> temp;
            while(j<m&&k<n)
            {
                temp.push_back(mat[k][j]);
                k++;
                j++;
            }
            sort(temp.begin(),temp.end());
            j=i;
            k=0;
            idx=0;
            while(j<m&&k<n)
            {
                mat[k][j]=temp[idx++];
                k++;
                j++;
            }
        }
        for(int i=1;i<n;i++)
        {
            int j=0;
            int k=i;
            vector<int> temp;
            while(k<n&&j<m)
            {
                temp.push_back(mat[k][j]);
                k++;
                j++;
            }
            sort(temp.begin(),temp.end());
            k=i;
            j=0;
            idx=0;
            while(k<n&&j<m)
            {
                mat[k][j]=temp[idx++];
                k++;
                j++;
            }
        }
        return mat;
    }
};