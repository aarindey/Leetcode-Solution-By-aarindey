class Solution {
public:
    int brokenCalc(int x, int y) {
     int c=0;
        while(y!=x)
        {
            if(x>=y)
            return c+(x-y);
            
            if(y%2==0)
            y/=2;
            else
            y++;
            
            c++;
        }
        return c;
    }
};