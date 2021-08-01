class Solution {
public:
    bool isUgly(int n) {
        int prev=n;
        if(n==1)
         return true; 
        if(n<0||n==0)
           return false; 
       while(n!=1)
       {
           prev=n;
           if(n%2==0)
           {
            n=n/2;   
           }
           if(n%3==0)
           {
               n=n/3;
           }
           if(n%5==0)
           {
               n=n/5;
           }
           if(prev==n)
             return false;  
       } 
        return true;
    }
};