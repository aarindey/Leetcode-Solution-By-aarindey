class Solution {
public:
    int findNthDigit(int n) {
        if(n<=9)
        return n;
        long long base=9;
        long long i=1;
        while(n>base*i)
        {
            n-=base*i;
            base*=10;
            i++;
        }
        int num=pow(10,i-1)+n/i;
        int dig=n%i;
        if(dig==0)
        return (num-1)%10;
        int x=i-dig;
        while(x--)
        {
            num/=10;
        }
        return num%10;
    }
};