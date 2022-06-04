class Solution {
public:
    int minCost(string s, vector<int>& time) {
        int n=s.size();
        int ans=0,sum=0,maxi=0;
        for(int i=0;i<n;i++)
        {
            if(i>0&&s[i]!=s[i-1])
            {
                ans+=sum-maxi;
                maxi=0;
                sum=0;
            }
            sum+=time[i];
            maxi=max(maxi,time[i]);
        }
        ans+=sum-maxi;
        return ans;
    }
};