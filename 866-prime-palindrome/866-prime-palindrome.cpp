#define ll long long int
class Solution {
public:
bool ispalin(int n)
{
    int n1=n;
    int n2=0;
    while(n1>0){
        int a=n1%10;
        n2=n2*10+a;
        n1/=10;
    }
    if(n2==n)
        return true;
    return false;
}
    bool sieve(int n)
    {
        if(n==1)
        return false;
        for(ll i=2;i*i<=n;i++)
        {
            if(n%i==0)
            return false;
        }
        return true;
    }
    int primePalindrome(int n) {
        if (99899*1e2 <= n && n <= 1e8)
        return 100030001;
        for(int j=n;j<1e8;j++)
        {
           if(sieve(j))
          {
               if(ispalin(j))
               {
                    return j;
               }
           }
        }
        return 0;
    }
};