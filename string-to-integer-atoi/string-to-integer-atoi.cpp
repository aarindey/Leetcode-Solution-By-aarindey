// class Solution {
// public:
//     int myAtoi(string s) {
//         long long int sum=0;
//         bool plus=true;
//         int i;
//          while (s[i] ==' '||s[i]=='0')
//             i++;
//           if(s[i]=='-')
//           {
//            plus=false;
//            i++;
//           } 
//          else if(s[i]=='+')
//          {
//              i++;
//          }  
//       if(isdigit(s[i]))
//       {
//       for(;i<s.length();i++)
//       {  
//           if(s[i]=='.')
//           break;    
//           else if(isdigit(s[i]))
//           {
//               sum=sum*10+(s[i]-'0');
//           }   
//       }
//       }   
//       if(!plus)
//       sum=-sum;
//         if(sum>=INT_MAX||sum<=INT_MIN)
//         {
//             return sum>=INT_MAX?INT_MAX:INT_MIN;
//         }   
//       return sum;  
//     }
// };
class Solution {
public:
    int myAtoi(string s) {
        long output = 0;
        int sign = 0;
        int index = 0;
        while (s[index] == ' ')
            index++;
        if (s[index] == '+' || s[index] == '-')
        {
            sign = s[index]-43;
            index++;
        }
        
        if (s[index] > 47 && s[index] < 58)
        {
            while (s[index] > 47 && s[index] < 58)
            {
                if (output > INT_MAX && !sign)
                    return INT_MAX;
                if (output > INT_MAX && sign)
                    return INT_MIN;
                output *= 10;
                output += s[index]-'0';
                index++;
            }
            if (output > INT_MAX && !sign)
                return INT_MAX;
            if (output > INT_MAX && sign)
                return INT_MIN;
            if (sign)
            {
                output = -output;
            }
            return output;
        }
        else
        {
            return 0;
        }
    }
};