class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int j=mat.size()-1;
        for(int i=0;i<mat.size();i++)
        {
            sum+=mat[i][i]+mat[i][j];
            j--;
        }
       int mid=(mat.size()-1)/2;
        if(mat.size()%2!=0)
        return sum-mat[mid][mid];
        else
         return sum;   
    }
};