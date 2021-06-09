class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> v;
        ans.push_back({1});
        for(int i=2;i<=numRows;i++)
        {
           v.clear();
                v.push_back(1);
                for(int j=0;j<i-2;j++)
                {
                    v.push_back(ans[i-2][j]+ans[i-2][j+1]);
                }   
                v.push_back(1);
            ans.push_back(v);
            }
    
                
        return ans;
    }
};