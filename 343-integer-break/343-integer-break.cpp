class Solution {
public:
    int integerBreak(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        int q,r;
        q=n/3;
        r=n%3;
        if(r==0)
        {
            return pow(3,q);
        }
        if(r==1)
        {
            return 4*pow(3,q-1);
        }
        if(r==2)
        {
            return 2*pow(3,q);
        }
        return 0;
    }
};