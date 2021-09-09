// class Solution {
// public:
//     vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
//         int m = nums.size(), n = nums[0].size(), o = m * n;
//         if (r * c != o) return nums;
//         vector<vector<int>> res(r, vector<int>(c, 0));
//         for (int i = 0; i < o; i++) res[i / c][i % c] = nums[i / n][i % n];
//         return res;
//     }
// };
// class Solution {
// public:
//     vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
//         int m = nums.size(), n = nums[0].size();
//         if (m * n != r * c) {
//             return nums;
//         }

//         vector<vector<int>> res(r, vector<int>(c, 0));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 int k = i * n + j;
//                 res[k / c][k % c] = nums[i][j];
//             }
//         }

//         return res;
//     }
// };
class Solution{
    public:
     vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
      int n=mat.size(),m=mat[0].size();
         if(m*n!=r*c)
          return mat;
          vector<vector<int>> ans(r, vector<int>(c, 0));
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                int k=m*i+j;
                 ans[k/c][k%c]=mat[i][j];
             }
         }
         return ans;
     }
};