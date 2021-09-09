class Solution {
public:
    string modifyString(string s) {
        int j=0,n=s.length();
    
     for(int i=0;i<n;i++)
     {
         if(s[i]=='?')
         {
            for(s[i]='a';s[i]<='c';s[i]++)
            {
                if((i==0||s[i]!=s[i-1])&&(i==n-1||s[i+1]!=s[i]))
                 break;   
            }
         }
     }
        return s;
    }
};