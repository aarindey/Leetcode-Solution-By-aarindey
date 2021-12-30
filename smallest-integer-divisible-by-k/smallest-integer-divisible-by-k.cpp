class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0||k%5==0)
        return -1;
        long long int n=0;
        int len=0;
        while(true)
        {
            n=(n*10+1)%k;
            len++;
            if(n==0)
            {
                return len;
            }
            if(len>k)
            return -1;
        }
        return -1;
    }
};