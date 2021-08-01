class Solution {
public:
    int trailingZeroes(int n) 
    {
        int count5=0,num;
        for(int i=2;i<=n;i++)
        {
           num=i;
           while(num%5==0)
           {
               count5++;
               num/=5;
           } 
        }   
        return count5;
    } 
};