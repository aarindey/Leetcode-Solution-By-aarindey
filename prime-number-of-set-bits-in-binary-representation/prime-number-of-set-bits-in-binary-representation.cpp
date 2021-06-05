class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int num;
        int count,c=0;
         while(left<(right+1))         
        {
            count=0;
            num=left;
            while(num)
            {
                count++;
                num=num&(num-1);
            }  
            if(prime(count))
            c++;
             left++;
        }  
        return c;
    }
bool prime(int num)
{
    int c=0;
    for(int i=num;i>=1;i--)
    {
        if(num%i==0)
         c++;   
    }  
    return c==2;
} 
};