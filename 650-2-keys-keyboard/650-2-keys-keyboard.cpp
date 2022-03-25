class Solution {
public:
    int minSteps(int n) {
        if(n==1)
        return 0;
        int x=n;
        while(x--)
        {
            if(n%x==0)
            return minSteps(x)+n/x;
        }
        return n;
    }
};