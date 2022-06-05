class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi=values[0];
        int n=values.size();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            ans=max((maxi+values[i]-i),ans);
            maxi=max(maxi,values[i]+i);
            //cout<<ans<<endl;
        }
        return ans;
    }
};