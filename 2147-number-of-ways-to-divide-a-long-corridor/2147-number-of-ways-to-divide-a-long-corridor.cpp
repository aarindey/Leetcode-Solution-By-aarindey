#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    int numberOfWays(string s) {
        int n=s.size();
        int count=0;
        for(char ch:s)
        {
            if(ch=='S')
            {
                count++;
            }
        }
        if((count&1)||count==0)
        {
            return 0;
        }
        if(count==2)
        {
            return 1;
        }
        ll mul=1,curr=0;
        ll prev=0,next=0;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(ch=='S')
            {
                curr++;
                if(curr==1)
                {
                    next=i;
                    if(prev!=0)
                    mul=(mul%mod*(next-prev)%mod)%mod;
                }
                if(curr==2)
                {
                    prev=i;
                    curr=0;
                }
            }
        }
        return mul;
    }
};
