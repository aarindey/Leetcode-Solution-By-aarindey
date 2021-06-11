class Solution {
public:
    int addDigits(int num) {
      int num1=num;
        int result=0;
            while(num1>0)
            {  
           result=result+num1%10;
           num1/=10;
             if(num1==0&&result>9)
             {
                 num1=result;
                 result=0;
             }  
            }
       
        return result;
    }
};