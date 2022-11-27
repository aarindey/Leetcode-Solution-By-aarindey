#define ll long long int
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        ll n=s.length();
        vector<vector<ll>> mpp(n,vector<ll>(26,0)),mpp2(n,vector<ll>(26,0));
        // ll n=s.length();
        set<ll> st;
        for(ll i=0;i<n;i++)
        {
            ll d=s[i]-'a';
            for(ll j=0;j<26;j++)
            {
                if(d==j)
                {
                    if(i>=1)
                    mpp[i][j]=mpp[i-1][j]+1;
                    else
                    mpp[i][j]=1;
                }
                else
                {
                    if(i>=1)
                    mpp[i][j]=mpp[i-1][j];
                    else
                    mpp[i][j]=0;
                }
            }
        }
        for(ll i=n-1;i>=0;i--)
        {
            ll d=s[i]-'a';
            for(ll j=0;j<26;j++)
            {
                if(d==j)
                {
                    if(i<n-1)
                    mpp2[i][j]=mpp2[i+1][j]+1;
                    else
                    mpp2[i][j]=1;
                }
                else
                {
                    if(i<n-1)
                    mpp2[i][j]=mpp2[i+1][j];
                    else
                    mpp2[i][j]=0;
                }
            }
        }
        
        // for(ll i=0;i<n;i++)
        // {
        //     for(ll j=0;j<26;j++)
        //     {
        //         cout<<mpp2[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // ll ans=0;
        
        for(ll i=1;i<n-1;i++)
        {
            for(ll j=0;j<26;j++)
            {
                if(mpp[i-1][j]>0&&mpp2[i+1][j]>0)
                {
                    ll num=j*1000+(s[i]-97);
                    st.insert(num);
                }
            }
        }
        return st.size();
    }
};