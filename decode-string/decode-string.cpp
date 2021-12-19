class Solution {
public:
    string helper(string &s,int &i)
    {
        string result="";
        while(i<s.length()&&s[i]!=']')
        {
            if(isdigit(s[i]))
            {
                int num=0;
                while(i<s.length()&&isdigit(s[i]))
                {
                    num=num*10+(s[i]-'0');
                    i++;
                }
                i++;
                string str=helper(s,i);
                while(num--)
                {
                    result+=str;
                }
                i++;
            }
            else{
                result+=s[i];
                i++;
            }
        }
        return result;
    }
    string decodeString(string s) {
        int index=0;
     return helper(s,index);
    }
};