#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    int numSub(string s) {
        int n=s.length();
        int c=1;
        ll ans=0;
        int cnt=0;
        for(char ch:s)
        {
            cnt+=(ch-'0');
        }
        if(cnt==0)
        return 0;
        s+='0';
        for(int i=1;i<n+1;i++)
        {
            if(s[i]==s[i-1]&&s[i]=='1')
            {
                c++;
            }
            else if(s[i]=='0'&&s[i-1]=='1')
            {
                ans+=c*(1ll)*(c+1)/2;
                ans=ans%mod;
                c=1;
            }
            
        }
        ans=ans%mod;
        return ans;
    }
};