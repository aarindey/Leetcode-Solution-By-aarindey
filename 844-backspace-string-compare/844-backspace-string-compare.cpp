class Solution {
public:
    bool backspaceCompare(string s, string t) {
     stack<char> a;
     stack<char> b;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='#')
            {
                if(a.empty())
                    continue;
                else
                a.pop();
            }
                else
                a.push(s[i]);
        }
        for(int i=0;i<t.length();i++)
        {
            if(t[i]=='#')
            {
           if(b.empty())
           continue;
                else
                    b.pop();
            }
                else
                b.push(t[i]);
        }
        string s1="";
        string s2="";
        while(!a.empty())
        {
            s1+=a.top();
            a.pop();
        }
         while(!b.empty())
        {
            s2+=b.top();
            b.pop();
        }
        if(s1==s2)
            return true;
        else
            return false;
    }
};