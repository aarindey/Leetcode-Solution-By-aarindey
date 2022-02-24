class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int m=colsum.size();
        vector<vector<int> > ans(2,vector<int>(m));
        int total=accumulate(colsum.begin(),colsum.end(),0);
        if(total!=upper+lower)
        {
            return {};
        }
    
            for(int j=0;j<m;j++)
            {
                if(colsum[j]==2)
                {
                    ans[0][j]=1;
                    ans[1][j]=1;
                    upper--;
                    lower--;
                }
                else if(colsum[j]==1)
                {
                    if(upper>lower)
                    {
                      ans[0][j]=1;
                      upper--;
                    }
                    else
                    {
                        ans[1][j]=1;
                        lower--;
                    }
                }    
            }
        if(upper!=0||lower!=0)
        return {};
        return ans;
    }
};