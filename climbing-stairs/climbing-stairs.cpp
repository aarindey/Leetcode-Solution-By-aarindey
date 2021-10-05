class Solution {
public:
    int climbStairs(int n) {
        int var[46]={0,1,2,3};
        for(int i=4;i<=n;i++)
        {
            var[i]=var[i-1]+var[i-2];
        }
        return var[n];
    }
};