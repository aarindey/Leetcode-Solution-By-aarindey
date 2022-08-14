#define ll long long int
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        vector<ll> dp(10);
        ll g=n;
        for(int i=1;i<=9;i++)
        {
            int z=9;
            if(i==1)
            {
                dp[i]=9;
            }
            else 
            {
                ll k=i;
                --k;
                dp[i]=9;
                while(k--)
                {
                    dp[i]*=(z);
                    z--;
                }
            }
        }
        ll z=log10(n)+1;
 
        ll ans=0;
        
        for(ll i=1;i<=z-1;i++)
        {
            ans+=dp[i];
        }
        vector<ll> digit;
        while(n)
        {
            digit.push_back(n%10);
            n/=10;
        }
        reverse(digit.begin(),digit.end());
        set<ll> st;
        bool ok=true;
        int j;
        for(ll i=0;i<z-1;i++)
        {
            ll k=digit[i]-1;
            if(k==0&&i==0)
            {
                st.insert(1);
                continue;
            }
            ll zz=1;

            ll mul=0;
            for(ll m=0;m<=k;m++)
            {
                if(st.find(m)==st.end())
                mul++;
            }
            if(i==0)
            {
                mul--;
            }
            ll c=10-i-1;

            for(ll j=i+1;j<z;j++)
            {
                zz*=c;
                c--;
            }
            zz*=mul;
            ans+=zz;
            if(st.find(digit[i])!=st.end())
            {
                ok=false;
                j=i;
                break;
            }
            st.insert(digit[i]);
        }
        if(ok)
        {
            ll f=digit[z-1];
            ll c=0;
            for(ll i=0;i<=f;i++)
            {
                if(st.find(i)==st.end())
                c++;
            }
            ans+=c;
            
            if(z==1)
            { 
                ans--;
            }
        }
        return g-ans;   
    }
};