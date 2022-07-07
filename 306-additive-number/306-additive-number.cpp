#define ll long long int
class Solution {
public:
    bool backtrack(string &s,int i,int n,vector<ll> &seq)
    {
        if(i==n)
        {
            if(seq.size()>2)
            return true;
            
            return false;
        }
        ll num=0;
        for(int j=i;j<n;j++)
        {
            if(num>=LLONG_MAX/10)
            return false;
            num=10*(1ll)*num+(1ll)*(s[j]-'0');
            ll z=seq.size();
            if(seq.size()<2||num==(ll)seq[z-1]+seq[z-2])
            {
                seq.push_back(num);
                if(backtrack(s,j+1,n,seq))
                {
                    return true;
                }
                seq.pop_back();
            }
            if(j==i&&s[i]=='0')
            return false;
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        vector<ll> seq;
        return backtrack(num,0,num.size(),seq);
    }
};