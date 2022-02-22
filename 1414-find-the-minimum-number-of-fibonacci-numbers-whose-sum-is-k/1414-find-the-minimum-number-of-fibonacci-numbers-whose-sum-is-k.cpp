class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib;
        fib.push_back(1);
        fib.push_back(1);
        for(int i=2;;i++)
        {
            if(fib[i-1]+fib[i-2]>k)
            break;
            fib.push_back(fib[i-1]+fib[i-2]);
        }
        int n=fib.size()-1;
        int c=0;
        while(true)
        {
            int x=fib[n];
            c+=k/x;
            k%=x;
            if(k==0)
                break;
            n--;
        }
        return c;
    }
};