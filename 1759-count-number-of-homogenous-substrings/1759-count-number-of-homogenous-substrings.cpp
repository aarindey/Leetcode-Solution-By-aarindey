#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    int countHomogenous(string s) {
        int n=s.length();
        int c=1;
        ll ans=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                c++;
            }
            else
            {
                ans+=c*(1ll)*(c+1)/2;
                ans=ans%mod;
                c=1;
            }
        }
        ans+=c*(1ll)*(c+1)/2;
        ans=ans%mod;
        return ans;
    }
};