class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        bool neg=false;
        if(n==INT_MIN)
        {
            x*=x;
            n=n>>1;
        }
        if(n<0)
        {
            neg=true;
            n=-n;
        }
        while(n>0)
        {
            if(n%2==0)
            {
                x*=x;
                n/=2;
            }
            else
            {
                ans=ans*x;
                n--;
            }
        }
        if(neg)
        {
            return 1.0/((double)ans);
        }
        return ans;
    }
};