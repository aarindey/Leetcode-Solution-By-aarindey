class Solution
{
public:
    string reverseWords(string s) 
    {
        string r="";
     s+=' ';
     int n=-1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                for(int j=i-1;j>n;j--)
                {
                    r+=s[j];
                }
                if(i!=s.length()-1)
                {
                r+=' ';
                }
                n=i;
           }
        }
        return r;
    }
};