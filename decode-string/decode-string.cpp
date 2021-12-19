class Solution {
public:
    int i=0;
    string decodeString(string s) {
        int n=s.length();
         int num=0;
        string ans="";
        while(i<n)
        {
            if(s[i]>=97&&s[i]<=122)
            {
                ans+=s[i];
                i++;
            }
            else if(isdigit(s[i]))
            {
                while(isdigit(s[i]))
                {
                    num=num*10+s[i]-'0';
                    i++;
                }
            }
            else if(s[i]=='[')
            {
               i++;
               string str=decodeString(s);
               while(num--)
               ans+=str;
               i++;
               num=0;
            }
            else 
            {
                return ans;
            }
        }
        return ans;
    }
};