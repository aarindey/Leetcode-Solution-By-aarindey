class Solution {
public:
    int trailingZeroes(int n) 
    {
        int count2=0,count5=0,num;
        for(int i=2;i<=n;i++)
        {
           num=i;
           while(num%2==0)
           {
               count2++;
               num/=2;
           }
           while(num%5==0)
           {
               count5++;
               num/=5;
           } 
        }   
        return min(count2,count5);
    } 
};