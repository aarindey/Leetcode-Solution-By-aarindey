#define ll long long
class Solution {
public:
    int divide(int dividend, int divisor) {
     ll a=(ll)dividend;
     ll b=(ll)divisor;
     ll res=a/b;
        if(res>INT_MAX)
        return INT_MAX;
        if(res<INT_MIN)
        return INT_MIN;
        int z=res;
        return z;
    }
};