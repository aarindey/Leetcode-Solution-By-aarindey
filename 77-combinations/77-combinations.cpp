class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        for(int i=0;i<(1<<n);i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                temp.push_back(j+1);
            }
            if(temp.size()==k)
            ans.push_back(temp);
        }     
        return ans;
    }
};