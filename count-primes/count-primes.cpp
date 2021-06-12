class Solution {
public:
    int countPrimes(int n) {
          if (n <= 2) {
            return 0;
        }
        bool prime[n+50];
            memset(prime, false, sizeof(prime));
        for(int i=2;i*i<n;i++)
        {
            if(prime[i]==false)
            {
                for(int j=i*i;j<n;j+=i)
                {
                    prime[j]=true;
                }
            }
        }
        int c=0;
        for(int j=2;j<n;j++)
        {
            if(prime[j]==false)
             c++;   
        }
        return c;
    }
};