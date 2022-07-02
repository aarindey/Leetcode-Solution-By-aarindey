#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    int maxArea(int hh, int w, vector<int>& h, vector<int>& v) {
        ll max_x=INT_MIN;
        ll max_y=INT_MIN;
        h.push_back(hh);
        h.push_back(0);
        v.push_back(w);
        v.push_back(0);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        
        int n=h.size();
        int m=v.size();
        for(int i=1;i<n;i++)
        {
            max_y=max(max_y,(ll)h[i]-h[i-1]);
        }
        for(int i=1;i<m;i++)
        {
            max_x=max(max_x,(ll)v[i]-v[i-1]);
        }
        if(max_x==INT_MIN||max_y==INT_MIN)
        return 0;
        return (max_x%mod*max_y%mod)%mod;
    }
};