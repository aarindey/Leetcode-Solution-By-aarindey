class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
        return a[2]<b[2];   
    }
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)     {
    vector<vector<int>> ans;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            int d=abs(i-rCenter)+abs(j-cCenter);
            ans.push_back({i,j,d});
        }
    }
    sort(ans.begin(),ans.end(),comp);
        for(int i=0;i<ans.size();i++)
        {
            ans[i].erase(ans[i].begin()+2);
        }
        return ans;
    }
};