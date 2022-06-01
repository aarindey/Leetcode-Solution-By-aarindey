class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int n=s.size();
        sort(s.begin(),s.end());
        int cumm=0,curr=0;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            curr+=cumm+s[i];
            cumm+=s[i];
            ans=max(ans,curr);
        }
        return ans;
    }
};