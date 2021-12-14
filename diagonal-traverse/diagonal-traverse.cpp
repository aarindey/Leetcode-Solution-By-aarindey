class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        map<int,vector<int> > mp;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        for(auto pr:mp)
        {
            if(pr.first%2==0)
            {
                vector<int> v=pr.second;
                for(int i=v.size()-1;i>=0;i--)
                {
                    ans.push_back(v[i]);
                }
            }
            else
            {
                for(auto &z:pr.second)
                {
                    ans.push_back(z);
                }
            }
        }
        return ans;
    }
};