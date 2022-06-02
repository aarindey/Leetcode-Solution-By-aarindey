class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> vec;
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int> v;
        for(int i=0;i<c;i++)
        {
            v.clear();
            for(int j=0;j<r;j++)
            {
               v.push_back(matrix[j][i]); 
            }   
            vec.push_back(v);
        }
        return vec;
    }
};