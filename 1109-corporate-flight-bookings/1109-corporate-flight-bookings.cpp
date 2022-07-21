class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int> ans(n,0);
        for(int i=0;i<b.size();i++)
        {
            ans[b[i][0]-1]+=b[i][2];
            if(b[i][1]<n)
            ans[b[i][1]]-=b[i][2];
        }
        for(int i=1;i<n;i++)
        {
            ans[i]+=ans[i-1];
        }
        return ans;
    }
};