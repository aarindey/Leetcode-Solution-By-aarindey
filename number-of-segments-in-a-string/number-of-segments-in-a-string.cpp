class Solution {
public:
    int countSegments(string s) {
        int c=0;
        if(s.length()==0)
           return 0; 
        int i=0;
        s+=' ';
          while(s[i]==' ')
          i++;
        for(;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                c++;
                while(s[i]==' '&&i<s.length())
                  i++;   
            }  
        }
        return c;
    }
};