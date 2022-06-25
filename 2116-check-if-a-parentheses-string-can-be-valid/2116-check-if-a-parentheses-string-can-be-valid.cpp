class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n&1)
        return false;
        
        // checking left to right 
        int c=0,bal=0;
        for(int i=0;i<n;i++)
        {
            if(locked[i]=='0')
            {
                c++;
            }
            else
            {
                if(s[i]=='(')
                {
                    bal++;
                }
                else
                {
                    bal--;
                    if(bal<0)
                    {
                        if(c==0)
                        return false;
                        
                        c--;
                        bal=0;
                    }
                }
            }
        }
        // checking right to left 
        c=0;
        bal=0;
        for(int i=n-1;i>=0;i--)
        {
            if(locked[i]=='0')
            {
                c++;
            }
            else
            {
                if(s[i]==')')
                {
                    bal++;
                }
                else
                {
                    bal--;
                    if(bal<0)
                    {
                        if(c==0)
                        return false;
                        
                        c--;
                        bal=0;
                    }
                }
            }
        }

        return true;
    }
};