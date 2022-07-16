#define ll long long int
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        ll l=1,r=2;
        ll lcm=(a*b)/__gcd(a,b);
        ll mod=1e9+7;
        while(true){
            ll n1=(l/a)+(l/b)-(l/lcm);
            ll n2=(r/a)+(r/b)-(r/lcm);
            if(n<=n2){
                break; 
            }else{
                l=r;
                r=2*l;
            }
        }
        ll ans;
        while(l<=r){
            ll mid=l+(r-l)/2;
            ll num=(mid/a)+(mid/b)-(mid/lcm);
            if(num==n){
                ans=mid%mod;
                r=mid-1;
            }   
            if(num>=n){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(ans!=0)
        return ans;
        return -1;
        
    }
};