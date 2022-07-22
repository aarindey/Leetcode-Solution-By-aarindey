class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int curr=0;
        int cumm=0;
        int n=s.size();
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            curr+=s[i]+cumm;
            cumm+=s[i];
            ans=max(ans,curr);
        }
        return ans;
    }
};