class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long int l=1,r=2;
        long long int lcm=(a*b)/__gcd(a,b);
        long long mod=1e9+7;
        while(true){
            long long int n1=(l/a)+(l/b)-(l/lcm);
            long long int n2=(r/a)+(r/b)-(r/lcm);
            if(n<=n2){
                break; 
            }else{
                l=r;
                r=2*l;
            }
        }
        
        while(l<=r){
            long long int mid=l+(r-l)/2;
            long long int num=(mid/a)+(mid/b)-(mid/lcm);
            if(num==n && ((mid%a==0) || (mid%b==0))){
                return mid%mod;
            }   
            if(num>=n){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return -1;
        
    }
};