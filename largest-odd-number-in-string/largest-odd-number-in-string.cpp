class Solution {
public:
    string largestOddNumber(string num) {
        int largest=0,index;
        for(int i=0;i<num.length();i++)
        {
            int n=num[i]-'0';
            if(n%2!=0)
            {
            largest=n;
            index=i;
            }
        }
        if(largest==0)
          return "";
        else
           return num.substr(0,index+1); 
    }
};