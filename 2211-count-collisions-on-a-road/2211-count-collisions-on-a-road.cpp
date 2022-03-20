class Solution {
public:
    int countCollisions(string dir) {
        int c=0;
        int n=dir.size();
        stack<char> s;
        for(int i=0;i<n;i++)
        {
            if(dir[i]=='L'&&!s.empty()&&s.top()=='R')
            {
                bool ff=true;
                while(!s.empty()&&s.top()=='R')
                {
                    if(ff)
                    {
                        c+=2;
                        ff=false;
                    }
                    else
                    {
                        c++;
                    }
                    s.pop();
                }
                //s.pop();
                s.push('S');
                continue;
            }
            else if(dir[i]=='S'&&!s.empty()&&s.top()=='R')
            {
                while(!s.empty()&&s.top()=='R')
                {
                        c++;
                        s.pop();
                }   
                //s.pop();
                s.push('S');
                continue;
            }
            else if(dir[i]=='L'&&!s.empty()&&s.top()=='S')
            {
                c+=1;
                //s.pop();
                s.push('S');
                continue;
            }
            s.push(dir[i]);
        }
        return c;
    }
};