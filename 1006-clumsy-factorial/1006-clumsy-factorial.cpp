#define ll long long int
class Solution {
public:
    int clumsy(int n) {
        ll ans=0;
        bool ok=true;
        for(ll i=n;i>=1;i-=4)
        {
            ll temp;
            temp=i;
            if(i-1>0)
            temp*=(i-1);
            if(i-2>0)
            temp/=(i-2);
            if(ok)
            {
                ans+=temp;
                ok=false;
            }
            else
            {
                ans+=(-1)*(temp);
            }
            if(i-3>0)
            ans+=(i-3);
        }
        return ans;
    }
};