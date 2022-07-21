class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int> ans(n,0);
        for(int i=0;i<b.size();i++)
        {
            int first_idx,last_idx,seats;
            first_idx=b[i][0]-1;
            last_idx=b[i][1]-1;
            seats=b[i][2];
            ans[first_idx]+=seats;
            if(last_idx+1<n)
            {
                ans[last_idx+1]-=seats;
            }
        }
        for(int i=1;i<n;i++)
        {
            ans[i]=ans[i-1]+ans[i];
        }
        return ans;
    }
};