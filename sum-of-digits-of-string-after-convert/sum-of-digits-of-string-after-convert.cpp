//1945. Sum of Digits of String After Convert
class Solution {
public:
    int getLucky(string s, int k) {
    string num="";
        for(int i=0;i<s.length();i++)
    {
        string str=to_string((int)(s[i]-'a'+1));
        num+=str;    
    }
        int n,add=0;
        for(int i=0;i<num.size();i++)
        {
            add+=num[i]-'0';
        } 
        n=add;
        for(int i=1;i<k;i++)
        {
            add=0;
            while(n>0)
            {
                add+=n%10;
                n/=10;
            } 
            n=add;
        }  
       return n; 
    }
};