class Solution {
public:
    string modifyString(string s) {
     string alpha="abcdefghijklmnopqrstuvwxyz";
        
        int j=0,n=s.length();
        if(n==1)
        {
            if(s[0]=='?')
             return "a";
            else
             return s;
        }   
     for(int i=0;i<n;i++)
     {
         if(s[i]=='?')
         {
             if(i==0)
             {
                 if(alpha[j]==s[i+1])
                 {
                     j++;
                 }
                 s[i]=alpha[j];
                 j=0;
             }
             else if(i==n-1)
             {
               if(alpha[j]==s[i-1])
                 {
                     j++;
                 }
                 s[i]=alpha[j];
                 j=0;  
             }
             else
             {
                 while(alpha[j]==s[i-1]||alpha[j]==s[i+1])
                 {
                     j++;
                 }
                 s[i]=alpha[j];
                 j=0;
             }
         }
     }
        return s;
    }
};