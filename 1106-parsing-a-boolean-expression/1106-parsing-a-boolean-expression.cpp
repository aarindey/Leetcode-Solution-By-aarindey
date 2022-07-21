class Solution {
public:
    bool parseBoolExpr(string e) {
        int n=e.size();
        stack<char> s,sign;
        for(int i=0;i<n;i++)
        {
            char ch=e[i];
            if(ch==',')
            continue;
            
            if(ch!=')')
            {
                if(ch=='!'||ch=='&'||ch=='|')
                {
                    sign.push(ch);
                }
                else
                    s.push(ch);
            }
            else
            {
                char op=sign.top();
                sign.pop();
                int hasT=-1,hasF=-1;
                while(s.top()!='(')
                {
                    if(s.top()=='t')
                    {
                        hasT=true;
                    }
                    else
                    {
                        hasF=true;
                    }
                    s.pop();
                }
                s.pop();
                if(op=='!')
                {
                    if(hasT==1)
                    {
                        s.push('f');
                    }
                    else if(hasF==1)
                    {
                        s.push('t');
                    }
                }
                else if(op=='&')
                {
                    if(hasF==1)
                    {
                        s.push('f');
                    }
                    else
                    {
                        s.push('t');
                    }
                }
                else
                {
                    if(hasT==1)
                    {
                        s.push('t');
                    }
                    else
                    {
                        s.push('f');
                    }
                }
            }
        }
        return s.top()=='t';
    }
};