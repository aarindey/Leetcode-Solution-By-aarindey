#define ll long long 
class Solution {
public:
    long long numberOfWays(string s){
        int n=s.length();
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                a++;
            }
            else
            {
                b++;
            }
        }
        ll ans=0;
        int c=0,d=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                ans+=b*c;
                d++;
                a--;
            }
            else
            {
                ans+=a*d;
                c++;
                b--;
            }
        }
        return ans;
    }
};