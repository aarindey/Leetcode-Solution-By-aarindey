class Solution {
public:
    int minFlipsMonoIncr(string s) {
    int ans=INT_MAX,n=s.length();
    vector<int> v(n+1,0);
    for(int i=0;i<n;i++)
    {
        v[i+1]=v[i]+(s[i]=='1'?1:0);
    }    
    for(int j=0;j<=n;j++)
    {
        ans=min(ans,v[j]+n-j-(v[n]-v[j]));
    } 
    return ans;    
    }
};