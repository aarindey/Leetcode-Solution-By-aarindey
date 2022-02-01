class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(p==q)
        return 1;
        if(p==2*q)
        return 2;
        if(q==0)
        return 0;
        while(p%2==0&&q%2==0)
        {
            p/=2;
            q/=2;
        }
        if(p%2==0)
        return 2;
        else if(q%2==0)
        return 0;
        
        return 1;
        
    }
};