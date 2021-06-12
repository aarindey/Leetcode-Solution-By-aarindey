class Solution {
public:
    bool isHappy(int n){
      int num,c=0;
        while(n!=1)
      {
            num=0;
            c++;
          while(n>0)
          {
              num+=(n%10)*(n%10);
              n=n/10;
          }
            n=num;
            if(c==40)
              return false;  
      }
        return true;
    }
};