//8. String to Integer (atoi)
class Solution {
public:
    int myAtoi(string s) {
        long sum=0;
        bool plus=true;
        int i;
         while (s[i] ==' ')
            i++;
          if(s[i]=='-')
          {
           plus=false;
           i++;
          } 
         else if(s[i]=='+')
         {
             i++;
         }  
      if(isdigit(s[i]))
      {
    while (s[i] > 47 && s[i] < 58)
            {
                if (sum> INT_MAX && plus)
                    return INT_MAX;
                if (sum> INT_MAX && !plus)
                    return INT_MIN;
                sum *= 10;
                sum += s[i]-'0';
                i++;
            }         
      }   
        if(!plus)
         sum=-sum;   
        if(sum>=INT_MAX||sum<=INT_MIN)
        {
            return sum>=INT_MAX?INT_MAX:INT_MIN;
        }   
      return sum;  
    }
};
