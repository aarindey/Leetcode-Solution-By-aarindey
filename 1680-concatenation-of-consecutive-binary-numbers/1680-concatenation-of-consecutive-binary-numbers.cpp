#define ll long long int
ll mod=1e9+7;
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
class Solution {
public:
    int concatenatedBinary(int n) {
        ll prev=0,curr;
        for(ll i=1;i<=n;i++)
        {
            if(prev==0)
            {
                curr=1;
                prev=curr;
            }
            else
            {
                ll z=log2(i)+1;
                curr=((prev%mod*1ll*binpow(2,z)%mod)%mod+i%mod)%mod;
                prev=curr;
            }
        }
        return curr;
    }
};